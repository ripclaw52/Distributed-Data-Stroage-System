#include "header.hpp"

// reset array
void reset_array(struct node node_array) {
	for (int i=0; i<NNODE_GROUP_SIZE; i++) {
		node_array->nnodes[i] = 0;
	}
}