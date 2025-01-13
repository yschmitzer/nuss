#include "logger.h"
#include "include/window.h"
#include "include/server.h"

int main(int argc, char **argv) {
    int error = 0;
    window_t window;
    server_t server;

    error = logger_init(1);
    if (error != 0) {
        return error;
    }

    error = window_init(&window, 800, 600, "nuss");
    if (error != 0) {
        logger_write_error("Failed to initialize window!");
        return error;
    }

    if (server_init(&server) != 0) {
        logger_write_warning("Could not initialize server connection.");
    }

    while (!window.should_close) {
        window_input(&window, &server);
        server_update(&server);
        window_update(&window);
        window_render(&window);
    }

    server_destroy(&server);
    window_destroy(&window);
    logger_destroy();

    return 0;
}

