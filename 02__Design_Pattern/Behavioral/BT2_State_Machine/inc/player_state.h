#ifndef PLAYER_STATE_H
#define PLAYER_STATE_H

struct music_player;

typedef struct player_state {
    void (*press_play)(struct player_state* self);
    void (*press_pause)(struct player_state* self);
    void (*press_stop)(struct player_state* self);
    void (*set_context)(struct player_state* self, struct music_player* context);
} player_state_t;

#endif // PLAYER_STATE_H
