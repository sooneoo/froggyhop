#ifndef _PLAYER_TED_H_
#define _PLAYER_TED_H_

#include "object/object_state.h"
#include <raylib.h>


typedef struct {
    Object_State super;
    Texture2D texture;
} Player_Ted;   


Player_Ted player_ted(Texture2D texture);


#endif


