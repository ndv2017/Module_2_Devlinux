#ifndef BOOK_H
#define BOOK_H

#include "config.h"

typedef struct {
    int id;
    char title[MAX_TITLE_LEN];
    char author[MAX_AUTHOR_LEN];
    int is_borrowed;    // 0 = available, 1 = borrowed
} Book;

extern Book book_db[MAX_BOOKS];
extern int book_count;

int book_add(const char *title, const char *author);
int book_edit(int id, const char *new_title, const char *new_author);
int book_delete(int id);
Book* book_find_by_id(int id);
Book* book_find_by_title(const char *title);
void book_list_available(void);

#endif // BOOK_H
