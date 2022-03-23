//
// Created by 28262 on 2022/3/7.
//
#include "book_management.h"
#include "user.h"
#include "visitor.h"
#include <stdio.h>

void borrow_a_book(User* currentuser, BookList* booklist, BookList* borrowedlist){
	Book* head_borrowed;
	Book* current = booklist->list->next;
	Book* borrowed_current = borrowedlist->list->borrowedlist_next;
	unsigned int option;
//print out the available books
      printf("id\ttitle\tauthor\tyear\tcopies\n");
      while(current->next){
		if(current->avaliable_statement == 1)
		printf("%d\t%c\t%c\t%d\t%d\n",current->id, current->title, current->authors, current->year, current->copies);
		else
		  current = current->next;
	}
	printf("please choose the book that you want to borrow(input the id):");
	while(1){
		scanf("%d", &option);
		if(option < 0 || option > borrowedlist->length){
			printf("the option is incalid!please re-input:(");
			continue;
		} else {
			current = booklist->list->next;
			break;
		}
	}	
			while(current->id = option){
				current = current->next; //find the chosen book
			}
//update the statement of the chosen book
			while(borrowed_current->next){
				borrowed_current = borrowed_current->borrowedlist_next; 
			}
			borrowed_current->next = current;
			current->borrowedlist_next = NULL;
			current->avaliable_statement = 0;
			borrowedlist->length ++;
//update the borrowed history of the chosen book
			User* current_borrowed_user = current->borroweduserlist->list->next;
			while(current_borrowed_user->next){
				current_borrowed_user = current_borrowed_user->next;			
			}
			current_borrowed_user->next = currentuser;
			current->borroweduserlist->length ++;
			
}

void return_a_book(User* currentuser, BookList* booklist, BookList* borrowedlist){
	Book* borrowedlist_current = borrowedlist->list->next;
      printf("id\ttitle\tauthor\tyear\tcopies\n");
	unsigned int option;
	User* current_borroweduserlist = borrowedlist_current->borroweduserlist->list->next;
	while(current_borroweduserlist->next){
		current_borroweduserlist=current_borroweduserlist->next;
	}
      while(borrowedlist_current->next){
		if(strcmp(current_borroweduserlist->username, currentuser->username))
			printf("%d\t%c\t%c\t%d\t%d\n",borrowedlist_current->id, borrowedlist_current->title, borrowedlist_current->authors, borrowedlist_current->year, borrowedlist_current->copies);
		else
		  	borrowedlist_current = borrowedlist_current->next;
	}
	printf("please choose the book that you want to return(input the id):");
	while(1){
		scanf("%d", &option);
		if(option < 0){
			printf("the option is incalid!please re-input:(");
			continue;
		}
		else {
			borrowedlist_current = borrowedlist->list->borrowedlist_next;
			while(borrowedlist_current->borrowedlist_next->id = option){
				borrowedlist_current = borrowedlist_current->borrowedlist_next; //find the chosen book
			}
			break;
		}
		borrowedlist_current->borrowedlist_next->avaliable_statement = 1;
		borrowedlist_current->borrowedlist_next = NULL;
		borrowedlist->length --;
}
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
    scanf("%d",&option);
    switch (option) {
        case 1 :           
            printf("please input the title:");
            scanf("%c", title);
            find_book_by_title(booklist->list,title);
        
        case 2 :
            printf("please input the authors:");
            scanf("%c", authors);
            find_book_by_author(booklist->list,authors);
        
        case 3 :
            printf("please input the year:");
            scanf("%d", &year);
            find_book_by_year(booklist->list, year);
        
    }

}

void display_all_books(BookList* booklist){
    Book* current = booklist->list->next;
    printf("id\ttitle\tauthor\tyear\tcopies\n");
    while(current->next){
        printf("%d\t%c\t%c\t%d\t%d\n",current->id, current->title, current->authors, current->year, current->copies);
	  current= current->next;
    		}
	}

