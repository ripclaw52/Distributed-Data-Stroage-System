#include "discovery_requests.hpp"
#include <cstdint> // might be excludable in the PicOS env...

bool set_discovery_message_gid(struct stDiscoveryMessage *st, uint16_t GID){
    st->gid = GID;
    return st->gid == GID; // evals to 0 (failed), or 1 (success)
};

bool set_discovery_message_type(struct stDiscoveryMessage *st, uint8_t type){
    st->type = type;
    return st->type == type;
};

//TODO: implement random number generation
void set_request_number(struct stDiscoveryMessage *st){
    uint8_t random = 1;
    st->request_number = random;
};

bool set_sender_id(struct stDiscoveryMessage *st, uint8_t sID){
    st->sender_id = sID;
    return st->sender_id == sID;
};

bool set_receiver_id(struct stDiscoveryMessage *st, uint8_t rID){
    st->receiver_id = rID;
    return st->receiver_id == rID;
};

