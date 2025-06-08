#include <stdio.h>
#include "borrow.h"
#include "user.h"
#include "book.h"
#include "error.h"

int borrow_book(int user_id, int book_id) {
    User *user = user_find_by_id(user_id);
    Book *book = book_find_by_id(book_id);

    if (!user) {
        printf("Borrow failed: user ID %d not found.\n", user_id);
        return ERR_USER_NOT_FOUND;
    }

    if (!book) {
        printf("Borrow failed: book ID %d not found.\n", book_id);
        return ERR_BOOK_NOT_FOUND;
    }

    if (book->is_borrowed) {
        printf("Borrow failed: book ID %d is already borrowed.\n", book_id);
        return ERR_BOOK_ALREADY_BORROWED;
    }

    if (user->borrowed_count >= MAX_BORROWED_BOOKS) {
        printf("Borrow failed: user has reached borrowing limit.\n");
        return ERR_USER_BORROW_LIMIT;
    }

    user->borrowed_books[user->borrowed_count++] = book_id;
    book->is_borrowed = 1;

    printf("Borrow successful: User %d borrowed Book %d.\n", user_id, book_id);
    return 0;
}

int return_book(int user_id, int book_id) {
    User *user = user_find_by_id(user_id);
    Book *book = book_find_by_id(book_id);
    int found = 0;

    if (!user) {
        printf("Return failed: user ID %d not found.\n", user_id);
        return ERR_USER_NOT_FOUND;
    }

    if (!book) {
        printf("Return failed: book ID %d not found.\n", book_id);
        return ERR_BOOK_NOT_FOUND;
    }

    for (int i = 0; i < user->borrowed_count; ++i) {
        if (user->borrowed_books[i] == book_id) {
            user->borrowed_books[i] = user->borrowed_books[user->borrowed_count - 1];
            user->borrowed_count--;
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Return failed: book ID %d not borrowed by user ID %d.\n", book_id, user_id);
        return ERR_BOOK_NOT_BORROWED_BY_USER;
    }

    book->is_borrowed = 0;
    printf("Return successful: User %d returned Book %d.\n", user_id, book_id);

    return 0;
}
