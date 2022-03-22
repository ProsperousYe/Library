#include "book_management.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int store_books(FILE *file){

}

int load_books(FILE *file){

}

int add_book(Book* booklist, Book* new_book){
    Book* current = booklist->next;
    while(current->next){
        if(current->next != NULL) {
            current = current->next;
            continue;
        } else {
            current = new_book;
            new_book->next = NULL;
            return 0;
        }
    }
    return 1;
}


int remove_book(Book* booklist, Book* targetbook){
    Book* current = booklist->next;
    Book* previews = booklist;
    while(current->next){
        if(current != targetbook){
            current = current->next;
            previews = previews->next;
            continue;
        } else {
		previews = previews->next;
		DeleteNode(targetbook);
            return 0;
        }
    }
    return 1;
}

void find_book_by_title(Book* booklist, char title[40]){
    Book* current = booklist->next;
    printf("id\ttitle\tauthor\tyear\tcopies\n");
    while(current->next){
        if(!strcmp(current->title,title)){
            current = current->next;
            continue;
        } else {
        	printf("%d\t%c\t%c\t%d\t%d\n",current->id, current->title, current->authors, current->year, current->copies);
            continue;
        }
    }
}

void find_book_by_author(Book* booklist, char authors[40]){
    Book* current = booklist->next;
    printf("id\ttitle\tauthor\tyear\tcopies\n");
    while(current->next){
        if(!strcmp(current->authors,authors)){
            current = current->next;
            continue;
        } else {
        	printf("%d\t%c\t%c\t%d\t%d\n",current->id, current->title, current->authors, current->year, current->copies);
            continue;
        }
    }

}

void find_book_by_year(Book* booklist, unsigned int year){
    Book* current = booklist->next;
    printf("id\ttitle\tauthor\tyear\tcopies\n");
    while(current->next){
        if(current->year != year){
            current = current->next;
            continue;
        } else {
        	printf("%d\t%c\t%c\t%d\t%d\n",current->id, current->title, current->authors, current->year, current->copies);
            continue;
        }
    }
}
