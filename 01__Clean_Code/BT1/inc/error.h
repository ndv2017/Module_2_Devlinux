#ifndef ERROR_H
#define ERROR_H

#define ERR_OK                          0
#define ERR_USER_NOT_FOUND              -1
#define ERR_BOOK_NOT_FOUND              -2
#define ERR_BOOK_ALREADY_BORROWED       -3
#define ERR_USER_BORROW_LIMIT           -4
#define ERR_BOOK_NOT_BORROWED_BY_USER   -5
#define ERR_MAX_BOOKS_REACHED           -6
#define ERR_MAX_USERS_REACHED           -7

const char* get_error_msg(int err_code);

#endif // ERROR_H
