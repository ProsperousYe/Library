//
// Created by 28262 on 2022/3/7.
//

#ifndef LIBRARY_INTERFACE_H
#define LIBRARY_INTERFACE_H
#include "user.h"
#include "book_management.h"

int show_menu_login(char username[40], int role);

int show_menu_not_login();

void interface(User* currentuser, BookList* booklist, BookList* borrowedlist, UserList* userlist);

//void interface_login(User* currentuser, BookList* booklist, BookList* borrowedlist, UserList* userlist);
#endif //LIBRARY_INTERFACE_H
