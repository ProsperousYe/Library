//
// Created by 28262 on 2022/3/7.
//

#ifndef LIBRARY_USER_H
#define LIBRARY_USER_H
#include "book_management.h"

typedef struct _User {
    char *password;
    char *username;
    int role;
    struct _User *next;
    //struct BookList *borrowedbooks;
} User;

typedef struct _UserList {
   User* list; // pointer to a list of struct User.
   unsigned int length;
} UserList;

void store_users(FILE *file, UserList *userlist);

void load_users(FILE *file, UserList *userlist);

int add_user(UserList *userlist, User *new_user);

void borrow_a_book(User* currentuser, BookList* booklist, BookList* borrowedlist);

void return_a_book(User* currentuser, BookList* booklist, BookList* borrowedlist);

void search_for_books(BookList* booklist);

void display_all_books(BookList* booklist);

#endif //LIBRARY_USER_H
