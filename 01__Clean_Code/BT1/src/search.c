#include <stdio.h>
#include <string.h>
#include "book.h"
#include "user.h"

void search_books_by_title(const char *title) {
    printf("Search Results (Title: %s):\n", title);
    for (int i = 0; i < book_count; ++i) {
        if (strstr(book_db[i].title, title)) {
            printf("ID: %d | Title: %s | Author: %s | %s\n",
                   book_db[i].id,
                   book_db[i].title,
                   book_db[i].author,
                   book_db[i].is_borrowed ? "Borrowed" : "Available");
        }
    }
}

void search_books_by_author(const char *author) {
    printf("Search Results (Author: %s):\n", author);
    for (int i = 0; i < book_count; ++i) {
        if (strstr(book_db[i].author, author)) {
            printf("ID: %d | Title: %s | Author: %s | %s\n",
                   book_db[i].id,
                   book_db[i].title,
                   book_db[i].author,
                   book_db[i].is_borrowed ? "Borrowed" : "Available");
        }
    }
}

void list_all_books(void) {
    printf("All Books in Library:\n");
    for (int i = 0; i < book_count; ++i) {
        printf("ID: %d | Title: %s | Author: %s | %s\n",
               book_db[i].id,
               book_db[i].title,
               book_db[i].author,
               book_db[i].is_borrowed ? "Borrowed" : "Available");
    }
}

void list_all_users(void) {
    printf("Registered Users:\n");
    for (int i = 0; i < user_count; ++i) {
        printf("ID: %d | Name: %s | Borrowed: %d books\n",
               user_db[i].id,
               user_db[i].name,
               user_db[i].borrowed_count);
    }
}
