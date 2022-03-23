//
// Created by 28262 on 2022/3/7.
//

#ifndef LIBRARY_USER_H
#define LIBRARY_USER_H

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

void store_users();

void load_users();

void borrow_a_book();

void return_a_book();

void search_for_books();

void display_all_books();

#endif //LIBRARY_USER_H
