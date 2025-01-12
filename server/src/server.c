#include "server.h"
#include "enet/enet.h"
#include "logger.h"

int server_init(server_t *server)
{
    if (enet_initialize() != 0) {
        logger_write_error("Could not initialize ENet");
        return 1;
    }

    server->port = 6942;
    server->clients_max = 5;
    server->channels_max = 2;
    server->incoming_bandwidth = 0;
    server->outgoing_bandwidth = 0;
    server->is_running = 0;

    server->address.host = ENET_HOST_ANY;
    server->address.port = server->port;
    server->host = enet_host_create(
        &server->address,
        server->clients_max,
        server->channels_max,
        server->incoming_bandwidth,
        server->outgoing_bandwidth
    );

    if (!server->host) {
        logger_write_error("Failed to create ENet server host");
        return 1;
    }

    server->is_running = 1;
    logger_write_info("Server initialized");
    return 0;
}

void server_destroy(server_t *server)
{
    enet_host_destroy(server->host);
    enet_deinitialize();
}
