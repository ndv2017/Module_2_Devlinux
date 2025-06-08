#include <stdio.h>
#include <string.h>
#include "book.h"

Book book_db[MAX_BOOKS];
int book_count = 0;

int book_add(const char *title, const char *author) {
    if (book_count >= MAX_BOOKS) return -1;

    book_db[book_count].id = book_count + 1;
    strncpy(book_db[book_count].title, title, MAX_TITLE_LEN);
    strncpy(book_db[book_count].author, author, MAX_AUTHOR_LEN);
    book_db[book_count].is_borrowed = 0;

    return book_count++;
}

int book_edit(int id, const char *new_title, const char *new_author) {
    Book *book = book_find_by_id(id);
    if (!book) return -1;

    strncpy(book->title, new_title, MAX_TITLE_LEN);
    strncpy(book->author, new_author, MAX_AUTHOR_LEN);

    return 0;
}

int book_delete(int id) {
    for (int i = 0; i < book_count; ++i) {
        if (book_db[i].id == id) {
            book_db[i] = book_db[book_count - 1];
            book_count--;
            return 0;
        }
    }

    return -1;
}

Book* book_find_by_id(int id) {
    for (int i = 0; i < book_count; ++i) {
        if (book_db[i].id == id)
            return &book_db[i];
    }

    return NULL;
}

Book* book_find_by_title(const char *title) {
    for (int i = 0; i < book_count; ++i) {
        if (strcmp(book_db[i].title, title) == 0)
            return &book_db[i];
    }

    return NULL;
}

void book_list_available(void) {
    printf("Available Books:\n");
    for (int i = 0; i < book_count; ++i) {
        if (!book_db[i].is_borrowed) {
            printf("ID: %d | Title: %s | Author: %s\n",
                   book_db[i].id,
                   book_db[i].title,
                   book_db[i].author);
        }
    }
}
