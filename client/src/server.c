#include "server.h"
#include "logger.h"

static ENetHost *client = NULL;
static ENetPeer *peer = NULL;

bool server_init() {
    if (enet_initialize() != 0) {
        logger_write_error("Failed to initialize ENet.");
        return false;
    }
    client = enet_host_create(NULL, 1, 2, 0, 0);
    if (!client) {
        logger_write_error("Failed to create ENet client.");
        return false;
    }
    return true;
}

void server_connect(const char *address, int port) {
    if (!client) {
        server_init();
    }
    if (!client) {
        logger_write_warning("Could not initialize server connection.");
        return;
    }

    ENetAddress serverAddress;
    enet_address_set_host(&serverAddress, address);
    serverAddress.port = port;

    peer = enet_host_connect(client, &serverAddress, 2, 0);
    if (!peer) {
        logger_write_error("Failed to connect to server.");
    } else {
        logger_write_info("Connecting to server...");
    }
}

void server_disconnect() {
    logger_write_info("Disconnecting from server...");
    server_destroy();
}

void server_update() {
    ENetEvent event;
    while (enet_host_service(client, &event, 0) > 0) {
        switch (event.type) {
            case ENET_EVENT_TYPE_CONNECT:
                logger_write_info("Connected to server.");
                break;
            case ENET_EVENT_TYPE_RECEIVE:
                enet_packet_destroy(event.packet);
                break;
            case ENET_EVENT_TYPE_DISCONNECT:
                logger_write_info("Disconnected from server.");
                server_destroy();
                break;
            default:
                break;
        }
    }
}

void server_destroy() {
    if (client) {
        if (peer) {
            enet_peer_disconnect(peer, 0); // Ensure proper disconnection
            peer = NULL;
        }
        enet_host_destroy(client);
        client = NULL;
    }
    enet_deinitialize();
}

