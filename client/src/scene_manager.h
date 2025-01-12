#ifndef SCENE_MANAGER_H
#define SCENE_MANAGER_H

typedef enum {
    SCENE_BOOT_MENU,
    SCENE_MAIN_MENU,
    SCENE_SETTINGS_MENU,
    SCENE_SERVER_MENU,
    SCENE_WORLD
} SceneType;

void scene_manager_init();
void scene_manager_set_scene(SceneType scene);
void scene_manager_update();
void scene_manager_render();
void scene_manager_destroy();

#endif // SCENE_MANAGER_H

