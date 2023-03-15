#include<header.hpp>

char CHOICE;
char reason[20];
int sfd = -1;

//struct node * node_db = NULL; im pretty certain you are setting a pointer to null here?

struct Node db_node; // globally defined struct, represents the node.
struct MessageHeader message_header;

// sends packet information to other nodes
fsm sender(struct msg* message) {
	address packet;

	state sending:
		packet = tcv_wnp(sending, sfd, sizeof(struct msg)+4);
		packet[0] = NETWORK_ID;

		tcv_endp(packet);
	
	state CONFIRM_message:
		// Display message was sent
		ser_out(CONFIRM_message, "Message sent\r\n");
		// Exit out of fsm
		finish;
}

// receives packet information from wireless connected nodes
fsm receiver(struct Node* db_node) {
	
	address incoming_packet;

	state receiving:
		// Get the next packet queued for input at the session (sfd)
		incoming_packet = tcv_rnp(receiving, sfd);
	state ok:
		
		//struct MessageHeader* message_header;
		struct Message* message;
		int bytes_read = tcv_read(incoming_packet+1, message, 6);
		//struct MessageHeader* message_header = (struct MessageHeader*)(incoming_packet+1);

		/* Grab and store the header components */
		uint16_t received_gid 		 = message->gid;
		uint8_t received_type 		 = message->type;
		uint8_t received_req_num 	 = message->req_num;
		uint8_t received_sender_id 	 = message->sender_id;
		uint8_t received_receiver_id = message->receiver_id;

		/*DEBUGGING PURPOSES*/
		DEBUG_PRINT("RECEIVED GID: %d\n", received_gid);
		DEBUG_PRINT("RECEIVED TYPE: %d\n", received_type);
		DEBUG_PRINT("RECEIVED REQ NUM: %d\n", received_req_num);
		DEBUG_PRINT("RECEIVED SID: %d\n", received_sender_id);
		DEBUG_PRINT("RECEIVED RID: %d\n", received_receiver_id);

		if (received_type < 0 || received_type > 5) {
			DEBUG_PRINT("ERROR: received type [%d] is not legal packet type", received_type);
			proceed error;
		} else if (received_receiver_id != db_node->id) {
			DEBUG_PRINT("ERROR: received type [%d] is not legal packet type", received_type);
			proceed error;
		} else if (received_sender_id > 25 || received_sender_id < 0) {
			DEBUG_PRINT("ERROR: sender_id [%d] is not within the valid id range", received_sender_id);
			proceed error;
		} else{

			switch(received_type) {
				// Discovery Request
				case 0:

					/*
					Our node has received a discovery request, we need to send back to the sending node
					a discovery response. The discovery response message includes the following fields.
					
					o Group ID [2 bytes]: The sender node group ID
					o Type [1 byte]: Always set to ONE
					o Request Number [1 byte]: This field should be equal to the request number received in the corresponding Discovery request message
					o Sender ID [1 byte]: The originator node ID for this message
					o Receiver ID [1 byte]: The ID of the node that originally sent the Discovery Request
					
					Because this is one of the scenarios where the packets are the same we can send back the packet with any required modifications
					*/
					message->gid         = node_db->gid;			// return this nodes gid in the message gid
					message->type        = (uint8_t) 1; 			// change the type to 1 for discovery response.
					message->req_num     = received_req_num;	
					message->sender_id   = node_db->id;	    		// change the sender_id to this nodes id.
					message->receiver_id = received_sender_id;		// the ID of the requester

					// perform sending operation
					
					break;
				// Discovery Response
				case 1:
					break;
				// Create Record Message
				case 2:
					break;
				// Delete Record Message
				case 3:
					break;
				// Retrieve Record Message
				case 4:
					break;
				// Response Message
				case 5:
					break;
				default:
					break;
				}

		}
		
		tcv_endp(incoming_packet);

		proceed receiving;

	state error:
		DEBUG_PRINT("ERROR: someting went wrong when receiving the packet");
		// handle error
}

fsm root {
	struct Message* message;

	state initialize_node:
		// cast node_db to struct node * and malloc to it the size of a struct node 
		node_db = (struct Node *)umalloc(sizeof(struct Node));

		message = (struct Message *message)umalloc(sizeof(struct Message));

		// cast message_header to struct MessageHeader * and malloc to it the size of a MessageHeader struct
		message_header = (struct MessageHeader *)umalloc(sizeof(struct MessageHeader));

		// initial values of payload

		phys_cc1350(0, MAX_PKT_LEN);
		/* 	void tcv_plug (int id, tcvplug_t *plugin)

			"The first argument is the numerical plugin identifier whose purpose is to uniquely identify
			all plugins configured by the praxis, e.g., for reference with tcv_open. The second
			argument points to a data structure describing the plugin."

			NOTE: the semantics of openeing a session rely on the plugin. Here we have have the simplest
				  plugin type defined (the null plug). The configuraiton of tcv_open rely on this plugin as well. 
				  the null plugin offers only a single session per physical interface. This session is explicitly 
				  setup (opened) through tcv_open().

			See docs section 3 pg11/20 for the struct of this plugin
		*/
		tcv_plug (0, &plug_null);

		/* int tcv_open (word state, int phid, int plid, ...)

		   The tcv_open calling process can be blocked, and thus the first argument is the state to return to
		   ro re-try the operation. Passing the state argument of WNONE states the process is never blocked
		   but returns its status. If the returned value is -2, then it is blocked.

		   The other two fixed parameters for which we are passing 0 and 0 represent the physical module and the plugin
		   that will be responsible for handling the session. Above we set the plugin identifier to 0 in tcv_plug().

		   tcv_open will return returns an int defining the session (it resembles a unix file descriptor hence
		   the abbreviation "sfd"). A return of -1 means an Error has occured.

		   NOTE: the maxmium number of sessions that can be open at any time is default 8. We can redfine this in
		   options.h by setting TCV_MAX_DESC to something higher.
		*/
		sfd = tcv_open (WNONE, 0, 0);

		if (sfd < 0) {
			diag("Cannot open tcv interface");
			halt();
		};

		/* int tcv_control (int fd, int option, address value)

		  This function is referenced only twice in the docs. To my understainding, it determines if the
		  sfd is interpreted as a plugin id or a physical module. 
		
		*/
		tcv_control(sfd, PHYSOPT_ON, NULL);

		runfsm receiver(db_node);

	state menu:
		ser_outf(menu, "\r\nGroup %d Device #%d (%d/%d records)\r\n(G)roup ID\r\n(N)ew device ID\r\n(F)ind neighbors\r\n(C)reate record on neighbor\r\n(D)elete record on neighbor\r\n(R)etrieve record from neighbor\r\n(S)how local records\r\nR(e)set local storage\r\n\r\nSelection: ", node_group_id, node_id, num_of_rec, max_num_rec);

	state get_choice:
		ser_inf(get_choice, "%c", &CHOICE);
		switch(CHOICE) {
			case 'g':
			case 'G':
				proceed get_new_group_id;
				break;
			case 'n':
			case 'N':
				proceed get_new_node_id;
				break;
			case 'f':
			case 'F':
				proceed find_proto;
				break;
			case 'c':
			case 'C':
				proceed create_proto;
				break;
			case 'd':
			case 'D':
				proceed delete_proto;
				break;
			case 'r':
			case 'R':
				proceed retrieve_proto;
				break;
			case 's':
			case 'S':
				proceed display_db;
				break;
			case 'e':
			case 'E':
				proceed del_local;
				break;
			default:
				proceed menu;
				break;
		}

	state get_new_group_id:
		ser_out(get_new_group_id, "Please provide a new group ID#: ");

	state new_group_id:
		ser_inf(new_group_id, "%d", NODE_GROUP_ID_VAR);
		proceed menu;

	state get_new_node_id:
		ser_out(get_new_node_id, "\r\nPlease provide a new node ID# (1-25 inclusive): ");

	state new_node_id:
		ser_inf(new_node_id, "%d", NODE_ID_VAR);
		/*HERE WE WILL HAVE TO CHECK TO ENSURE THAT THIS ID NUMBER
		IS UNIQUE FOR THE NODE GROUP AS WELL AS THE BELOW
		if(NODE_ID_VAR in database){
			reason = "ID is in use";
			proceed invalid_node_id;
		}*/
		if(NODE_ID_VAR < 1 || NODE_ID_VAR > 25){
			reason = "Out of Range";
			proceed invalid_node_id;
		}

	state invalid_node_id:
		ser_outf(invalid_node_id, "\r\nID#: %d, is an invalid choice. Reason: %s.", NODE_ID_VAR, reason);
		proceed get_new_node_id;

	state find_proto:

	state display_neighboring_array:
		ser_out(display_neighboring_array, "\r\n Neighbors: ");
		for (int i=0; i<NNODE_GROUP_SIZE; i++) {
			if (payload->nnodes[i] == 0) {
				break;
			} else {
				ser_outf(display_neighboring_array, "%d ", payload->nnodes[i]);
			}
		}
		ser_out(display_neighboring_array, "\r\n");

	state create_proto:

	state delete_proto:

	state retrieve_proto:

	state display_db:

	state del_local:

}