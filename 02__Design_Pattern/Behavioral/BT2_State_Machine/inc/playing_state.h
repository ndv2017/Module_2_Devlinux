#ifndef PLAYING_STATE_H
#define PLAYING_STATE_H

#include "player_state.h"

typedef struct {
    player_state_t base;
    struct music_player* context;
} playing_state_t;


player_state_t* playing_state_create(void);

#endif // PLAYING_STATE_H
