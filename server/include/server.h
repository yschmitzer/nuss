#pragma once

#include "enet/enet.h"
#include <stdbool.h>
#include <stdint.h>

typedef struct server {
    uint32_t incoming_bandwidth;
    uint32_t outgoing_bandwidth;
    uint16_t clients_max;
    uint16_t channels_max;
    uint16_t port;
    bool is_running;
    ENetHost *host;
    ENetAddress address;
    // ENetPeer *clients[5]; //TODO
} server_t;

int server_init(server_t *server);
void server_destroy(server_t *server);
