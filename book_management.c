#include "book_management.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int store_books(FILE *file, BookList *booklist){
	Book* temp;
	Book* current = booklist->list->next;
	while(current != NULL){
		fprintf(file, "%d\n", current->id);
		fprintf(file, "%s\n", current->title);
		fprintf(file, "%s\n", current->authors);
		fprintf(file, "%d\n", current->year);
		fprintf(file, "%d\n", current->copies);
		fprintf(file, "%s\n", current->currentborroweduser);	
		temp = current->next;
		free((void *)current);
		current = temp;
	}
	return 0;
}

int load_books(FILE *file, BookList* booklist){
	
	while(getc(file) != EOF){
		char title[100];
		char authors[100];
		char currentborroweduser[100];
		Book* new_book = (Book *)malloc(sizeof(Book));
		fscanf(file, "%d\n", &new_book->id);
		fscanf(file, "%s\n", title);
		new_book->title = (char *)malloc(sizeof(strlen(title)));
		strcpy(new_book->title, title);
		fscanf(file, "%s\n", authors);
		new_book->authors = (char *)malloc(sizeof(strlen(authors)));
		strcpy(new_book->authors, authors);
		fscanf(file, "%d\n", &new_book->year);
		fscanf(file, "%d\n", &new_book->copies);
		fscanf(file, "%s\n", currentborroweduser);
		new_book->currentborroweduser = (char *)malloc(sizeof(currentborroweduser));
		strcpy(new_book->currentborroweduser, currentborroweduser);
		add_book(booklist, new_book);
	}
	return 0;
}

int add_book(BookList* booklist, Book* new_book){
    Book* current = booklist->list;
    while(1){
        if(current->next != NULL) {
            current = current->next;
            continue;
        } else {
            current->next = new_book;
            new_book->next = NULL;
            return 0;
        }
    } return 1;
}


int remove_book(Book* booklist, Book* targetbook){
    Book* current = booklist->next;
    Book* previews = booklist;
    while(current != NULL){
        if(current != targetbook){
            current = current->next;
            previews = previews->next;
            continue;
        } else {
		previews = previews->next;
		free((void *)targetbook);
            return 0;
        }
    }
    return 1;
}

void find_book_by_title(Book* booklist, char title[40]){
    Book* current = booklist->next;
    printf("id\ttitle\tauthor\tyear\tcopies\n");
    while(current != NULL){
        if(!strcmp(current->title,title)){
            current = current->next;
            continue;
        } else {
        	printf("%d\t%s\t%s\t%d\t%d\n",current->id, current->title, current->authors, current->year, current->copies);
		current = current->next;
            continue;
        }
    }
}

void find_book_by_author(Book* booklist, char authors[40]){
    Book* current = booklist->next;
    printf("id\ttitle\tauthor\tyear\tcopies\n");
    while(current != NULL){
        if(!strcmp(current->authors,authors)){
            current = current->next;
            continue;
        } else {
        	printf("%d\t%s\t%s\t%d\t%d\n",current->id, current->title, current->authors, current->year, current->copies);
		current = current->next;
            continue;
        }
    }

}

void find_book_by_year(Book* booklist, unsigned int year){
    Book* current = booklist->next;
    printf("id\ttitle\tauthor\tyear\tcopies\n");
    while(current != NULL){
        if(current->year != year){
            current = current->next;
            continue;
        } else {
        	printf("%d\t%s\t%s\t%d\t%d\n",current->id, current->title, current->authors, current->year, current->copies);
		current = current->next;
            continue;
        }
    }
}
