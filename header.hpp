#include "sysio.h"
#include "ser.h"
#include "serf.h"
#include "tcv.h"
#include "phys_cc1350.h"
#include "plug_null.h"

#define MAX_PKT_LEN 250
#define NUMB_OF_ENT 40
#define MAX_DB_ENT_LEN 20

#define NNODE_GROUP_SIZE 26
//#define SFD -1 session descriptor

// Base struct for records in the database
struct record{
	byte owner_id;
	char rec[MAX_DB_ENT_LEN];
	int timesstamp;
};

// This is an array of records
struct data{
	record item_array[NUM_OF_ENT];
};

// This is the struct for individual nodes. All nodes will have this basic
// design of ID, group id and database.
struct node {
    byte ID;
    char GID[2];		// This is 2 bytes an int is 4 bytes
    data DataBase;
	int c_db; 			// count of database entries
	uint8_t nnodes[NNODE_GROUP_SIZE];
};

// Specifically this is the response message but can be used as default
// template for all messages as it has all the variables for every message.
struct msg{
	char GID[2];
	byte type;
	byte req_num;
	byte sender_id;
	byte receiver_id;
	byte status;
	byte padding;
	char record[20];
};

void reset_array(struct node node_array);