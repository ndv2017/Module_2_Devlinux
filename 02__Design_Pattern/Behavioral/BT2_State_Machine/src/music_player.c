#include <stdlib.h>
#include "music_player.h"

static void click_play_button(music_player_t* self) {
    if (self->current_state && self->current_state->press_play)
        self->current_state->press_play(self->current_state);
}

static void click_pause_button(music_player_t* self) {
    if (self->current_state && self->current_state->press_pause)
        self->current_state->press_pause(self->current_state);
}

static void click_stop_button(music_player_t* self) {
    if (self->current_state && self->current_state->press_stop)
        self->current_state->press_stop(self->current_state);
}

static void change_state(music_player_t* self, player_state_t* new_state) {
    self->current_state = new_state;
    if (new_state && new_state->set_context)
        new_state->set_context(new_state, self);
}

music_player_t* music_player_create(player_state_t* initial_state) {
    music_player_t* player = (music_player_t*)malloc(sizeof(music_player_t));
    if (!player) {
        return NULL;
    }

    player->click_play_button = click_play_button;
    player->click_pause_button = click_pause_button;
    player->click_stop_button = click_stop_button;
    player->change_state = change_state;
    player->change_state(player, initial_state);

    return player;
}

void music_player_destroy(music_player_t* player) {
    free(player);
}
