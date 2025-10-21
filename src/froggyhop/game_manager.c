#include "froggyhop/game_manager.h"
#include <raylib.h>


GameManager game_manager(GameState * init_state, GameState ** state_stack, Player_Ted ted) {
	return (GameManager) {
		.context = {
			.state_stack = state_stack
            , .ted = ted
		}
		, .state = init_state
	};
}


void game_manager_execute(GameManager * self) {
	self->context.frame_time = GetFrameTime();
	self->state = self->state->callback(self->state, &self->context);
}


