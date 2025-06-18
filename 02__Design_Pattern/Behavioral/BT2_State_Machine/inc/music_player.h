#ifndef MUSIC_PLAYER_H
#define MUSIC_PLAYER_H

#include "player_state.h"

typedef struct music_player {
    player_state_t* current_state;

    void (*click_play_button)(struct music_player* self);
    void (*click_pause_button)(struct music_player* self);
    void (*click_stop_button)(struct music_player* self);
    void (*change_state)(struct music_player* self, player_state_t* new_state);
} music_player_t;

music_player_t* music_player_create(player_state_t* initial_state);
void music_player_destroy(music_player_t* player);

#endif // MUSIC_PLAYER_H
