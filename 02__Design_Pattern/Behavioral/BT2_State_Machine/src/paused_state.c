#include <stdio.h>
#include <stdlib.h>
#include "paused_state.h"
#include "playing_state.h"
#include "stopped_state.h"
#include "music_player.h"

static void press_play(player_state_t* self) {
    paused_state_t* state = (paused_state_t*)self;

    printf("Resuming music...\n");
    state->context->change_state(state->context, playing_state_create());
}

static void press_pause(player_state_t* self) {
    printf("Music is already paused.\n");
}

static void press_stop(player_state_t* self) {
    paused_state_t* state = (paused_state_t*)self;

    printf("Stopping music from paused state...\n");
    state->context->change_state(state->context, stopped_state_create());
}

static void set_context(player_state_t* self, struct music_player* context) {
    ((paused_state_t*)self)->context = context;
}

player_state_t* paused_state_create(void) {
    paused_state_t* state = (paused_state_t*)malloc(sizeof(paused_state_t));

    state->base.press_play = press_play;
    state->base.press_pause = press_pause;
    state->base.press_stop = press_stop;
    state->base.set_context = set_context;
    state->context = NULL;

    return (player_state_t*)state;
}
