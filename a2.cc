#include "sysio.h"
#include "ser.h"
#include "serf.h"

char CHOICE;
char reason[20];

fsm receiver{

}

fsm root{
	state menu:
		ser_outf(menu, "\r\nGroup %d Device #%d (%d/%d records)\r\n(G)roup ID\r\n(N)ew device ID\r\n(F)ind neighbors\r\n(C)reate record on neighbor\r\n(D)elete record on neighbor\r\n(R)etrieve record from neighbor\r\n(S)how local records\r\nR(e)set local storage\r\n\r\nSelection: ", node_group_id, node_id, num_of_rec, max_num_rec);

	state get_choice:
		ser_inf(get_choice, "%c", &CHOICE);
		if(CHOICE == 'G' || CHOICE == 'g'){
			proceed get_new_group_id;
		} else if(CHOICE == 'N' || CHOICE == 'n'){
			proceed get_new_node_id;
		} else if(CHOICE == 'F' || CHOICE == 'f'){
			proceed find_proto;
		} else if(CHOICE == 'C' || CHOICE == 'c'){
			proceed create_proto;
		} else if(CHOICE == 'D' || CHOICE == 'd'){
			proceed delete_proto;
		} else if(CHOICE == 'R' || CHOICE == 'r'){
			proceed retrieve_proto;
		} else if(CHOICE == 'S' || CHOICE == 's'){
			proceed display_db;
		} else if(CHOICE == 'E' || CHOICE == 'e'){
			proceed del_local;
		} else{
			proceed menu;
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

	state create_proto:

	state delete_proto:

	state retrieve_proto:

	state display_db:

	state del_local:

}