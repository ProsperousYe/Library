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
    printf("(Logged in as: %s)\n", username);
    if (strcmp(username, "admin") != 0) {
	//role = 0;
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
	//role = 1;
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

void interface(User* currentuser, BookList* booklist, BookList* borrowedlist, UserList* userlist){
while(1){
        switch(show_menu_not_login()){
            case 1:printf("loading...\n");
			register_an_account(userlist);
			//interface(currentuser, booklist, borrowedlist, userlist);
			break;
            case 2:printf("loading...\n");
			if((currentuser = visitor_login(currentuser, userlist)) != NULL){
				printf("%s,%d", currentuser->username,currentuser->role);			
				printf("waiting...\n");
				while(1){
					switch(show_menu_login(currentuser->username, currentuser->role)){
					    case 1:printf("loading...\n");
						if(strcmp(currentuser->username, "admin") == 0){
						    printf("waiting...");
						    add_a_book(booklist);
						} else {
						    borrow_a_book(currentuser, booklist, borrowedlist);
						} break;
					    case 2:printf("loading...\n");
						if(strcmp(currentuser->username, "admin") == 0){
						    remove_a_book(booklist);
						} else {
						    return_a_book(currentuser, booklist, borrowedlist);
						} break;
					    case 3:printf("loading...\n");
							search_for_books(booklist);
							break;
					    case 4:printf("loading...\n");
							display_all_books(booklist);
							break;
					    case 5: 
							break;  
					}
					break;
				}
				//interface_login(currentuser, booklist, borrowedlist, userlist);
			}	
			break;           
            case 3:printf("loading...\n");
			search_for_books(booklist);
			break;
            case 4:printf("loading...\n");
			display_all_books(booklist);
			break;
            case 5:printf("exiting...\n");
			return;
        }
    
	}
}
