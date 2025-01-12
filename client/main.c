#include "logger.h"
#include "src/window.h"
#include "src/scene_manager.h"
#include "src/server.h"

int main(int argc, char **argv) {
    logger_init(true);
    if (!window_init(800, 600, "Minecraft Clone")) {
        logger_write_error("Failed to initialize window!");
        return -1;
    }

    if (!server_init()) {
        logger_write_warning("Could not initialize server connection.");
    }

    scene_manager_init();
    scene_manager_set_scene(SCENE_BOOT_MENU);

    while (!window_should_close()) {
        scene_manager_update();
        scene_manager_render();
        window_refresh();
    }

    scene_manager_destroy();
    server_destroy();
    window_destroy();
    logger_destroy();

    return 0;
}

