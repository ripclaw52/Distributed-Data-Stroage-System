#include<header.hpp>

char CHOICE;
char reason[50];
int sfd = -1;

// Stores the random request numner and the type of message send
int response_checker[2];

word response_flag=0;

struct Node *node_db; // globally defined struct, represents the node.


struct ResponseMessage *assemble_response_message(uint16_t gid, uint8_t request_number, uint8_t sender_id, uint8_t receiver_id, uint8_t status, uint8_t padding, char rec[20]){
	struct ResponseMessage *response_message;

	response_message->gid = gid;
	response_message->tpe = RESPONSE;
	response_message->request_number = request_number;
	response_message->sender_id = sender_id;
	response_message->receiver_id = receiver_id;
	response_message->status = status;
	if (!padding){
		response_message->padding = padding;
	};
	if (rec != NULL){
		strncpy(response_message->record, rec, 20);
	};

	return response_message;

};

// Gets the message size
int get_message_size(struct ResponseMessage *message) {
	int packet_size;
	/*
	 * Calculate needed size of sending packet
	 */
	switch(message->tpe) {
		// Discovery Request
		case DISCOVERY_REQUEST: packet_size = sizeof(struct DiscoveryRequestMessage); break;

		// Discovery Response
		case DISCOVERY_RESPONSE: packet_size = sizeof(struct DiscoveryResponseMessage); break;
		
		// Create Record
		case CREATE_RECORD: packet_size = sizeof(struct CreateRecordMessage); break;
		
		// Delete Record
		case DELETE_RECORD: packet_size = sizeof(struct DeleteRecordMessage); break;

		// Retrieve Record
		case RETRIEVE_RECORD: packet_size = sizeof(struct RetrieveRecordMessage); break;
		
		// Response
		case RESPONSE: packet_size = sizeof(struct ResponseMessage); break;

		// Type is not valid. exit from loop
		default:
			packet_size = 0;
			// EXIT SENDER FSM
			break;
	}
	return packet_size;
}

// sends packet information to other nodes
fsm sender(struct ResponseMessage *message) {
	address packet;

	int packet_size = sizeof(struct ResponseMessage); //get_message_size(message);

	state sending:
		packet = tcv_wnp(sending, sfd, 4 + packet_size); //NOTE: PUT SIZE OF MESSAGE + 4
		packet[0] = NETWORK_ID;
		char * p = (char *)(packet+1);
		// Base packet information
		*p = message->gid;p++;
		*p = message->tpe;p++;
		*p = message->request_number;p++;
		*p = message->sender_id;p++;
		*p = message->receiver_id;p++;
		// Specific packet information based on message type
		switch(message->tpe) {
			// Create Record
			case CREATE_RECORD:
				// format packet for create record message
				// the sizeof may not work depending on how we are defining record, we will see when we test
				strncpy(p, message->record, sizeof(message->record));
				break;

			// Delete Record & Retrieve Record
			case DELETE_RECORD:
			case RETRIEVE_RECORD:
				// format packet for delete or retrieve record message
				*p = message->record_index;p++;
				*p = message->padding;
				break;

			// Response 
			case RESPONSE:
				// format packet for response message
				*p = message->status;p++;
				*p = message->padding;p++;
				
				strncpy(p, message->record, sizeof(message->record));
				break;

			// Type is not response or create/delete/retrieve records
			default:
				// Packet is a discovery request/response
				break;
		}

		tcv_endp(packet);
	
	state CONFIRM_message:
		// Display message was sent
		ser_out(CONFIRM_message, "Message sent\r\n");
		// Exit out of fsm
		finish;
}

// receives packet information from wireless connected nodes
fsm receiver(struct Node* node_db) {
	struct ResponseMessage* response_message_5;
	
	address incoming_packet;
	char array[20];

	state receiving:
		// Get the next packet queued for input at the session (sfd)
		incoming_packet = tcv_rnp(receiving, sfd);
	state ok:
		
		uint8_t tpe;
		uint8_t bytes_read = tcv_read(incoming_packet+3, &tpe, 1); // NOTE: might still be broked'd

		if (bytes_read != 1){
			//proceed error; //NOTE: NO ERROR STATE
		};
		// in each switch case where we send a response using call (), we may be able to remove the return state...
		switch (tpe){
			
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
			case DISCOVERY_REQUEST: ;
				// respondng with this
				struct DiscoveryResponseMessage *response_message_0;
				// receiving this
				struct DiscoveryRequestMessage *discovery_request_message = (struct DiscoveryRequestMessage*)(incoming_packet+1);

				/*DEBUGGING*/
				DEBUG_PRINT("RECEIVED GID: %d\n", discovery_request_message->gid);
				DEBUG_PRINT("RECEIVED TYPE: %d\n", discovery_request_message->tpe);
				DEBUG_PRINT("RECEIVED REQ NUM: %d\n", discovery_request_message->request_number);
				DEBUG_PRINT("RECEIVED SID: %d\n", discovery_request_message->sender_id);
				DEBUG_PRINT("RECEIVED RID: %d\n", discovery_request_message->receiver_id);

				// if the group_ids match
				if (discovery_request_message->gid == node_db->gid){
					response_message_0->gid = discovery_request_message->gid;
					response_message_0->tpe = DISCOVERY_RESPONSE;
					response_message_0->request_number = discovery_request_message->request_number;
					response_message_0->sender_id = node_db->id;
					response_message_0->receiver_id = discovery_request_message->sender_id;
					// NOTE: return_from_sender might be optional, in which case it should just return to here and then break
					call sender(response_message_0, done_case);
				} 

				break;
			
			/*
			Our node has received a discovery response message, meaning it has sent a discovry request.

			We need to populate the node neighbour array with the appropriate values. I beleive we want it
			to be filled with the node_ids of those who have the same group id.

			Based on the specifications, there is no response when this kind of message is received.
			*/
			case DISCOVERY_RESPONSE: ;
				// receiving this, no response.
				struct DiscoveryResponseMessage* response_message_1 = (struct DiscoveryResponseMessage*)(incoming_packet+1);

				/*DEBUGGING*/
				DEBUG_PRINT("RECEIVED GID: %d\n", response_message_1->gid);
				DEBUG_PRINT("RECEIVED TYPE: %d\n", response_message_1->tpe);
				DEBUG_PRINT("RECEIVED REQ NUM: %d\n", response_message_1->request_number);
				DEBUG_PRINT("RECEIVED SID: %d\n", response_message_1->sender_id);
				DEBUG_PRINT("RECEIVED RID: %d\n", response_message_1->receiver_id);

				node_db->nnodes[node_db->index] = node_db->gid == response_message_1->gid && response_message_1->sender_id < NNODE_GROUP_SIZE && response_message_1->sender_id > 0 ? response_message_1->sender_id : node_db->nnodes[node_db->index];
				
				//node_db->index = node_db->nnodes[node_db->index] == discovery_response_message->sender_id ? node_db->index+1 : node_db->index;
				// increment the index if the insertion succeeded.
				if (node_db->nnodes[node_db->index] == response_message_1->sender_id){
					node_db->index+=1;
				};
				
				break;
			/*
			Our node has received a create record message. This means the sender node wishes to create and store
			a record in our node (the receiver).
			*/
			case CREATE_RECORD: ;
				struct ResponseMessage *response_message_2;
				struct CreateRecordMessage* create_record_message = (struct CreateRecordMessage*)(incoming_packet+1);
				bool neighbour_check = false;
				uint8_t status;

				/*DEBUGGING*/
				DEBUG_PRINT("RECEIVED GID: %d\n", create_record_message->gid);
				DEBUG_PRINT("RECEIVED TYPE: %d\n", create_record_message->tpe);
				DEBUG_PRINT("RECEIVED REQ NUM: %d\n", create_record_message->request_number);
				DEBUG_PRINT("RECEIVED SID: %d\n", create_record_message->sender_id);
				DEBUG_PRINT("RECEIVED RID: %d\n", create_record_message->receiver_id);
				DEBUG_PRINT("RECEIVED RECORD: %s\n", create_record_message->record);

				// if the message is not for this node, it is ignored.
				if (create_record_message->receiver_id != node_db->id || create_record_message->gid != node_db->id){
					break;
				};

				// check the record size, attempt to insert it...if the user send something invalid, we will just ignore this message and break
				if (sizeof(create_record_message->record) <= MAX_DB_ENT_LEN && sizeof(create_record_message->record) > 0) {
					// pointer to node, the record to be inserted, the owner of the record (the sender)
					if (insert_record(node_db, create_record_message->record, create_record_message->sender_id)){
						status = (uint8_t) SUCCESS;
					} else{
						status = (uint8_t) DB_FULL;
					};

					response_message_2 = assemble_response_message(node_db->gid, create_record_message->request_number, node_db->id, create_record_message->receiver_id, status, 0, array);
					call sender(response_message_2, done_case);

				};
				
				break;

			case DELETE_RECORD: ;
				struct ResponseMessage *response_message_3;
				struct DeleteRecordMessage *delete_record_message = (struct DeleteRecordMessage*)(incoming_packet+1);

				// if the message is not intended for this node, ignore it.
				if (delete_record_message->gid != node_db->gid || delete_record_message->receiver_id != node_db->id){
					break;
				};

				// if a valid index is provided
				if (delete_record_message->record_index >=0 && delete_record_message->record_index <= 40){
					
					// attempt to delete the record at the provided, valid, index.
					if (delete_record(node_db, delete_record_message->record_index)){
						status = (uint8_t) SUCCESS;
					} else{
						status = (uint8_t) DELETE_ERROR;
					};

					response_message_3 = assemble_response_message(node_db->gid, delete_record_message->request_number, node_db->id, delete_record_message->receiver_id, status, 0, array);
					call sender(response_message_3, done_case);

				};

				break;

			// NOTE: this case will likely still require work
			case RETRIEVE_RECORD: ;
				struct ResponseMessage *response_message_4;
				struct RetrieveRecordMessage *retreive_record_message = (struct RetrieveRecordMessage*)(incoming_packet+1);
				struct record retrieved_record;

				// if the message is not intended for this node, ignore it.
				if (delete_record_message->gid != node_db->gid || delete_record_message->receiver_id != node_db->id){
					break;
				};

				// validate index
				if (retreive_record_message->record_index >=0 && retreive_record_message->record_index <= 40){
					retrieved_record = retrieve_record(node_db, retreive_record_message->record_index);
					if (retrieved_record.data_entry == NULL){
						status = (uint8_t) RETRIEVE_ERROR;
						response_message_4 = assemble_response_message(node_db->gid, retreive_record_message->request_number, node_db->id, retreive_record_message->receiver_id, status, 0, retrieved_record.data_entry);

					} else {
						status = (uint8_t) SUCCESS;
						response_message_4 = assemble_response_message(node_db->gid, retreive_record_message->request_number, node_db->id, retreive_record_message->receiver_id, status, 0, retrieved_record.data_entry);

					};
					call sender(response_message_4, done_case);
				};

				break;

			case RESPONSE: ;
				response_message_5 = (struct ResponseMessage*)(incoming_packet+1);

				// if the message is not intended for this node, ignore it.
				if (response_message_5->gid != node_db->gid || response_message_5->receiver_id != node_db->id){
					break;
				};

				if(!response_flag){
					response_flag=1;
					trigger(&response_flag);
				}

				switch(response_message_5->status){
					
					case OTHER_ERROR:
						break;
					case SUCCESS:
						if (response_checker[0] == response_message_5->request_number){
							switch(response_checker[1]){
								case CREATE_RECORD:
									proceed response_1_create;
									break;
								case DELETE_RECORD:
									proceed response_1_delete;
									break;
								case RETRIEVE_RECORD:
									proceed response_1_retrieve;
									break;
								default:
									break;
							}
						}
						break;
					case DB_FULL:
						proceed response_2;
						break;
					case DELETE_ERROR:
						proceed response_3;
						break;
					case RETRIEVE_ERROR:
						proceed response_4;
						break;
					default:
						break;

				};

				break;

			// if the type provided is > 5 || < 0
			default:
				DEBUG_PRINT("ERROR: received type [%d] is not legal packet type", tpe);
				break;

		};
	state done_case:

		tcv_endp(incoming_packet);

	//proceed receiving;
	
	// Succeeded in performing requested action
	state response_1_create:
		ser_out(response_1_create, "\r\n Data Saved");
		proceed receiving;
	state response_1_delete:
		ser_out(response_1_delete, "\r\n Record Deleted");
		proceed receiving;
	state response_1_retrieve:
		ser_outf(response_1_retrieve, "\r\n Record Received from %d: %s", response_message_5->sender_id, response_message_5->record);
		proceed receiving;
	
	// Failed to perform requests action
	state response_2:
		ser_outf(response_2, "\r\n The record can't be saved on node %d", response_message_5->sender_id);
		proceed receiving;
	state response_3:
		ser_outf(response_3, "\r\n The record does not exists on node %d", response_message_5->sender_id);
		proceed receiving;
	state response_4:
		ser_outf(response_4, "\r\n The record does not exist on node %d", response_message_5->sender_id);
		proceed receiving;

	// likely want to respond with error message
	state error:
		DEBUG_PRINT("ERROR: someting went wrong when receiving the packet");
		// handle error
		// retry?
		proceed receiving;
		
}

fsm root {
	/*
	#ifdef DEBUG_MODE
    if we need to set parameters specifically for debug mode, we can do it here.
	#endif
	*/
	int discovery_wait_flag = 0;
	char user_provided_record[20];
	uint8_t user_provided_index;
	
	uint8_t user provided_receiver_id;

	
	state initialize_node:
		// cast node_db to struct node * and malloc to it the size of a struct node
		// setup node structure
		node_db = (struct Node *)umalloc(sizeof(struct Node));

		// Bool condition, check for failure
		init_node(node_db);

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

		runfsm receiver(node_db);

	state menu:
		ser_outf(menu, "\r\nGroup %d Device #%d (%d/%d records)\r\n(G)roup ID\r\n(N)ew device ID\r\n(F)ind neighbors\r\n(C)reate record on neighbor\r\n(D)elete record on neighbor\r\n(R)etrieve record from neighbor\r\n(S)how local records\r\nR(e)set local storage\r\n\r\nSelection: ", node_db->gid, node_db->id, node_db->index, NUMB_OF_ENT);

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
				proceed clear_neighbour_array;
				break;
			case 'c':
			case 'C':
				proceed create_proto_start;
				break;
				
			case 'd':
			case 'D':
				proceed start_delete_proto;
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

	/*NOTE: Do we need to add new checks here? what are the limitations on group IDs*/
	state new_group_id:
		uint16_t NEW_NODE_GID;
		ser_inf(new_group_id, "%d", NEW_NODE_GID); // NOTE: is this syntax correct?
		
		DEBUG_PRINT("setting node group ID");

		if (!set_node_gid(node_db, NEW_NODE_GID)){
			DEBUG_PRINT("setting node group ID failed");
			strncpy(reason, "Error setting node ID", 50);
			proceed invalid_node_id;
		};

		proceed menu;

	state get_new_node_id:
		ser_out(get_new_node_id, "\r\nPlease provide a new node ID# (1-25 inclusive): ");

	state new_node_id:
		uint8_t NEW_NODE_ID;
		ser_inf(new_node_id, "%d", NEW_NODE_ID);
		
		// Check to see if the number given is within range.
		if(node_db->id < 1 || node_db->id > 25){
			strncpy(reason, "Out of Range", 50);
			proceed invalid_node_id;
		};
		
		// Check to see if the number give is unique
		for(int i = 0; i < 25; i++){
			if(node_db->id == node_db->nnodes[i]){
				strncpy(reason, "ID is already in use", 50);
				proceed invalid_node_id;
			};
		};

		// Bool condition, check for failure
		if (!set_node_id(node_db, NEW_NODE_ID)) {
			strncpy(reason, "Error setting node ID", 50);
			proceed invalid_node_id;
		};
		
		proceed menu;

	// NOTE: to prevent unwanted behaviour, we will likely want to clear the array in here
	state invalid_node_id:
		// NOTE: node_db->id will not be set if they provide an invalid reason, so we can't do this like this
		ser_outf(invalid_node_id, "\r\nID#: %d, is an invalid choice. Reason: %s.", node_db->id, reason);
		proceed get_new_node_id;


	/*The user has provided either an 'f' or an 'F', indicating they want to perform the find protocol.

	  The node receiving this command will reset its list of reachable neighbours, then it repeats the following sequence two times:
	  	1) send a discovery request
		2) waits 3 seconds for a response. During the waiting period, the node should receive the incoming discovery 
		   response and record their sender nodes IDs. 
		   
	  Then prints the list of neighbours
	
	*/
	state clear_neighbour_array:
		if (!clear_neighbour_array(&node_db)){
				strncpy(reason, "Error Clearing Node Array", 50);
				proceed error;
			};

	state find_proto_start:

		struct DiscoveryRequestMessage *request_packet;
		request_packet = (struct DiscoveryRequestMessage*)umalloc(sizeof(struct DiscoveryRequestMessage));

		request_packet->gid = node_db->gid;
		request_packet->tpe = DISCOVERY_REQUEST;
		request_packet->request_number = generate_request_num();
		request_packet->sender_id = node_db->id;
		request_packet->receiver_id=0;

		// call sender?
		// delay() ?
		// what should the trigger listen for?
		//trigger(&fin);
		call sender(request_packet, wait_discovery);
	
	state wait_discovery:
		if (discovery_wait_flag == 0){
			discovery_wait_flag=1;
			delay(3000, find_proto_start);
			release;
		}
		if (discovery_wait_flag == 1){
			discovery_wait_flag=0;
			delay(3000, display_neighbour_nodes);
			release;
		}
	
	state display_neighbour_nodes:
		ser_out(display_neighbour_nodes, "\r\n Neighbors: ");
		//ser_outf(display_neighbour_nodes, "\r\n Neighbors: %s", node_db->nnodes);
		for (int i=0; i<=NNODE_GROUP_SIZE; i++){
			if (node_db->nnodes[i]=='\0') break;
			ser_outf(display_neighbour_nodes, "%d, ", node_db->nnodes[i]);
		}
		proceed menu;

	/*
		the user has provided 'c' or 'C' command, indicating they wish to perform the create protocol.

		1) the node will ask the user through UART to provide the destination node ID and the record string to be saved.
		2) after receiving the previous information, the node sends the create record message to the destination node.
		3) the node then waits to receive the response message with a maximum wating interval of 3 seconds
		4) if no repsone is received, the node indicates this to the user through UART
		5) if a response is received, the node sends through UART the appropriate response message
	
	*/
	state create_proto_start:
		ser_out(create_proto_start, "Please provide a node ID (0-25): ");

	state get_id_for_create:
		ser_in(get_id_for_create, "%d", user_provided_receiver_id);

		if (user_provided_receiver_id < 1 || user_provided_receiver_id > 25){
			strncpy(reason, "Error: improper ID", 50);
			proceed error;
		};

	state ask_for_record_to_create:
		ser_out(ask_for_record_to_create, "Please provide a record (length <= 20): ");

	state get_record_to_create:
		ser_in(get_record_to_create, user_provided_record, 20);
		// NOTE: im not sure if we need to add checks here, this should stop them from entering anymore than 20 characters?

	state init_create_record_message:

		struct CreateRecordMessage *create_message;
		create_message = (struct CreateRecordMessage*)umalloc(sizeof(struct CreateRecordMessage));
		create_message->gid = node_db->gid;
		create_message->tpe = CREATE_RECORD;
		create_message->request_number = generate_request_num();
		create_message->sender_id = node_db->id;
		create_message->receiver_id = user_provided_receiver_id;
		strncpy(create_message->record, user_provided_record, 20);
		
		// Store create message type & request number for response message parsing
		response_checker[0] = create_message->request_number;
		response_checker[1] = create_message->tpe;

		call sender(&create_message, wait);
		// trigger?

	/*
		When a node receives the command ‘D’ or ‘d’: 
		1.The node asks the user through the UART to provide the destination node ID and the record index to be deleted 
		2.After receiving the previous information, the node sends a Delete Record Message to the destination node 
		3.The node then waits to receive the response message with a maximum waiting interval of 3 seconds 
		4.If no response is received, the node sends the following message through the UART “\r\nFailed to reach the destination”
		5.
	*/
	state start_delete_proto:
		ser_out(start_delete_proto, "Please provide a node ID (0-25): ");

	state get_id_for_delete:
		ser_inf(get_id_for_delete, "%d", user_provided_receiver_id);

		if (user_provided_receiver_id < 1 || user_provided_receiver_id > 25){
			strncpy(reason, "Error: improper node ID", 50);
			proceed error;
		};

	state ask_for_record_index:
		ser_out(ask_for_record_index, "Please provide the record index (0-40): ");

	state get_index_for_delete:
		ser_inf(get_index_for_delete, "%d", user_provided_index);

		if (user_provided_index < 0 || user_provided_index > 40){
			strncpy(reason, "Error: invalid index", 50);
			proceed error;
		};

	state init_delete_record_message:

		struct DeleteRecordMessage *delete_record;
		delete_record = (struct DeleteRecordMessage *)umalloc(sizeof(struct DeleteRecordMessage));
		delete_record->gid = node_db->gid;
		delete_record->tpe = DELETE_RECORD;
		delete_record->request_number = generate_request_num();
		delete_record->sender_id = node_db->id;
		delete_record->receiver_id = user_provided_receiver_id;
		delete_record->record_index = user_provided_index;
		// NOTE: something to do with padding here?

		// Store delete record message type & request number for response message parsing
		response_checker[0] = delete_record->request_number;
		response_checker[1] = delete_record->tpe;

		call sender(&delete_record, wait);
		// NOTE: trigger not added, not sure where it is explcitly needed

	/*
		When a node receives the command ‘R’ or ‘r’: 
		1.The node asks the user through the UART to provide the destination node ID and the record index to be retrieved 
		2.After receiving the previous information, the node sends a Retrieve Record Message to the destination node 
		3.The node then waits to receive the response message with a maximum waiting interval of 3 seconds 
		4.If no response is received, the node sends the following message through the UART “\r\nFailed to reach the destination”
		5.
	*/
	state start_retrieve_proto:
		ser_out(start_retrieve_proto, "Please provide a node ID (0-25): ");

	state get_id_for_retrieve:
		ser_inf(get_id_for_retrieve, "%d", user_provided_receiver_id);

		if (user_provided_receiver_id < 1 || user_provided_receiver_id > 25){
			strncpy(reason, "Error: improper node ID", 50);
			proceed error;
		};

	state ask_for_record_retrieve_index:
		ser_out(ask_for_record_retrieve_index, "Please provide the record index (0-40): ");

	state get_index_for_retrieve:
		ser_inf(get_index_for_retrieve, "%d", user_provided_index);

		if (user_provided_index < 0 || user_provided_index > 40){
			strncpy(reason, "Error: invalid index", 50);
			proceed error;
		};

	state retrieve_proto:

		struct RetrieveRecordMessage *retrieve_record;
		retrieve_record = (struct RetrieveRecordMessage *)umalloc(sizeof(struct RetrieveRecordMessage));
		retrieve_record->gid = node_db->gid;
		retrieve_record->tpe = RETRIEVE_RECORD;
		retrieve_record->request_number = generate_request_num();
		retrieve_record->sender_id = node_db->id;
		retrieve_record->receiver_id = user_provided_receiver_id;
		retrieve_record->record_index = user_provided_index;
		// NOTE: something to do with padding here?

		// Store retrieve record message type & request number for response message parsing
		response_checker[0] = retrieve_record->request_number;
		response_checker[1] = retrieve_record->tpe;
		
		call sender(&retrieve_record, wait);
		
	state display_db:
		ser_out(display_db, "\r\nIndex\tTime Stamp\t\tOwner ID\tRecord Data");
		
	state loop_through_data:
		for(int i = 0; i <= node_db->data_base.item_count; i++){
			ser_outf(loop_through_data, "\r\n%d\t\t%d\t%d%t%s", i, node_db->data_base.item_array[i].timestamp, node_db->data_base.item_array[i].owner_id, node_db->data_base.item_array[i].data_entry);
		}
		proceed menu;

	state del_local:
		delete_all(node_db);
		proceed menu;

	state wait:
		delay(3000, timeout);
		when(&response_flag, menu);
		release;
	
	state timeout:
		ser_out(timeout, "\r\nFailed to reach the destination");
		proceed menu;
	
	// NOTE: to prevent unwanted behaviour, we will likely want to clear the array in here
	state error:
		ser_outf(invalid_node_id, "\r\nError: %s", reason);
		proceed menu;
}
