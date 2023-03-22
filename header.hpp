#ifndef DISCOVERY_REQUESTS_H_
#define DISCOVERY_REQUESTS_H_
#include <cstdint>
#include <stdlib.h>
#include "sysio.h"
#include "ser.h"
#include "serf.h"
#include "tcv.h"
#include "phys_cc1350.h"
#include "plug_null.h"

#include "discovery_requests.hpp"

#define MAX_PKT_LEN 250
#define NUMB_OF_ENT 40
#define MAX_DB_ENT_LEN 20
#define NETWORK_ID 0
#define NNODE_GROUP_SIZE 26 //NOTE: shouldn't this be 25? (0-25)
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
	DB_EMPTY
};


// Base struct for records in the database
struct record{
	uint8_t owner_id;
	char data_entry[MAX_DB_ENT_LEN];
	unsigned long timestamp;  			// NOTE: might need to change data type in future
};

// This is an array of records
struct data{
	record item_array[NUMB_OF_ENT];
	uint8_t index;
};

// TODO: when a user "logs in", none of these node values are set, we will likely want to provide default values.
// This is the struct for individual nodes. All nodes will have this basic
// design of ID, group id and database.
struct Node {
    uint8_t id;							
    uint16_t gid;						
    data data_base;
	uint8_t nnodes[NNODE_GROUP_SIZE]; 	// Array containing neighbouring nodes ids
	uint8_t index;						// we need to keep track of what index we are at in this list
};

struct DiscoveryRequestMessage{
    uint16_t gid;                 						// Sender Node Group ID (2-bytes)
	uint8_t  type = DISCOVERY_REQUEST;                	// Always set to zero for requests and one for responses
    uint8_t  request_number;      						// Request Number (node generated random number)
    uint8_t  sender_id;           						// Senders ID (the ID of the node that is sending)
    uint8_t  receiver_id;         						// Receiver ID (the ID of the node that is receiving) 
};

struct DiscoveryResponseMessage{
    uint16_t gid;                 						// Sender Node Group ID (2-bytes)
    uint8_t  type = DISCOVERY_RESPONSE;                 // Always set to zero for requests and one for responses
    uint8_t  request_number;      						// Request Number (node generated random number)
    uint8_t  sender_id;           						// Senders ID (the ID of the node that is sending)
    uint8_t  receiver_id;         						// Receiver ID (the ID of the node that is receiving) 
};

struct CreateRecordMessage{
	uint16_t gid;                 						// Sender Node Group ID (2-bytes)
    uint8_t  type = CREATE_RECORD;          			// Always set to zero for requests and one for responses
	uint8_t  request_number;							// Request Number (node generated random number)
	uint8_t  sender_id;           						// Senders ID (the ID of the node that is sending)
    uint8_t  receiver_id;         						// Receiver ID (the ID of the node that is receiving)
	char record[MAX_DB_ENT_LEN]; 						// Payload
};

struct DeleteRecordMessage{
	uint16_t gid;                 						// Sender Node Group ID (2-bytes)
    uint8_t  type = DELETE_RECORD;          			// Always set to zero for requests and one for responses
	uint8_t  request_number;							// Request Number (node generated random number)
	uint8_t  sender_id;           						// Senders ID (the ID of the node that is sending)
    uint8_t  receiver_id;         						// Receiver ID (the ID of the node that is receiving)
	uint8_t padding;
};


struct RetrieveRecordMessage{
	uint16_t gid;                 						// Sender Node Group ID (2-bytes)
    uint8_t  type = RETRIEVE_RECORD;          			// Always set to zero for requests and one for responses
	uint8_t  request_number;							// Request Number (node generated random number)
	uint8_t  sender_id;           						// Senders ID (the ID of the node that is sending)
    uint8_t  receiver_id;         						// Receiver ID (the ID of the node that is receiving)
	uint8_t  record_index;
	uint8_t padding;
};


// Specifically this is the response message but can be used as default
// template for all messages as it has all the variables for every message.
// NOTE not every message is going to require every type here,
struct ResponseMessage{
	uint16_t gid; 
	uint8_t type = RESPONSE;
	uint8_t request_number;
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

void reset_array(struct node* node);
uint8_t generate_request_num(void);

#endif