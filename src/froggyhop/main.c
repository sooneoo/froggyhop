#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <raylib.h>

#include "froggyhop/game_manager.h"
#include "froggyhop/game_state_menu.h"
#include "froggyhop/game_state_game_control.h"
#include "froggyhop/player/player_ted.h"


typedef struct {
    GameState super;
} GameState_Options;


static GameState * game_state_options_callback(
        GameState * self, GameManager_Context * context) {
    DrawText("Options", 400, 300, 40, BLACK);
    if(IsKeyPressed(KEY_SPACE) == true) {
        return context->state_stack[GameState_ID_GameControl];
    } else {
        return context->state_stack[GameState_ID_Options];
    }
}


GameState_Options game_state_options(void) {
    return (GameState_Options) {
        .super = {
            .callback = game_state_options_callback
        }     
    };
}


typedef struct {
    GameState super;
} GameState_Pause;


static GameState * game_state_pause_callback(
        GameState * self, GameManager_Context * context) {
    DrawText("Pause", 400, 300, 40, BLACK);
    if(IsKeyPressed(KEY_SPACE) == true) {
        return context->state_stack[GameState_ID_GameOver];
    } else {
        return context->state_stack[GameState_ID_Pause];
    }
}


GameState_Pause game_state_pause(void) {
    return (GameState_Pause) {
        .super = {
            .callback = game_state_pause_callback
        }
    };
}


typedef struct {
    GameState super;
} GameState_GameOver;


static GameState * game_state_game_over_callback(
        GameState * self, GameManager_Context * context) {
    DrawText("Game Over", 400, 300, 40, BLACK);
    if(IsKeyPressed(KEY_SPACE) == true) {
        return context->state_stack[GameState_ID_Menu];
    } else {
        return context->state_stack[GameState_ID_GameOver];
    }
}

 
GameState_GameOver game_state_game_over(void) {
    return (GameState_GameOver) {
        .super = {
            .callback = game_state_game_over_callback
        }
    };
}



static Player_Ted ted;

static GameState_Menu state_menu;
static GameState_Options state_options;
static GameState_GameControl state_game_control;
static GameState_Pause state_pause;
static GameState_GameOver state_game_over;

static GameState* state_buff_mem[GameState_ID_N] = {
    &state_menu.super
    , &state_options.super
    , &state_pause.super
    , &state_game_control.super
    , &state_game_over.super
};

GameManager game_manager_instance;

#define IMG "assets/img/"


#include "version.h"
#define WINDOW_TITLE "Froggy Hop"


int main(void) {
    FroggyHop_Version version = froggyhop_version();
    char wtitle[64];
    sprintf(wtitle, "%s %d.%d.%d", WINDOW_TITLE, version.major, version.minor, version.patch);

	InitWindow(800, 600, wtitle);
    SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);
	SetTargetFPS(144);
	
    Texture2D texture_ted = LoadTexture(IMG "ted.png");

    ted = player_ted(texture_ted); 

    state_menu = game_state_menu();
    state_options = game_state_options();
    state_game_control = game_state_game_control();
    state_pause = game_state_pause();
    state_game_over = game_state_game_over();
	game_manager_instance = game_manager(&state_menu.super, state_buff_mem, ted);

	while(WindowShouldClose() == false) {
		BeginDrawing();
		ClearBackground(WHITE);
        game_manager_execute(&game_manager_instance);
		DrawFPS(10, 10);
		EndDrawing();
	}

    UnloadTexture(texture_ted);
	CloseWindow();

	printf("program exit..\n");
	return EXIT_SUCCESS;
}


