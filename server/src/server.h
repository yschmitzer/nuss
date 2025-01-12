#ifndef SERVER_H
#define SERVER_H

#include "enet/enet.h"
#include <stdint.h>

typedef struct server {
    uint32_t incoming_bandwidth;
    uint32_t outgoing_bandwidth;
    uint16_t clients_max;
    uint16_t channels_max;
    uint16_t port;
    uint8_t is_running;
    ENetHost *host;
    ENetAddress address;
    // ENetPeer *clients[5]; //TODO: how to make this dynamically adjustable? should use clients_max... !
} server_t;

int server_init(server_t *server);
void server_destroy(server_t *server);

#endif // SERVER_H
