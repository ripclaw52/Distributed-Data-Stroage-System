#include "header.hpp"

// reset neighbouring node array
void reset_array(struct Node* node) {
	for (int i=0; i<NNODE_GROUP_SIZE; i++) {
		node->nnodes[i] = 0;
	}
}