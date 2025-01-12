#ifndef SERVER_H
#define SERVER_H

#include <stdbool.h>
#include <enet/enet.h>

bool server_init();
void server_connect(const char *address, int port);
void server_disconnect();
void server_update();
void server_destroy();

#endif // SERVER_H

