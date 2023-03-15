#ifndef DISCOVERY_REQUESTS_H_
#define DISCOVERY_REQUESTS_H_



// uint16_t -> 2 bytes, uint8_t -> 1 byte
struct stDiscoveryMessage{
    uint16_t gid;                 // Sender Node Group ID (2-bytes)
    uint8_t  type;                // Always set to zero for requests and one for responses
    uint8_t  request_number;      // Request Number (node generated random number)
    uint8_t  sender_id;                 // Senders ID (the ID of the node that is sending)
    uint8_t  receiver_id;                 // Receiver ID (the ID of the node that is receiving) 
};

bool set_discovery_message_gid(struct stDiscoveryMessage *st, uint16_t GID);
bool set_discovery_message_type(struct stDiscoveryMessage *st, uint8_t type);
void set_request_number(struct stDiscoveryMessage *st);
bool set_sender_id(struct stDiscoveryMessage *st, uint8_t sID);
bool set_receiver_id(struct stDiscoveryMessage *st, uint8_t rID);
#endif