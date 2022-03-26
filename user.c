//
// Created by 28262 on 2022/3/7.
//
#include "book_management.h"
#include "user.h"
#include "visitor.h"
#include <stdio.h>

void borrow_a_book(User* currentuser, BookList* booklist, BookList* borrowedlist){
	Book* current = booklist->list->next;
	Book* borrowed_current = borrowedlist->list->next;
	unsigned int option;
//print out the available books
      printf("id\ttitle\tauthor\tyear\tcopies\n");
      while(current->next != NULL){
		if(current->copies != 0) {
		  printf("%d\t%s\t%s\t%d\t%d\n",current->id, current->title, current->authors, current->year, current->copies);
		   current = current->next;
		} else current = current->next;
	}
	printf("please choose the book that you want to borrow(input the id):");
	while(1) {
		scanf("%d", &option);
		if(option < 0 || option > borrowedlist->length){
			printf("the option is invalid! please re-input:(");
			continue;
		} else break;	
	}
			current = booklist->list->next;
			while(current->id != option)
				current = current->next; //find the chosen book
//update the statement of the chosen book
			Book* new_borrowedbook = (Book *)malloc(sizeof(Book));
			new_borrowedbook->id = current->id;
			new_borrowedbook->title = (char *)malloc(strlen(current->title));
			strcpy(new_borrowedbook->title, current->title);
			new_borrowedbook->authors = (char *)malloc(strlen(current->authors));
			strcpy(new_borrwedbook->authors, current->authors);
			new_borrowedbook->year = current->year;
			new_borrowedbook->currentborroweduser = (char *)malloc(strlen(currentuser->username));
			strcpy(new_borrowedbook->currentborroweduser, currentuser->username);
			new_borrowedbook->copies = NULL;
			new_borrowedbook->next = NULL;
			if(add_book(borrowedlist->list, new_borrowedbook)){
				borrowedlist->length ++;
				print("you have borrowed the %s successfully:)", borrowedbook->title);
			} else print("Sorry, you are failed to borrowed the book, please try again:(")
			current->copies --;
			if(current->copies == 0) booklist->length --;
}

void return_a_book(User* currentuser, BookList* booklist, BookList* borrowedlist){
	Book* borrowedlist_current = borrowedlist->list->next;
      printf("id\ttitle\tauthor\tyear\tcopies\n");
	unsigned int option;
//print the borrowed book of this account
      while(borrowedlist_current->next != NULL){
		if(strcmp(borrowedlist_current->currentborroweduser, currentuser->username)) {
			printf("%d\t%s\t%s\t%d\t%d\n",borrowedlist_current->id, borrowedlist_current->title, borrowedlist_current->authors, borrowedlist_current->year, borrowedlist_current->copies);
			borrowedlist_current = borrowedlist_current->next;
		} else borrowedlist_current = borrowedlist_current->next;
	}
	printf("please choose the book that you want to return(input the id):");
	while(1){
		scanf("%d", &option);
		if(option < 0){
			printf("the option is incalid!please re-input:(");
			continue;
		} else {
			borrowedlist_current = borrowedlist->list->next;
			while(borrowedlist_current->id != option && borrowedlist_current->next != NULL){
				borrowedlist_current = borrowedlist_current->borrowedlist_next; //find the chosen book
			}
			break;
		} 
		if(borrowedlist_current->id == option){
			borrowedlist_current->borrowedlist_next->avaliable_statement = 1;
			borrowedlist_current->borrowedlist_next->currentborroweduser = NULL;
			borrowedlist_current = borrowedlist_current->borrowedlist_next;
			borrowedlist_current->borrowedlist_next = NULL;
			borrowedlist->length --;
		} else printf("can not find the book you need, please try again:(");		
}

void search_for_books( BookList* booklist){
    int option;
    char title[40];
    char authors[40];
    unsigned int year;
    printf("how you want to search?Please choose an option:\n");
    printf("1) search by title\n");
    printf("2) search by author\n");
    printf("3) search by year\n");
    pruntf("4) quit\n")
    scanf("%d",&option);
    switch (option) {
        case 1 :           
            printf("please input the title:");
            scanf("%c", title);
            find_book_by_title(booklist->list,title);
        	search_for_books(booklist);
        case 2 :
            printf("please input the authors:");
            scanf("%c", authors);
            find_book_by_author(booklist->list,authors);
        	search_for_books(booklist);
        case 3 :
            printf("please input the year:");
            scanf("%d", &year);
            find_book_by_year(booklist->list, year);
        	search_for_books(booklist);
	  case 4:
		return;
    }

}

void display_all_books(BookList* booklist){
    Book* current = booklist->list->next;
    printf("id\ttitle\tauthor\tyear\tcopies\n");
    while(current->next != NULL){
        printf("%d\t%s\t%s\t%d\t%d\n",current->id, current->title, current->authors, current->year, current->copies);
	  current= current->next;
    		}
	}

