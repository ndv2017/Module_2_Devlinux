#include <stdio.h>
#include <stdlib.h>
#include "music_player.h"
#include "stopped_state.h"

int main(void) {
    music_player_t* player = music_player_create(stopped_state_create());
    if (!player) {
        fprintf(stderr, "Failed to create music player\n");
        return EXIT_FAILURE;
    }

    printf("\n--> Press Play\n");
    player->click_play_button(player);

    printf("\n--> Press Pause\n");
    player->click_pause_button(player);

    printf("\n--> Press Play\n");
    player->click_play_button(player);

    printf("\n--> Press Stop\n");
    player->click_stop_button(player);

    printf("\n--> Press Pause\n");
    player->click_pause_button(player);

    music_player_destroy(player);
    return 0;
}
