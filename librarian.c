//
// Created by 28262 on 2022/3/7.
//
#include <stdio.h>
#include <stdlib.h>
#include "librarian.h"
#include "book_management.h"
#include "user.h"

void add_a_book(BookList* booklist){
    Book* new_book=(Book *)malloc(sizeof(Book));
    printf("please input the title:");
    scanf("%s",new_book->title);
    printf("please input the author:");
    scanf("%s",new_book->authors);
    printf("please input the year:");
    scanf("%d",new_book->year);
    printf("please input the copies:");
    scanf("%d",new_book->copies);
    if(add_book(booklist->list, new_book) == 0)
    booklist->length ++;
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
