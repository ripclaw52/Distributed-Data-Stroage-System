#ifndef DISCOVERY_REQUESTS_H_
#define DISCOVERY_REQUESTS_H_



// uint16_t -> 2 bytes, uint8_t -> 1 byte
struct stDiscoveryMessage{
    uint16_t GID;       // Sender Node Group ID (2-bytes)
    uint8_t  type;      // Always set to zero for requests and one for responses
    uint8_t  rNum;      // Request Number (node generated random number)
    uint8_t  sID;       // Senders ID (the ID of the node that is sending)
    uint8_t  rID;       // Receiver ID (the ID of the node that is receiving) 
};

#endif