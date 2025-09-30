#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <raylib.h>


typedef struct GameManager_Context GameManager_Context;


typedef struct GameState {
	struct GameState * (*callback)(struct GameState *, GameManager_Context *, float);
} GameState;


struct GameManager_Context {
	GameState ** state_stack;
};


typedef struct {
	GameManager_Context context;
	GameState * state;	
} GameManager;


GameManager game_manager(GameState * init_state, GameState ** state_stack) {
	return (GameManager) {
		.context = {
			.state_stack = state_stack
		}
		, .state = init_state
	};
}


void game_manager_execute(GameManager * self) {
	float frame_time = GetFrameTime();
	self->state = self->state->callback(self->state, &self->context, frame_time);
}


#define WINDOW_TITLE "Froggy Hop"





int main(void) {
	InitWindow(800, 600, WINDOW_TITLE);
    SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);
	SetTargetFPS(144);
	
	GameManager game_manager_instance = game_manager(NULL, NULL);

	while(WindowShouldClose() == false) {
		BeginDrawing();
		ClearBackground(WHITE);
		DrawFPS(10, 10);
		EndDrawing();
	}

	CloseWindow();

	printf("program exit..\n");
	return EXIT_SUCCESS;
}


