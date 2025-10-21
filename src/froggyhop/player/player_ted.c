#include "froggyhop/player/player_ted.h"


Player_Ted player_ted(Texture2D texture) {
    return (Player_Ted) {
        .texture = texture
    };
}
