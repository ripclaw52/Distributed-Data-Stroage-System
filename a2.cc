#include<header.hpp>

char CHOICE;
char reason[20];
int sfd = -1;

fsm receiver{

}

fsm root{

	state initialize_node:
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

	state create_proto:

	state delete_proto:

	state retrieve_proto:

	state display_db:

	state del_local:

}