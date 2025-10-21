#include "froggyhop/game_state_menu.h"
#include <raylib.h>


static GameState * game_state_menu_callback(
        GameState * self, GameManager_Context * context) {
    DrawText("Menu", 400, 300, 40, BLACK);
    if(IsKeyPressed(KEY_SPACE) == true) {
        return context->state_stack[GameState_ID_Options];        
    } else {
        return context->state_stack[GameState_ID_Menu];        
    }
}


GameState_Menu game_state_menu(void) {
    return (GameState_Menu) {
        .super = {
            .callback = game_state_menu_callback
        }
    };
}

