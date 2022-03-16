//
// Created by 28262 on 2022/3/7.
//
#include <stdio.h>
#include <string.h>
#include "interface.h"
#include "user.h"
#include "visitor.h"
#include "librarian.h"


int show_menu_login(char username[40]){
    int option;
    printf("(Logged in as: %c\n)", username);
    if (!strcmp("librarian", username)) {
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
            show_menu_login(username);
        }
    } else {
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
            show_menu_login(username);
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

void interface(){
    if(login){
        switch(show_menu_not_login()){
            case 1:
                if(strcmp("librarian",username)){
                    add_a_book();
                    break;
                } else {
                    borrow_a_book();
                    break;
                }
            case 2:
                if(strcmp("librarian",username)){
                    remove_a_book();
                    break;
                } else {
                    return_a_book();
                    break;
                }
            case 3:search_for_books();
                break;
            case 4:display_all_books();
                break;
            case 5:log_out(); //将log状态改为0，并且调用show_menu_not_login（）
                break;
        }
    } else {
        switch(show_menu_not_login()){
            case 1:register_an_account();
                break;
            case 2:login(); //输入账号密码，验证后，将log状态改为1，并且调用show_menu_login（）
                break;
            case 3:search_for_books();
                break;
            case 4:display_all_books();
                break;
            case 5:quit(); //退出系统
                break;
        }
    }
    return;
}