#include "header.hpp"
#include <cstdint>

/*
This function will initialize an empty node strucutre, provided a pointer to that strucutre
*/
bool init_node(struct Node* node){
    node->id  = 0;                  // default id value 0
    node->gid = 0;                  // default gid value 0
    node->index = 0;                // default entry count 0
    node->data_base;                // default empty array THIS WILL LIKELY NEED TO BE AMENDED
   
    /* check that each item is set to what we want it intialized to e.g., !node->id, we set it to 0, so this should 
       evaluate to 1.
    */
    if ((!node->id) && (!node->gid) && (!node->db_entry_count) && (sizeof(node->data_base) == 0)){
        return true;
    } 
    DEBUG_PRINT("Error initializing node...\n");
    return false;
};

bool set_node_id(struct Node* node, uint8_t id){
    node->id = id; 
    return node->id == id;
};

bool set_node_gid(struct Node* node, uint16_t gid){
    node->gid = gid; 
    return node->gid == gid;
};

// NOTE: count can be a uint8_t because it goes to 255 and the count will never exceed 40
bool set_node_db_entry_count(struct Node* node, uint8_t count){
    node->index = count; 
    return node->index == count;
};


// reset neighbouring node array
void reset_array(struct Node* node) {
	for (int i=0; i<NNODE_GROUP_SIZE; i++) {
		node->nnodes[i] = 0;
	}
}

// Generate random value between 0-255
uint8_t generate_request_num(void){
    return (uint8_t) (rand() % 255);
}