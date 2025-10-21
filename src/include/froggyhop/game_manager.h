#ifndef _GAME_MANAGER_H_
#define _GAME_MANAGER_H_

#include "game_context.h"


typedef struct {
	GameManager_Context context;
	GameState * state;	
} GameManager;


GameManager game_manager(GameState * init_state, GameState ** state_stack, Player_Ted ted);


void game_manager_execute(GameManager * self);

#endif


