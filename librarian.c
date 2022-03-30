//
// Created by 28262 on 2022/3/7.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "librarian.h"
#include "book_management.h"
#include "user.h"

void add_a_book(BookList* booklist){
    char temp[100];
    char temp2[100];
    Book* new_book = (Book *)malloc(sizeof(Book));
    printf("\nplease input the id:");
    scanf("%d",&new_book->id);
    printf("\nplease input the title:");
    scanf("%s",temp);
    new_book->title = (char *)malloc(strlen(temp)+1);
    strcpy(new_book->title,temp);
    printf("\nplease input the author:");
    scanf("%s",temp2);
    new_book->authors = (char *)malloc(strlen(temp2)+1);
    strcpy(new_book->authors,temp2);
    printf("\nplease input the year:");
    scanf("%d",&new_book->year);
    printf("\nplease input the copies:");
    scanf("%d",&new_book->copies);
    //new_book->avaliablestatement = 0;
    new_book->currentborroweduser = NULL;
    new_book->next = NULL;
    //new_book->borrowedlistnext = NULL;
    if(add_book(booklist, new_book) == 0) {
	booklist->length ++;
	printf("\nAdd book successfully!");	
    } else printf("\nAdd book failed! please try again:(");
}

void remove_a_book(BookList* booklist){
	const int option;	
	display_all_books(booklist);
	printf("which book you want to remove?(Please choose it by id):");
	while(1){	
		scanf("%d\n", option);
		if(option <= 0 || option > booklist->length){
			printf("invalid option! Please re-input:");
			continue;
		} else {	
			Book* current = booklist->list->next;    
			while(current->id = option){
				if(remove_book(booklist->list, current) == 0){
					printf("you have remove the book successfully:)");
					break;				
				} else {
					printf("Sorry! There is some error when removing the book:(");
					break;
				}
			}
		}
	}
}
