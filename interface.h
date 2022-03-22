//
// Created by 28262 on 2022/3/7.
//

#ifndef LIBRARY_INTERFACE_H
#define LIBRARY_INTERFACE_H
#include "user.h"
#include "book_management.h"

int show_menu_login(char username[40], int role);

int show_menu_not_login();

void interface(CurrentUser* currentuser, Book* booklist, Book* borrowedlist, User* userlist, int login);
#endif //LIBRARY_INTERFACE_H
