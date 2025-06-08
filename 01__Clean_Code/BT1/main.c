#include <stdio.h>
#include <string.h>
#include "book.h"
#include "user.h"
#include "borrow.h"
#include "search.h"
#include "error.h"
#include "config.h"

void print_menu(void);

int main() {
    int option;

    while (1) {
        print_menu();
        scanf("%d", &option);
        getchar();

        if (option == 0) break;

        int id, user_id, book_id;
        char buffer[MAX_BUF];
        int res;

        switch (option) {
            case 1: {
                char title[MAX_TITLE_LEN];
                char author[MAX_AUTHOR_LEN];

                printf("Enter book title: ");
                fgets(buffer, sizeof(buffer), stdin);
                buffer[strcspn(buffer, "\n")] = '\0';
                strcpy(title, buffer);

                printf("Enter author: ");
                fgets(buffer, sizeof(buffer), stdin);
                buffer[strcspn(buffer, "\n")] = '\0';
                strcpy(author, buffer);

                id = book_add(title, author);
                if (id >= 0)
                    printf("Book added with ID: %d\n", id + 1);
                else
                    printf("Error: %s\n", get_error_msg(ERR_MAX_BOOKS_REACHED));

                break;
            }

            case 2:
                printf("Enter user name: ");
                fgets(buffer, sizeof(buffer), stdin);
                buffer[strcspn(buffer, "\n")] = '\0';

                id = user_add(buffer);
                if (id >= 0)
                    printf("User added with ID: %d\n", id + 1);
                else
                    printf("Error: %s\n", get_error_msg(ERR_MAX_USERS_REACHED));

                break;

            case 3:
                printf("Enter user ID: ");
                scanf("%d", &user_id);

                printf("Enter book ID: ");
                scanf("%d", &book_id);
                getchar();

                res = borrow_book(user_id, book_id);
                if (res != ERR_OK)
                    printf("Error: %s\n", get_error_msg(res));

                break;

            case 4:
                printf("Enter user ID: ");
                scanf("%d", &user_id);

                printf("Enter book ID: ");
                scanf("%d", &book_id);
                getchar();

                res = return_book(user_id, book_id);
                if (res != ERR_OK)
                    printf("Error: %s\n", get_error_msg(res));

                break;

            case 5:
                book_list_available();
                break;

            case 6:
                list_all_users();
                break;

            case 7:
                printf("Enter title keyword: ");
                fgets(buffer, sizeof(buffer), stdin);
                buffer[strcspn(buffer, "\n")] = '\0';

                search_books_by_title(buffer);
                break;

            case 8:
                printf("Enter author keyword: ");
                fgets(buffer, sizeof(buffer), stdin);
                buffer[strcspn(buffer, "\n")] = '\0';

                search_books_by_author(buffer);
                break;

            case 9:
                printf("Enter user ID: ");
                scanf("%d", &user_id);
                getchar();

                user_print_info(user_id);
                break;

            default:
                printf("Invalid option.\n");
        }
    }

    printf("Exiting system.\n");
    return 0;
}

void print_menu(void) {
    printf("=============================================\n");
    printf("\nLibrary Management System:\n");
    printf("1. Add Book\n");
    printf("2. Add User\n");
    printf("3. Borrow Book\n");
    printf("4. Return Book\n");
    printf("5. List Available Books\n");
    printf("6. List Users\n");
    printf("7. Search Book by Title\n");
    printf("8. Search Book by Author\n");
    printf("9. Show User Info\n");
    printf("0. Exit\n");
    printf("Choose an option: ");
}
