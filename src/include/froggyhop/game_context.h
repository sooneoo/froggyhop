#ifndef _GAME_CONTEXT_H_
#define _GAME_CONTEXT_H_

#include "player/player_ted.h"

typedef struct GameState GameState;


typedef struct {
    Player_Ted ted;

	GameState ** state_stack;
    float frame_time;
} GameManager_Context;


struct GameState {
	struct GameState * (*callback)(struct GameState *, GameManager_Context *);
};


typedef enum {
    GameState_ID_Menu
    , GameState_ID_Options
    , GameState_ID_Pause
    , GameState_ID_GameControl
    , GameState_ID_GameOver
    , GameState_ID_N
} GameState_ID ;


#endif


