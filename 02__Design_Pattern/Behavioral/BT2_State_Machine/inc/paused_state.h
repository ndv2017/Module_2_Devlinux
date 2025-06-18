#ifndef PAUSED_STATE_H
#define PAUSED_STATE_H

#include "player_state.h"

typedef struct {
    player_state_t base;
    struct music_player* context;
} paused_state_t;

player_state_t* paused_state_create(void);

#endif // PAUSED_STATE_H
