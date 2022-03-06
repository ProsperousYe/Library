#include "book_management.h"

int store_books(FILE *file){
    scanf("%s", &nbook);
	//Book ID:
	fprintf(file, "ID:%d\n", );
	//Book Title:
	fprintf(file, "Book Title:%s\n", booktitle);
	fclose(file);
	return 0;
}

int load_books(FILE *file){

}

int add_books(Book book){
    current = book->next;
}


int remove_book(Book book){
    Book* current = library.list->next;
    Book* previews = library.list;
    while(1){
        if(current != book.next){
            current = current->next;
            previews = previews->current;
            continue;
        } else {
            previews = book->next;
            free(book);
            return 0;
        }
    }
    return 1;
}

BookList find_book_by_title(const char *title){
    BookList books;
    Book* current = library.list->next;
    while(1){
        if(current->title != title){
            current = current->next;
            continue;
        } else {
            books.list
        }
    }
    return books;
}

BookList find_book_by_author(const char *title){

}

BookList find_book_by_year(unsigned int year){

}
