#include "froggyhop/game_state_game_control.h"
#include <raylib.h>


static GameState * game_state_game_control_callback(
        GameState * self, GameManager_Context * context) {
    DrawText("Game Control", 400, 300, 40, BLACK);

    if(IsKeyPressed(KEY_SPACE) == true) {
        return context->state_stack[GameState_ID_Pause];
    } else {
        return context->state_stack[GameState_ID_GameControl];
    }
}


GameState_GameControl game_state_game_control(void) {
    return (GameState_GameControl) {
        .super = {
            .callback = game_state_game_control_callback
        }
    };
}




