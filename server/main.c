#include <enet/enet.h>
#include <stdbool.h>
#include <signal.h>
#include "logger.h"
#include "include/server.h"

volatile bool server_should_stop = false;

void handle_signal(int signal)
{
    if (signal == SIGINT || signal == SIGTERM) {
        server_should_stop = true;
    }
}

int signal_init()
{ if (signal(SIGINT, handle_signal) == SIG_ERR) {
        logger_write_error("Error setting up signal handler");
        return 1;
    }
    if (signal(SIGTERM, handle_signal) == SIG_ERR) {
        logger_write_error("Error setting up signal handler");
        return 1;
    }
    return 0;
}

int main()
{
    int error = 0;
    server_t server;

    error = logger_init(1);
    if (error != 0) return error;
    logger_write_info("Logger initialized");

    error = signal_init();
    if (error != 0) return error;

    error = server_init(&server);
    if (error != 0) return error;

    while (server.is_running && !server_should_stop) {
        ENetEvent event;
        while (enet_host_service(server.host, &event, 0) > 0) {
            switch (event.type) {
            case ENET_EVENT_TYPE_CONNECT:
                logger_write_info("Client connected");
                break;
            case ENET_EVENT_TYPE_DISCONNECT:
                logger_write_info("Client disconnected");
                break;
            case ENET_EVENT_TYPE_RECEIVE:
                logger_write_info("Packet received");
                enet_packet_destroy(event.packet);
                break;
            default:
                break;
            }
        }
    }

    server_destroy(&server);
    logger_write_info("Server stopped");
    logger_destroy();

    return 0;
}


