//
// Created by 28262 on 2022/3/7.
//

#ifndef LIBRARY_USER_H
#define LIBRARY_USER_H

typedef struct _User {
    char password[40];
    char username[40];
    struct _User *next;
} User;

typedef struct _UserList {
   User* list; // pointer to a list of struct User.
   unsigned int length;
} UserList;

typedef struct _CurrentUser{
	char password[40];
	char username[40];
	int role;
} CurrentUser;


void borrow_a_book();

void return_a_book();

void search_for_books();

void display_all_books();

void log_out();
#endif //LIBRARY_USER_H
