#ifndef _GAME_STATE_MENU_H_
#define _GAME_STATE_MENU_H_


#include "game_context.h"


typedef struct {
    GameState super;
} GameState_Menu;


#define GAME_STATE_MENU ((T)(GameState_Menu*))


GameState_Menu game_state_menu(void);


#endif


