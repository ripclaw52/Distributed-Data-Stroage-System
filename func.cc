#include "header.hpp"

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