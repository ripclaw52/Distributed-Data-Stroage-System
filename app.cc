#include<header.hpp>

char CHOICE;
char reason[20];
int sfd = -1;

//struct node * node_db = NULL; im pretty certain you are setting a pointer to null here?

struct Node node_db; // globally defined struct, represents the node.


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

// sends packet information to other nodes
fsm sender(const void *message) {
	address packet;
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
			// EXIT SENDER FSM
			break;
		}

	state sending:
		packet = tcv_wnp(sending, sfd, 4 + packet_size); //NOTE: PUT SIZE OF MESSAGE + 4
		packet[0] = NETWORK_ID;

		/*
		 * Sending specific message structure into packet
		 */
		switch(message->tpe) {
			// Discovery Request
			case DISCOVERY_REQUEST: ;
				// format packet for discovery request message
				break;

			// Discovery Response
			case DISCOVERY_RESPONSE: ;
				// format packet for discovery response message
				break;

			// Create Record
			case CREATE_RECORD: ;
				// format packet for create record message
				break;

			// Delete Record
			case DELETE_RECORD: ;
				// format packet for delete record message
				break;

			// Retrieve Record
			case RETRIEVE_RECORD: ;
				// format packet for retrieve record message
				break;

			// Response 
			case RESPONSE: ;
				// format packet for response message
				break;

			// Type is not matching with any other value
			default:
				// packet being sent is not of a valid type
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
				}

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
				struct ResponseMessage* response_message_5 = (struct ResponseMessage*)(incoming_packet+1);

				// if the message is not intended for this node, ignore it.
				if (response_message_5->gid != node_db->gid || response_message_5->receiver_id != node_db->id){
					break;
				};

				switch(response_message_5->status){
					
					case OTHER_ERROR:
						break;
					case SUCCESS:
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
	state response_1_cre:
		ser_out(response_1_cre, "\r\n Data Saved");
		proceed receiving;
	state response_1_del:
		ser_out(response_1_del, "\r\n Record Deleted");
		proceed receiving;
	state response_1_ret:
		//ser_outf(response_1_ret, "\r\n Record Received from %d: %s", message->sender_id, message->record);
		proceed receiving;
	
	// Failed to perform requestws action
	state response_2:
		//ser_outf(response_2, "\r\n The record can't be saved on node %d", message->sender_id);
		proceed receiving;
	state response_3:
		//ser_outf(response_3, "\r\n The record does not exists on node %d", message->sender_id);
		proceed receiving;
	state response_4:
		//ser_outf(response_4, "\r\n The record does not exist on node %d", message->sender_id);
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

	state initialize_node:
		// cast node_db to struct node * and malloc to it the size of a struct node 
		node_db = (struct Node *)umalloc(sizeof(struct Node));

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
		ser_inf(new_node_id, "%d", node_db->id);
		
		// Check to see if the number given is within range.
		if(node_db->id < 1 || node_db->id > 25){
			reason = "Out of Range";
			proceed invalid_node_id;
		}
		
		// Check to see if the number give is unique
		for(int i = 0; i < 25; i++){
			if(node_db->id == node_db->nnodes[i]){
				reason = "ID is in use";
				proceed invalid_node_id;
			}
		}
		proceed menu;

	state invalid_node_id:
		ser_outf(invalid_node_id, "\r\nID#: %d, is an invalid choice. Reason: %s.", node_db->id, reason);
		proceed get_new_node_id;

	state find_proto:
		trigger(&fin);
/* DON"T THINK WE NEED THE BELOW, it will also break the code due to payload not being declaired.
	state display_neighboring_array:
		ser_out(display_neighboring_array, "\r\n Neighbors: ");
		for (int i=0; i<NNODE_GROUP_SIZE; i++) {
			if (payload->nnodes[i] == 0) {
				break;
			} else {
				ser_outf(display_neighboring_array, "%d, ", payload->nnodes[i]);
			}
		}
		ser_out(display_neighboring_array, "\r\n");
*/

	state create_proto:
		
	state delete_proto:
		
	state retrieve_proto:
		
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
}
