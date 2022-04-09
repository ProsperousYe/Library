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
	User* current = userlist->list->next->next;
	//puts(current->username);
	while(current != NULL){
		//fprintf(file, "%c\n", 'c');
		//puts(userlist->list->next->username);
		fprintf(file, "%s\n", current->username);
		fprintf(file, "%s\n", current->password);
		fprintf(file, "%d\n", current->role);
		//fwrite(current, sizeof(User), 1, file); 
		current = current->next;
	}
	//fclose(file);
	return;
}

void load_users(FILE *file, UserList *userlist){	
	//add other users
	User* new_user;
	while(1){
		if (feof(file)) break;
		new_user =(User *)malloc(sizeof(User));
		char username[100];
		char password[100];
		fscanf(file, "%s\n", username);
		new_user->username = (char *)malloc(sizeof(strlen(username)+1));
		strcpy(new_user->username, username);
		fscanf(file, "%s\n", password);
	      new_user->password = (char *)malloc(sizeof(strlen(password)+1));
	      strcpy(new_user->password, password);
		fscanf(file, "%d\n", &new_user->role);
		add_user(userlist, new_user);
		userlist->length++;
	}
	userlist->length--;
	//fcolse(file);
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
	if(booklist->length == 0){
		printf("the library is empty!");
		return;
	}
      printf("id\t\ttitle\t\tauthor\t\tyear\t\tcopies\n");
      while(current != NULL){
		if(current->copies != 0) {
		  printf("%d\t\t%s\t\t%s\t\t%d\t\t%d\n",current->id, current->title, current->authors, current->year, current->copies);
		  current = current->next;
		} else current = current->next;
	}
	int breaknum;
	char optionstr[100];
	printf("please choose the book that you want to borrow(input the id):");
	do {
		breaknum = 0;
		//clear();
		scanf("%s", &optionstr);
		int i;	
		for(i=0;i<strlen(optionstr);i++){
			if('0' <= optionstr[i] && optionstr[i] <= '9') continue;
			else { 
				printf("the option is invalid! please re-input:");
				breaknum = 1;
				break;
			}
		}
	} while(breaknum == 1);
	//printf("1");
	option = atoi(optionstr);

	Book* borrowedcurrent = borrowedlist->list->next->next;
	while(borrowedcurrent != NULL){
		if(borrowedcurrent->id != option && strcmp(currentuser->username, borrowedcurrent->currentborroweduser) != 0)		
			borrowedcurrent = borrowedcurrent->next;
		else {
			printf("this book you have borrowed!please retuen it at first!");
			return;		
		}
	}
	
	current = booklist->list->next->next;
	while(current != NULL){
		if(current->id != option) current = current->next; //find the chosen book
		else break;
	}
		
//update the statement of the chosen book
	if(current == NULL){
		printf("there is no book has id you input:(");
	} else if(current->id == option && current != NULL){
		printf("1");
		Book* new_borrowedbook = (Book *)malloc(sizeof(Book));
		new_borrowedbook->id = current->id;
		new_borrowedbook->title = (char *)malloc(strlen(current->title));
		strcpy(new_borrowedbook->title, current->title);
		new_borrowedbook->authors = (char *)malloc(strlen(current->authors));
		strcpy(new_borrowedbook->authors, current->authors);
		new_borrowedbook->year = current->year;
		new_borrowedbook->currentborroweduser = (char *)malloc(strlen(currentuser->username));
		strcpy(new_borrowedbook->currentborroweduser, currentuser->username);
		add_book(borrowedlist, new_borrowedbook);
		borrowedlist->length ++;
		current->copies --;
		printf("you have borrowed the %s successfully:)", new_borrowedbook->title);
		sleep(1);
	}

}

void return_a_book(User* currentuser, BookList* booklist, BookList* borrowedlist){
	Book* borrowedlist_current = borrowedlist->list->next;
      printf("id\t\ttitle\t\tauthor\t\tyear\n");
	unsigned int option;
	int number = 0;
      while(borrowedlist_current != NULL){
		if(strcmp(borrowedlist_current->currentborroweduser, currentuser->username) == 0) {
			printf("%d\t\t%s\t\t%s\t\t%d\n",borrowedlist_current->id, borrowedlist_current->title, borrowedlist_current->authors, borrowedlist_current->year);
			borrowedlist_current = borrowedlist_current->next;
			number ++;
		} else borrowedlist_current = borrowedlist_current->next;
	}
	if(number == 0){
		printf("You have not borrowed any book!");
		return;
	} else {
	int breaknum;
	char optionstr[100];
	printf("please choose the book that you want to borrow(input the id):");
	do {
		breaknum = 0;
		//clear();
		scanf("%s", &optionstr);
		int i;	
		for(i=0;i<strlen(optionstr);i++){
			if('0' <= optionstr[i] && optionstr[i] <= '9') continue;
			else { 
				printf("the option is invalid! please re-input:");
				breaknum = 1;
				break;
			}
		}
	} while(breaknum == 1);
	//printf("1");
	option = atoi(optionstr);
	Book* booklist_current = booklist->list->next->next;
	while(booklist_current!= NULL){
		if(booklist_current->id != option) booklist_current = booklist_current->next; //find the chosen book
		else break;
	}	
	if(booklist_current == NULL){
		printf("retrun false, please check the library stroage!");
	} else {
		printf("returning...\n");
		booklist_current->copies++;
		borrowedlist->length--;
		remove_book(borrowedlist,borrowedlist_current);
		printf("return %s successfully!\n", booklist_current->title);
		sleep(2);
	}
	}
}

void search_for_books( BookList* booklist){
    int option;
    char title[40];
    char authors[40];
    unsigned int year;
	system("clear");
    printf("how you want to search?Please choose an option:\n");
    printf("1) search by title\n");
    printf("2) search by author\n");
    printf("3) search by year\n");
    printf("4) quit\n");
    printf("Option:");
    scanf("%d",&option);
	clear();
while(1){
	if(option<1 || option>4){
		printf("invalid input please re-input:");
		scanf("%d",&option);
		clear();	
	} else {
		break;	
	}
}
    switch (option) {
        case 1 :           
            printf("please input the title:");
            scanf("%s", title);
		clear();
            find_book_by_title(booklist->list,title);
        	search_for_books(booklist);
		break;
        case 2 :
            printf("please input the authors:");
            scanf("%s", authors);
		clear();
            find_book_by_author(booklist->list,authors);
        	search_for_books(booklist);
		break;
        case 3 :
            printf("please input the year:");
            scanf("%d", &year);
		clear();
            find_book_by_year(booklist->list, year);
        	search_for_books(booklist);
		break;
	  case 4:
		return;
		break;
    }

}

void display_all_books(BookList* booklist){
    if(booklist->length == 0){
	printf("the library is empty\n");	
	}
	else{
    Book* current = booklist->list->next->next;
    printf("id\t\ttitle\t\tauthor\t\tyear\t\tcopies\n");
    while(current != NULL){
        printf("%d\t\t%s\t\t%s\t\t%d\t\t%d\n",current->id, current->title, current->authors, current->year, current->copies);
	  current = current->next;
    		}
	}
	printf("please input any character to continue...");
	//clear();
	getchar();
	clear();
	}

