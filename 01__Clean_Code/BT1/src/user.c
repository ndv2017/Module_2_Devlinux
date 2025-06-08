#include <stdio.h>
#include <string.h>
#include "user.h"

User user_db[MAX_USERS];
int user_count = 0;

int user_add(const char *name) {
    if (user_count >= MAX_USERS) return -1;

    user_db[user_count].id = user_count + 1;
    strncpy(user_db[user_count].name, name, MAX_NAME_LEN);
    user_db[user_count].borrowed_count = 0;

    return user_count++;
}

int user_edit(int id, const char *new_name) {
    User *user = user_find_by_id(id);
    if (!user) return -1;

    strncpy(user->name, new_name, MAX_NAME_LEN);

    return 0;
}

int user_delete(int id) {
    for (int i = 0; i < user_count; ++i) {
        if (user_db[i].id == id) {
            user_db[i] = user_db[user_count - 1];
            user_count--;
            return 0;
        }
    }

    return -1;
}

User* user_find_by_id(int id) {
    for (int i = 0; i < user_count; ++i) {
        if (user_db[i].id == id)
            return &user_db[i];
    }

    return NULL;
}

void user_print_info(int id) {
    User *user = user_find_by_id(id);
    if (!user) {
        printf("User ID %d not found.\n", id);
        return;
    }

    printf("User ID: %d | Name: %s\n", user->id, user->name);
    printf("Borrowed Books (%d):\n", user->borrowed_count);
    for (int i = 0; i < user->borrowed_count; ++i) {
        Book *b = book_find_by_id(user->borrowed_books[i]);
        if (b) {
            printf(" - [%d] %s by %s\n", b->id, b->title, b->author);
        }
    }
}
