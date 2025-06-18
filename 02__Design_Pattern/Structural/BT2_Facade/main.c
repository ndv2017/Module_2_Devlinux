#include <stdio.h>
#include <stdlib.h>
#include "smart_home_facade.h"

int main(void) {
    smart_home_facade_t* smart_home = smart_home_facade_create();

    printf("Activating Morning Routine:\n");
    activate_morning_routine(smart_home);

    printf("\nActivating Away Mode:\n");
    activate_away_mode(smart_home);

    printf("\nActivating Movie Night:\n");
    activate_movie_night(smart_home);

    printf("\nFreeing allocated memory...\n");
    free(smart_home->lighting);
    free(smart_home->security);
    free(smart_home->hvac);
    free(smart_home);

    return 0;
}
