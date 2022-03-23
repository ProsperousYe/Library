//
// Created by 28262 on 2022/3/7.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "interface.h"
#include "user.h"
#include "visitor.h"
#include "librarian.h"
#include "book_management.h"


int show_menu_login(char username[40], int role){
    int option;
    printf("(Logged in as: %c\n)", username);
    if (!strcmp(username, "librarian")) {
	role = 1;
        printf("Please choose an option:\n");
        printf("1) Borrow a book\n");
        printf("2) Return a book\n");
        printf("3) Search for books\n");
        printf("4) Display all books\n");
        printf("5) Quit\n");
        printf(" Option:");
        scanf("%d", &option);
        if (0 < option && option < 6) {
            return option;
        } else {
            printf("\nSorry, the option you entered was invalid, please try again.");
            show_menu_login(username, role);
        }
    } else {
	role = 2;
        printf("Please choose an option:\n");
        printf("1) Add a book\n");
        printf("2) Remove a book\n");
        printf("3) Search for books\n");
        printf("4) Display all books\n");
        printf("5) Log out\n");
        printf(" Option:");
        scanf("%d", &option);
        if (0 < option && option < 6) {
            return option;
        } else {
            printf("\nSorry, the option you entered was invalid, please try again.");
            show_menu_login(username, role);
        }
    }
}

int show_menu_not_login(){
    int option;
    printf("Please choose an option:\n");
    printf("1) Register an account\n");
    printf("2) Login\n");
    printf("3) Search for books\n");
    printf("4) Display all books\n");
    printf("5) Quit\n");
    printf(" Option:");
    scanf("%d", &option);
    if(0 < option && option < 6){
        return option;
    } else {
        printf("\nSorry, the option you entered was invalid, please try again.");
        show_menu_not_login();
    }
}

void interface(User* currentuser, BookList* booklist, BookList* borrowedlist, UserList* userlist, int login){
    if(login){
        switch(show_menu_login(currentuser->username, currentuser->role)){
            case 1:
                if(currentuser->role == 2){
                    add_a_book(booklist);
			interface(currentuser, booklist, borrowedlist, userlist, login);
                } else {
                    borrow_a_book(booklist, borrowedlist);
			interface(currentuser, booklist, borrowedlist, userlist, login);
                }
            case 2:
                if(currentuser->role == 2){
                    remove_a_book(booklist);
			interface(currentuser, booklist, borrowedlist, userlist, login);
                } else {
                    return_a_book(booklist, borrowedlist);
			interface(currentuser, booklist, borrowedlist, userlist, login);
                }
            case 3:search_for_books(booklist);
			interface(currentuser, booklist, borrowedlist, userlist, login);
            case 4:display_all_books(booklist);
			interface(currentuser, booklist, borrowedlist, userlist, login);
            case 5: interface(currentuser, booklist, borrowedlist, userlist, 0);                
        }
    } else {
        switch(show_menu_not_login()){
            case 1:register_an_account(userlist);
			interface(currentuser, booklist, borrowedlist, userlist, login);
            case 2:visitor_login(currentuser, userlist, login); //输入账号密码，验证后，将log状态改为1，并且调用show_menu_login（）
			interface(currentuser, booklist, borrowedlist, userlist, login);               
            case 3:search_for_books(booklist);
			interface(currentuser, booklist, borrowedlist, userlist, login);
            case 4:display_all_books(booklist);
			interface(currentuser, booklist, borrowedlist, userlist, login);
            case 5: //退出系统
                break;
        }
    }
    return;
}
