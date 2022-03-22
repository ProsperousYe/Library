//
// Created by 28262 on 2022/3/7.
//
#include "book_management.h"
#include "user.h"
#include "visitor.h"
#include <stdio.h>

void borrow_a_book(){

}

void return_a_book(){

}

void search_for_books(Book* booklist){
    int option;
    char title[40];
    char authors[40];
    unsigned int year;
    printf("how you want to search?Please choose an option:\n");
    printf("1) search by title\n");
    printf("2) search by author\n");
    printf("3) search by year\n");
    scanf("%d",&option);
    switch (option) {
        case 1 :
            
            printf("please input the title:");
            scanf("%c", title);
            find_book_by_title(title);
        
        case 2 :

            printf("please input the authors:");
            scanf("%c", authors);
            find_book_by_author(authors);
        
        case 3 :

            printf("please input the year:");
            scanf("%d", &year);
            find_book_by_year(year);
        
    }

}

void display_all_books(Book* booklist){
    Book* current = booklist->next;
    printf("id\ttitle\tauthor\tyear\tcopies\n");
    while(current){
        printf("%d\t%c\t%c\t%d\t%d\n",current->id, current->title, current->authors, current->year, current->copies);
    }
}

void log_out(CurrentUser* currentuser, Book* booklist, Book* borrowedlist, User* userlist, int login){
	login = 0;
    	interface(currentuser, userlist, borrowedlist, userlist, login);
}
