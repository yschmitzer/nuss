#pragma once

#include <stdbool.h>
#include <enet/enet.h>

typedef struct server {
    ENetHost *client;
    ENetPeer *peer;
} server_t;

int server_init(server_t *server);
void server_connect(server_t *server, const char *address, int port);
void server_disconnect(server_t *server);
void server_update(server_t *server);
void server_destroy(server_t *server);
