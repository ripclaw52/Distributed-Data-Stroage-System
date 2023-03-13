#include "sysio.h"
#include "ser.h"
#include "serf.h"
#include "tcv.h"
#include "phys_cc1350.h"
#include "plug_null.h"

#define MAX_PKT_LEN 250 
#define NUMBER_OF_ENTRIES 40
#define MAXIMUM_DB_ENTRY_LENGTH 20
//#define SFD -1 session descriptor


struct node {

    byte ID;
    int GID;
    char DataBase[NUMBER_OF_ENTRIES][MAXIMUM_DB_ENTRY_LENGTH];
    // ID (1 byte) + GID (2 bytes) + timestamp
    char metadata[NUMBER_OF_ENTRIES][]

};





