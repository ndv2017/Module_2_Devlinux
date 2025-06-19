#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "buttons.h"

void buttons_init(void) {
    // Initialize random number generator for button simulation
    srand((unsigned)time(NULL));
    printf("[Buttons] Initialized\n");
}

int button1_pressed(void) {
    return (rand() % 1000) < 5;
}

int button2_pressed(void) {
    return (rand() % 1000) < 3;
}
