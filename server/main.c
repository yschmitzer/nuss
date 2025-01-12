#include <stdio.h>
#include <stdbool.h>
#include <enet/enet.h>

int main() {
    if (enet_initialize() != 0) {
        fprintf(stderr, "An error occurred while initializing ENet.\n");
        return EXIT_FAILURE;
    }
    printf("Server initialized!\n");

    // Create an ENet host
    ENetAddress address;
    ENetHost *server;

    address.host = ENET_HOST_ANY;
    address.port = 1234;

    server = enet_host_create(&address, 32, 2, 0, 0);
    if (!server) {
        fprintf(stderr, "Failed to create server host.\n");
        enet_deinitialize();
        return EXIT_FAILURE;
    }

    printf("Server is running...\n");
    bool running = true;
    while (running) {
        ENetEvent event;
        while (enet_host_service(server, &event, 1000) > 0) {
            switch (event.type) {
                case ENET_EVENT_TYPE_CONNECT:
                    printf("A client connected.\n");
                    break;
                case ENET_EVENT_TYPE_RECEIVE:
                    printf("Packet received: %s\n", (char *)event.packet->data);
                    enet_packet_destroy(event.packet);
                    break;
                case ENET_EVENT_TYPE_DISCONNECT:
                    printf("A client disconnected.\n");
                    break;
                default:
                    break;
            }
        }
    }

    enet_host_destroy(server);
    enet_deinitialize();
    return 0;
}

