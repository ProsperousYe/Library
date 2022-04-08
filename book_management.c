#include "book_management.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int store_books(FILE *file, BookList *booklist){
	Book* current = booklist->list->next;
	int count = 0;
	while(current != NULL){
		if(count >= booklist->length) break;
		fprintf(file,"%d\n",current->id);
		fprintf(file,"%s\n",current->title);
		fprintf(file,"%s\n",current->authors);
		fprintf(file,"%d\n",current->year);
		fprintf(file,"%d\n",current->copies);
		fprintf(file,"%s\n",current->currentborroweduser);
		current = current->next;
		count++;
	}
	//fclose(file);
}

int load_books(FILE *file, BookList* booklist){
        Book* bp = booklist->list;
        Book* new_book;
        while (1){
		if(feof(file)) break;
		char temp1[100];
		char temp2[100];
		char temp3[100];
		new_book = (Book*)malloc(sizeof(Book));
		//printf("1");
		fscanf(file,"%d\n",&new_book->id);
		fscanf(file,"%s\n",temp1);
		new_book->title = (char *)malloc(strlen(temp1)+1);
		strcpy(new_book->title,temp1);
		fscanf(file,"%s\n",temp2);
		new_book->authors = (char *)malloc(strlen(temp2)+1);
		strcpy(new_book->authors,temp2);
		fscanf(file,"%d\n",&new_book->year);
		fscanf(file,"%d\n",&new_book->copies);
		fscanf(file,"%s\n", temp3);
		new_book->currentborroweduser = (char *)malloc(strlen(temp3)+1);
		strcpy(new_book->currentborroweduser,temp3);		
		//fflush(stdin);
		add_book(booklist,new_book);
		booklist->length++;
	   }
        //fclose(file);
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


int remove_book(BookList* booklist, Book* targetbook){
    Book* current = booklist->list->next;
    Book* previews = booklist->list;
    while(current != NULL){
        if(current != targetbook){
            current = current->next;
            previews = previews->next;
            continue;
        } else {
		previews->next = current->next;
		free((void *)targetbook);
            return 0;
        }
    }
    return 1;
}

void find_book_by_title(Book* booklist, char title[40]){
    Book* current = booklist->next;
    printf("id\t\ttitle\t\tauthor\t\tyear\t\tcopies\n");
    while(current != NULL){
        if(strcmp(current->title,title) == 1){
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
    printf("id\t\ttitle\t\tauthor\t\tyear\t\tcopies\n");
    while(current != NULL){
        if(strcmp(current->authors,authors) == 1){
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
    printf("id\t\ttitle\t\tauthor\t\tyear\t\tcopies\n");
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

void clear(){
	char b;
	do{
		scanf("%c",&b);
	}while(b!='\n');
}
