//
// Created by 28262 on 2022/3/7.
//

#include "visitor.h"
void register_an_account(){
    printf("please input the username:");
    scanf("%c\n", currentuser->username);
    printf("please input the password:");
    scanf("%c\n", currentuser->password);
}

void visitor_login(CurrentUser* currentuser, Book* booklist, Book* borrowedlist, User* userlist, int login){
    login = 1;
    interface(interface(currentuser, userlist, borrowedlist, userlist, login);
}

void quit(){
    exit();
}
