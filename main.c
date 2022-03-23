#include <stdio.h>
#include <stdlib.h>
#include "interface.h"
#include "user.h"
#include "book_management.h"

int main(int argc, char* argv[]){
//four steps to initialize:open files, regisiter for the head pointer, regisiter for the frist empty block and constract the linked lists
	FILE* bookfile                = fopen(argv[1],"w+");			//the first argment is the name of booklist storage
	FILE* userfile                = fopen(argv[2],"w+");			//second is storage the user info
	FILE* loanfile                = fopen(argv[3],"w+");			//third is storage the borrowed info
	User* currentuser             = (User*)malloc(sizeof(User));		//register a space to record the current user info
	BookList* booklist            = (BookList*)malloc(sizeof(BookList));//register a header pointer for the book linked list
	BookList* borrowedlist        = (BookList*)malloc(sizeof(BookList));//register a header pointer for the borrowed book linked list 
	UserList* userlist            = (UserList*)malloc(sizeof(UserList));//register a header pointer for the user linked list
	Book* bookheader              = (Book*)malloc(sizeof(Book));		//register the first empty node for the book linked list
	Book* borrowedheader          = (Book*)malloc(sizeof(Book));		//register the first empty node for the borrowed book linked list
	User* userheader              = (User*)malloc(sizeof(User));		//register the first empty node for the user linked lists
	booklist->list                = bookheader;				//let the head pointer point to the first empty node
	bookheader->next              = NULL;					//let the first empty node next point to NULL, means the end of linked list
	borrowedlist->list            = borrowedheader;
	borrowedheader->borrowedlist_next = NULL;
	userlist->list                = userheader;
	userheader->next              = NULL;
	int login                     = 0;						//initialize the login statement
    	interface(currentuser, booklist, borrowedlist, userlist, login);	//enter the main menu
	fclose(bookfile);									//closing the files
	fclose(userfile);
	fclose(loanfile);	
	free(bookheader);									//free the space of head pionters
	free(borrowedheader);
	free(userheader);
	free(currentuser);								//free the space of linked lists
	free(booklist);
	free(borrowedlist);
	free(userlist);
    	return 0;
}

