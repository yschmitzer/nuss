#include "../include/server.h"
#include "enet/enet.h"
#include "logger.h"

int server_init(server_t *server)
{
    server->peer = NULL;
    if (enet_initialize() != 0) {
        logger_write_error("Failed to initialize ENet.");
        return -1;
    }
    server->client = enet_host_create(NULL, 1, 2, 0, 0);
    if (!server->client) {
        logger_write_error("Failed to create ENet client.");
        return -2;
    }
    return 0;
}

void server_connect(server_t *server, const char *address, int port)
{
    if (!server->client) {
        int error = server_init(server);
        if (error != 0) {
            logger_write_warning("Failed to connect ENet.");
            return;
        }
    }

    ENetAddress serverAddress;
    enet_address_set_host(&serverAddress, address);
    serverAddress.port = port;

    server->peer = enet_host_connect(server->client, &serverAddress, 2, 0);
    if (!server->peer) {
        logger_write_error("Failed to connect to server.");
    } else {
        logger_write_info("Connecting to server...");
    }
}

void server_disconnect(server_t *server)
{
    if (server->peer) {
        logger_write_info("Disconnecting from server...");
        enet_peer_disconnect(server->peer, 0);
        server->peer = NULL;
    }
}

void server_update(server_t *server)
{
    ENetEvent event;
    while (enet_host_service(server->client, &event, 0) > 0) {
        switch (event.type) {
            case ENET_EVENT_TYPE_CONNECT:
                logger_write_info("Connected to server.");
                break;
            case ENET_EVENT_TYPE_RECEIVE:
                enet_packet_destroy(event.packet);
                break;
            case ENET_EVENT_TYPE_DISCONNECT:
                logger_write_info("Disconnected from server.");
                break;
            default:
                break;
        }
    }
}

void server_destroy(server_t *server)
{
    server_disconnect(server);
    if (server->client) {
        enet_host_destroy(server->client);
        server->client = NULL;
    }
    enet_deinitialize();
}

