#include "scene_manager.h"
#include "scenes/boot_menu.h"
#include "scenes/main_menu.h"
#include "scenes/settings_menu.h"
#include "scenes/server_menu.h"
#include "scenes/world_scene.h"
#include "logger.h"

static SceneType current_scene;
static void (*scene_update)();
static void (*scene_render)();

void scene_manager_init() {
    logger_write_info("Scene manager initialized.");
    current_scene = SCENE_BOOT_MENU;
    scene_update = boot_menu_update;
    scene_render = boot_menu_render;
}

void scene_manager_set_scene(SceneType scene) {
    current_scene = scene;
    switch (scene) {
        case SCENE_BOOT_MENU:
            scene_update = boot_menu_update;
            scene_render = boot_menu_render;
            break;
        case SCENE_MAIN_MENU:
            scene_update = main_menu_update;
            scene_render = main_menu_render;
            break;
        case SCENE_SETTINGS_MENU:
            scene_update = settings_menu_update;
            scene_render = settings_menu_render;
            break;
        case SCENE_SERVER_MENU:
            scene_update = server_menu_update;
            scene_render = server_menu_render;
            break;
        case SCENE_WORLD:
            scene_update = world_scene_update;
            scene_render = world_scene_render;
            break;
    }
}

void scene_manager_update() {
    scene_update();
}

void scene_manager_render() {
    scene_render();
}

void scene_manager_destroy() {
    logger_write_info("Scene manager destroyed.");
}

