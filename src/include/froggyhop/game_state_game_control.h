#ifndef _GAME_STATE_GAME_CONTROL_H_
#define _GAME_STATE_GAME_CONTROL_H_

#include "game_context.h"


typedef struct {
    GameState super;
} GameState_GameControl;


GameState_GameControl game_state_game_control(void);


#endif


