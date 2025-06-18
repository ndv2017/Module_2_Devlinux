#ifndef STOPPED_STATE_H
#define STOPPED_STATE_H

#include "player_state.h"

typedef struct {
    player_state_t base;
    struct music_player* context;
} stopped_state_t;

player_state_t* stopped_state_create(void);

#endif // STOPPED_STATE_H
