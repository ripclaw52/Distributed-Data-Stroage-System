#ifndef DISCOVERY_REQUESTS_H_
#define DISCOVERY_REQUESTS_H_
#include <stdlib.h>
#include <string.h>
#include "sysio.h"
#include "ser.h"
#include "serf.h"
#include "tcv.h"
#include "phys_cc1350.h"
#include "plug_null.h"

#define MAX_PKT_LEN 250
#define NUMB_OF_ENT 40
#define MAX_DB_ENT_LEN 20
#define NETWORK_ID 0
#define NNODE_GROUP_SIZE 25 // NOTE: Should this be 24 because 1 - 25 inclusive?
/*BECAUSE THIS IS DEFINED THE BELOW IS TRUE*/
#define DEBUG_MODE

/*THIS IS TRUE*/
#ifdef DEBUG_MODE
#define DEBUG_PRINT(fmt, args...) diag(fmt, ## args)
#else
#define DEBUG_PRINT(fmt, args...) ;
#endif

enum MessageType {
	DISCOVERY_REQUEST,
	DISCOVERY_RESPONSE,
	CREATE_RECORD,
	DELETE_RECORD,
	RETRIEVE_RECORD,
	RESPONSE
};

enum Status {
	OTHER_ERROR,
	SUCCESS,
	DB_FULL,
	DELETE_ERROR,
	RETRIEVE_ERROR
};


// Base struct for records in the database
struct record{
	uint8_t owner_id;
	char data_entry[MAX_DB_ENT_LEN];
	unsigned long timestamp;  			// NOTE: might need to change data type in future
};

// This is an array of records
struct data{
	struct record item_array[NUMB_OF_ENT];
	uint8_t item_count;
};

// TODO: when a user "logs in", none of these node values are set, we will likely want to provide default values.
// NOTE FOR ABOVE: There are no pre initialized values in the assignment specs, also do not know if how assigning the node id would work as it need to be unique and if we hard code an init value it will not be unique.
// This is the struct for individual nodes. All nodes will have this basic
// design of ID, group id and database.
struct Node {
	uint8_t id;					// Individual Node ID (1-byte)							
	uint16_t gid;					// The Nodes group ID (2-bytes)
	struct data data_base;				// The database each node will have to fill
	uint8_t nnodes[NNODE_GROUP_SIZE]; 		// Array containing neighbouring nodes ids
	uint8_t index;					// We need to keep track of what index we are at in this list
};

struct DiscoveryRequestMessage{
	uint16_t gid;                			// Sender Node Group ID (2-bytes)
	uint8_t  tpe;            // Always set to zero for requests and one for responses
	uint8_t  request_number;      		// Request Number (node generated random number)
	uint8_t  sender_id;           		// Senders ID (the ID of the node that is sending)
	uint8_t  receiver_id;         		// Receiver ID (the ID of the node that is receiving) 
};

struct DiscoveryResponseMessage{
	uint16_t gid;                 		// Sender Node Group ID (2-bytes)
	uint8_t  tpe;           // Always set to zero for requests and one for responses
	uint8_t  request_number;      		// Request Number (node generated random number)
	uint8_t  sender_id;           		// Senders ID (the ID of the node that is sending)
	uint8_t  receiver_id;         		// Receiver ID (the ID of the node that is receiving) 
};

struct CreateRecordMessage{
	uint16_t gid;                 		// Sender Node Group ID (2-bytes)
	uint8_t  tpe;          	// Always set to zero for requests and one for responses
	uint8_t  request_number;			// Request Number (node generated random number)
	uint8_t  sender_id;           		// Senders ID (the ID of the node that is sending)
	uint8_t  receiver_id;         		// Receiver ID (the ID of the node that is receiving)
	char record[MAX_DB_ENT_LEN]; 			// Payload
};

struct DeleteRecordMessage{
	uint16_t gid;                 		// Sender Node Group ID (2-bytes)
	uint8_t  tpe;          	// Always set to zero for requests and one for responses
	uint8_t  request_number;			// Request Number (node generated random number)
	uint8_t  sender_id;           		// Senders ID (the ID of the node that is sending)
	uint8_t  receiver_id;         		// Receiver ID (the ID of the node that is receiving)
	uint8_t record_index;
	uint8_t padding;
};


struct RetrieveRecordMessage{
	uint16_t gid;                 		// Sender Node Group ID (2-bytes)
	uint8_t  tpe;          	// Always set to zero for requests and one for responses
	uint8_t  request_number;			// Request Number (node generated random number)
	uint8_t  sender_id;           		// Senders ID (the ID of the node that is sending)
	uint8_t  receiver_id;         		// Receiver ID (the ID of the node that is receiving)
	uint8_t  record_index;
	uint8_t padding;
};


// Specifically this is the response message but can be used as default
// template for all messages as it has all the variables for every message.
// NOTE not every message is going to require every type here,
struct ResponseMessage{
	uint16_t gid; 
	uint8_t tpe;
	uint8_t request_number;
	uint8_t sender_id;
	uint8_t receiver_id;
	uint8_t status;
	uint8_t padding;
	char record[20];
};

/*NODE METHODS*/
bool init_node(struct Node *node);
bool set_node_id(struct Node *node, uint8_t id);
bool set_node_gid(struct Node *node, uint16_t gid);
bool set_node_db_entry_count(struct Node *node, uint8_t count);

bool insert_record(struct Node *node, char* new_entry, uint8_t owner_id);
bool delete_record(struct Node *node, uint8_t index);
struct record retrieve_record(struct Node *node, uint8_t index);

void reset_array(struct Node *node);
uint8_t generate_request_num(void);
bool delete_all(struct Node *node);

#endif
