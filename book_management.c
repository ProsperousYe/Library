#include "book_management.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int store_books(FILE *file){

}

int load_books(FILE *file){

}

int add_book(Book book){
    struct Book* current = library.list->next;
    while(1){
        if(current != NULL) {
            current = current->next;
            continue;
        } else {
            current = &book;
            book.next = NULL;
            return 0;
        }
    }
    return 1;
}


int remove_book(Book book){
    struct Book* current = library.list->next;
    struct Book* previews = library.list;
    while(1){
        if(current != book.next){
            current = current->next;
            previews = previews->next;
            continue;
        } else {
            DeleteNode(previews);
            previews = book.next;
            return 0;
        }
    }
    return 1;
}

BookList find_book_by_title(const char *title){
    struct BookList books_title;
    struct Book *book;
    struct Book* current = library.list->next;
    CreatBookNode(books_title.list);
    books_title.list->next = NULL;
    while(current){
        if(!strcmp(current->title,title)){
            current = current->next;
            continue;
        } else {
            CreateBookNode(book);
            book->title = current->title;
            book->authors = current->authors;
            book->copies = current->copies;
            book->id = current->id;
            book->year = current->year;
            book->next = books_title.list->next;
            books_title.list->next = book;
            current = current->next;
            continue;
        }
    }
    return books;
}

BookList find_book_by_author(const char *author){
    struct BookList books_author;
    struct Book *book;
    struct Book* current = library.list->next;
    CreatBookNode(books_author.list);
    books_author.list->next = NULL;
    while(current){
        if(!strcmp(current->author,author)){
            current = current->next;
            continue;
        } else {
            CreateBookNode(book);
            book->title = current->title;
            book->authors = current->authors;
            book->copies = current->copies;
            book->id = current->id;
            book->year = current->year;
            book->next = books_author.list->next;
            books_author.list->next = book;
            current = current->next;
            continue;
        }
    }
    return books;

}

BookList find_book_by_year(unsigned int year){
    struct BookList books_year;
    struct Book *book;
    struct Book* current = library.list->next;
    CreatBookNode(books_year.list);
    books_year.list->next = NULL;
    while(current){
        if(current->year != year){
            current = current->next;
            continue;
        } else {
            CreateBookNode(book);
            book->title = current->title;
            book->authors = current->authors;
            book->copies = current->copies;
            book->id = current->id;
            book->year = current->year;
            book->next = books_year.list->next;
            books_year.list->next = book;
            current = current->next;
            continue;
        }
    }
    return books;
}
