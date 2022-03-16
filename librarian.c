//
// Created by 28262 on 2022/3/7.
//
#include <stdio.h>
#include "librarian.h"

void add_a_book(){
    struct Book new_book;
    unsigned int id;
    char *title;
    char *authors;
    unsigned int year;
    unsigned int copies;
    printf("please input the title:");
    scanf("%s",&title);
    printf("please input the author:");
    scanf("%s",&author);
    printf("please input the year:");
    scanf("%d",&year);
    printf("please input the copies:");
    scanf("%d",&copies);
    new_book.title = title;
    new_book.author = author;
    new_book.year = year;
    new_book.copies = copies;
    new_book.id = id;
    add_book(new_book);
}

void remove_a_book(){

}
