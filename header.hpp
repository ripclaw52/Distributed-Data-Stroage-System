#ifndef DISCOVERY_REQUESTS_H_
#define DISCOVERY_REQUESTS_H_
#include <cstdint>
/*
#include "sysio.h"
#include "ser.h"
#include "serf.h"
#include "tcv.h"
#include "phys_cc1350.h"
#include "plug_null.h"
*/


#include "discovery_requests.hpp"

#define MAX_PKT_LEN 250
#define NUMB_OF_ENT 40
#define MAX_DB_ENT_LEN 20
#define NETWORK_ID 0
#define NNODE_GROUP_SIZE 26
/*BECAUSE THIS IS DEFINED THE BELOW IS TRUE*/
#define DEBUG_MODE

/*THIS IS TRUE*/
#ifdef DEBUG_MODE
#define DEBUG_PRINT(fmt, args...) diag(fmt, ## args)
#else
#define DEBUG_PRINT(fmt, args...) ;
#endif


/* NOTE: a uint8_t is a byte, a uint16_t is 2 bytes (or a word in picos)

		if these types dont work in picos for some reason, we can convery them back

*/



// Base struct for records in the database
struct record{
	uint8_t owner_id;
	char record[MAX_DB_ENT_LEN];
	int timestamp;  			// NOTE: might need to change data type in future
};

// This is an array of records
struct data{
	record item_array[NUMB_OF_ENT];
};

// This is the struct for individual nodes. All nodes will have this basic
// design of ID, group id and database.
struct Node {
    uint8_t id;							
    uint16_t gid;						// I changed this from char GID[2] to uint16_t GID
    data data_base;
	uint8_t db_entry_count; 			// count of database entries
	uint8_t nnodes[NNODE_GROUP_SIZE]; 	// Array containing neighbouring nodes ids
};

/* No matter what message we get (or send), we know this will populate the header from 
   byte 1 to byte 6.
*/
struct MessageHeader{
	uint16_t gid; 
	uint8_t type;
	uint8_t req_num;
	uint8_t sender_id;
	uint8_t receiver_id;
};

// Specifically this is the response message but can be used as default
// template for all messages as it has all the variables for every message.
// NOTE not every message is going to require every type here,
struct Message{
	uint16_t gid; // I changed this from char GID[2] to uint16_t GID
	uint8_t type;
	uint8_t req_num;
	uint8_t sender_id;
	uint8_t receiver_id;
	uint8_t status;
	uint8_t padding;
	char record[20];
};

/*NODE METHODS*/
bool init_node(struct node* node);
bool set_node_id(struct node* node, uint8_t id);
bool set_node_gid(struct node* node, uint16_t gid);
bool set_node_db_entry_count(struct node* node, uint8_t count);

//void reset_array(struct node* node);

#endif