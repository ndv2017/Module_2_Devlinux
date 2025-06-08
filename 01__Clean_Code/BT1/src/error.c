#include "error.h"

const char* get_error_msg(int err_code) {
    switch (err_code) {
        case ERR_OK: return "Success";
        case ERR_USER_NOT_FOUND: return "User not found";
        case ERR_BOOK_NOT_FOUND: return "Book not found";
        case ERR_BOOK_ALREADY_BORROWED: return "Book already borrowed";
        case ERR_USER_BORROW_LIMIT: return "User borrow limit reached";
        case ERR_BOOK_NOT_BORROWED_BY_USER: return "Book not borrowed by this user";
        case ERR_MAX_BOOKS_REACHED: return "Maximum book limit reached";
        case ERR_MAX_USERS_REACHED: return "Maximum user limit reached";
        default: return "Unknown error";
    }
}
