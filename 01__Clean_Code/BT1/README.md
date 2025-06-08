**BT1**. Build a Simple Library Management Application Following [Clean Code Rules](https://www.canva.com/design/DAGlse_Tohg/v2GkCpr5Th5xUvbPzMyAQQ/edit?utm_content=DAGlse_Tohg&utm_campaign=designshare&utm_medium=link2&utm_source=sharebutton) and [C Coding Convention](https://github.com/MaJerle/c-code-style)

*Description*:
1. Book Information Management
   - Each book has the following information: title, author, ID, borrowing status.
   - Allow adding, editing, and deleting books in the library.
2. User Management
   - Each user has information: name, ID, list of borrowed books.
   - Allow adding, editing, and deleting user information.
3. Book Borrowing and Returning Management
   - Allow users to borrow books if books are available in stock.
   - Track the number of books borrowed and returned.
4. Search and Information Display
   - Search books by title, author.
   - Display list of available books in the library.
   - Display user information and borrowed books.
5. Error Handling
   - Validate input data.
   - Handle error cases such as out-of-stock books, non-existent users, etc.

---

*Answer*:

This is a modular Library Management System implemented in C, following Clean Code practices and a layered design.

* [book.c](/01__Clean_Code/BT1/src/book.c) & [book.h](/01__Clean_Code/BT1/inc/book.h): Handles book-related operations — adding, editing, deleting, searching, and listing available books.
* [user.c](/01__Clean_Code/BT1/src/user.c) & [user.h](/01__Clean_Code/BT1/inc/user.h): Manages user data — creating, updating, deleting users and tracking borrowed books.
* [borrow.c](/01__Clean_Code/BT1/src/borrow.c) & [borrow.h](/01__Clean_Code/BT1/inc/borrow.h): Implements borrowing and returning logic, enforcing availability and user borrowing limits.
* [search.c](/01__Clean_Code/BT1/src/search.c) & [search.h](/01__Clean_Code/BT1/inc/search.h): Provides utilities to search books by title or author, and to list all books and users.
* [error.c](/01__Clean_Code/BT1/src/error.c) & [error.h](/01__Clean_Code/BT1/inc/error.h): Defines centralized error codes and messages for consistent error handling across modules.
* [config.h](/01__Clean_Code/BT1/inc/config.h): Contains global configuration constants (e.g., max books/users, string lengths) to avoid magic numbers.
* [main.c](/01__Clean_Code/BT1/main.c): Acts as the entry point and CLI interface, coordinating all system actions.

The architecture ensures separation of concerns, testability, and ease of maintenance.
