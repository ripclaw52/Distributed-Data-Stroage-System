#include "discovery_requests.hpp"
#include <cstdint> // might be excludable in hte PicOS env...

bool setGID(struct stDiscoveryMessage *st, uint16_t GID){
    st->GID = GID;
    return st->GID == GID; // evals to 0 (failed), or 1 (success)
};

bool setType(struct stDiscoveryMessage *st, uint8_t type){
    st->type = type;
    return st->type == type;
};

//TODO: implement random number generation
void setRequestNumber(struct stDiscoveryMessage *st){
    uint8_t random = 1;
    st->rNum = random;
};

bool setSenderID(struct stDiscoveryMessage *st, uint8_t sID){
    st->sID = sID;
    return st->sID == sID;
};

bool setReceiverID(struct stDiscoveryMessage *st, uint8_t rID){
    st->rID = rID;
    return st->rID == rID;
};

