#include <stdio.h>
#include <stdlib.h>
#include "stopped_state.h"
#include "music_player.h"
#include "playing_state.h"

static void press_play(player_state_t* self) {
    stopped_state_t* state = (stopped_state_t*)self;

    printf("Starting to play music...\n");
    state->context->change_state(state->context, playing_state_create());
}

static void press_pause(player_state_t* self) {
    printf("Nothing to pause. Music is stopped.\n");
}

static void press_stop(player_state_t* self) {
    printf("Music is already stopped.\n");
}

static void set_context(player_state_t* self, struct music_player* context) {
    ((stopped_state_t*)self)->context = context;
}

player_state_t* stopped_state_create(void) {
    stopped_state_t* state = (stopped_state_t*)malloc(sizeof(stopped_state_t));
    if (!state) {
        return NULL;
    }

    state->base.press_play = press_play;
    state->base.press_pause = press_pause;
    state->base.press_stop = press_stop;
    state->base.set_context = set_context;
    state->context = NULL;

    return (player_state_t*)state;
}
