//
// Created by 28262 on 2022/3/7.
//
#include "book_management.h"
#include "user.h"
#include "visitor.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void store_users(FILE *file, UserList *userlist){
		User* temp = NULL;
		User* current = userlist->list->next;
		puts(userlist->list->next->password);
	while(current != NULL){
		fprintf(file, "%s\n", current->username);
		fprintf(file, "%s\n", current->password);
		fprintf(file, "%d\n", current->role);
		temp = current->next;
		free((void *)current);
		current = temp;
	}
	return;
}

void load_users(FILE *file, UserList *userlist){
	while(getc(file) != EOF){
		User* new_user=(User *)malloc(sizeof(User));
		char username[100];
		char password[100];
		fscanf(file, "%s\n", username);
		new_user->username = (char *)malloc(sizeof(strlen(username)));
		strcpy(new_user->username, username);
		fscanf(file, "%s\n", password);
		new_user->password = (char *)malloc(sizeof(strlen(password)));
		strcpy(new_user->password, password);
		fscanf(file, "%d\n", &new_user->role);
		add_user(userlist, new_user);
	}
	return;
}

int add_user(UserList *userlist, User *new_user){
    User* current = userlist->list;
    while(1){
        if(current->next != NULL) {
            current = current->next;
            continue;
        } else {
            current->next = new_user;
            new_user->next = NULL;
            return 0;
        }
    } return 1;
}

void borrow_a_book(User* currentuser, BookList* booklist, BookList* borrowedlist){
	Book* current = booklist->list;
	Book* borrowed_current = borrowedlist->list;
	unsigned int option;
//print out the available books
      printf("id\ttitle\tauthor\tyear\tcopies\n");
      while(current != NULL){
		if(current->copies != 0) {
		  printf("%d\t%s\t%s\t%d\t%d\n",current->id, current->title, current->authors, current->year, current->copies);
		   current = current->next;
		} else current = current->next;
	}
	printf("please choose the book that you want to borrow(input the id):");
	scanf("%d", &option);
	while(1) {
		if(option < 0){
			printf("the option is invalid! please re-input:(");
			scanf("%d", &option);
			continue;
		} else break;
	}
			current = booklist->list;
			while(current->id != option)
				current = current->next; //find the chosen book
//update the statement of the chosen book
			Book* new_borrowedbook = (Book *)malloc(sizeof(Book));
			new_borrowedbook->id = current->id;
			new_borrowedbook->title = (char *)malloc(strlen(current->title));
			strcpy(new_borrowedbook->title, current->title);
			new_borrowedbook->authors = (char *)malloc(strlen(current->authors));
			strcpy(new_borrowedbook->authors, current->authors);
			new_borrowedbook->year = current->year;
			new_borrowedbook->currentborroweduser = (char *)malloc(strlen(currentuser->username));
			strcpy(new_borrowedbook->currentborroweduser, currentuser->username);
			new_borrowedbook->next = NULL;
			if(add_book(borrowedlist, new_borrowedbook) == 0){
				borrowedlist->length ++;
				current->copies --;
				if(current->copies == 0) booklist->length --;
				printf("you have borrowed the %s successfully:)", new_borrowedbook->title);
			} else printf("Sorry, you are failed to borrowed the book, please try again:(");
}

void return_a_book(User* currentuser, BookList* booklist, BookList* borrowedlist){
	Book* borrowedlist_current = borrowedlist->list->next;
      printf("id\ttitle\tauthor\tyear\tcopies\n");
	unsigned int option;
      do{
		if(strcmp(borrowedlist_current->currentborroweduser, currentuser->username)) {
			printf("%d\t%s\t%s\t%d\t%d\n",borrowedlist_current->id, borrowedlist_current->title, borrowedlist_current->authors, borrowedlist_current->year, borrowedlist_current->copies);
			borrowedlist_current = borrowedlist_current->next;
		} else borrowedlist_current = borrowedlist_current->next;
	}while(borrowedlist_current != NULL);
	printf("please choose the book that you want to return(input the id):");
	scanf("%d", &option);
	while(1){
		if(option < 0){
			printf("the option is incalid!please re-input:(");
			scanf("%d", &option);
			continue;
		} else {
			borrowedlist_current = borrowedlist->list;
			while(borrowedlist_current->id != option && borrowedlist_current != NULL){
				borrowedlist_current = borrowedlist_current->next; //find the chosen book
			}
			break;
		} 
		if(borrowedlist_current->next->id == option){
			free((void *)borrowedlist_current);
			
		} else printf("can not find the book you need, please try again:(");		
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
    printf("4) quit\n");
    printf("Option:");
    scanf("%d",&option);
    switch (option) {
        case 1 :           
            printf("please input the title:");
            scanf("%s", title);
            find_book_by_title(booklist->list,title);
        	search_for_books(booklist);
		break;
        case 2 :
            printf("please input the authors:");
            scanf("%s", authors);
            find_book_by_author(booklist->list,authors);
        	search_for_books(booklist);
		break;
        case 3 :
            printf("please input the year:");
            scanf("%d", &year);
            find_book_by_year(booklist->list, year);
        	search_for_books(booklist);
		break;
	  case 4:
		return;
		break;
    }

}

void display_all_books(BookList* booklist){
    Book* current = booklist->list->next;
    printf("id\ttitle\tauthor\tyear\tcopies\n");
    while(current != NULL){
        printf("%d\t%s\t%s\t%d\t%d\n",current->id, current->title, current->authors, current->year, current->copies);
	  current= current->next;
    		}
	}

