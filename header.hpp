#include "sysio.h"
#include "ser.h"
#include "serf.h"

#define NUMBER_OF_ENTRIES 40

#define MAXIMUM_DB_ENTRY_LENGTH 20

struct node {

    int ID;
    int GID;
    char DataBase[NUMBER_OF_ENTRIES][MAXIMUM_DB_ENTRY_LENGTH];
    // ID (1 byte) + GID (2 bytes) + timestamp
    char metadata[NUMBER_OF_ENTRIES][]

};