#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interface.h"
#include "user.h"
#include "book_management.h"

int main(int argc, char* argv[]){
//four steps to initialize:open files, regisiter for the head pointer, regisiter for the frist empty block and constract the linked lists
	if(argc != 4 || strcmp(argv[1],"book.txt") != 0 || strcmp(argv[2], "user.txt") != 0 || strcmp(argv[3], "loan.txt") != 0){
		printf("Invalid file name! Please input: book.txt user.txt loan.txt\n");
		return 0;		
	}	
system("touch book.txt");
system("touch user.txt");
system("touch loan.txt");
	FILE* bookfile_p              = fopen(argv[1],"r");			//the first argment is the name of booklist storage
	FILE* userfile_p              = fopen(argv[2],"r");			//second is storage the user info
	FILE* loanfile_p              = fopen(argv[3],"r");			//third is storage the borrowed info
	//if(bookfile_p==NULL) {fclose(bookfile_p);system("touch book.txt");FILE* bookfile_p = fopen(argv[1],"r");}
	//if(userfile_p==NULL) {fclose(userfile_p);system("touch user.txt");FILE* userfile_p = fopen(argv[2],"r");}
	//if(loanfile_p ==NULL) {fclose(loanfile_p);system("touch loan.txt");FILE* loanfile_p = fopen(argv[3],"r");}
	User* currentuser             = (User*)malloc(sizeof(User));		//register a space to record the current user info
	BookList* booklist            = (BookList*)malloc(sizeof(BookList));//register a header pointer for the book linked list
	BookList* borrowedlist        = (BookList*)malloc(sizeof(BookList));//register a header pointer for the borrowed book linked list 
	UserList* userlist            = (UserList*)malloc(sizeof(UserList));//register a header pointer for the user linked list
	Book* bookheader              = (Book*)malloc(sizeof(Book));		//register the first empty node for the book linked list
	Book* borrowedheader          = (Book*)malloc(sizeof(Book));		//register the first empty node for the borrowed book linked list
	User* userheader              = (User*)malloc(sizeof(User));		//register the first empty node for the user linked lists
	booklist->list                = bookheader;
	userlist->list		     = userheader;				//let the head pointer point to the first empty node
	bookheader->next              = NULL;					//let the first empty node next point to NULL, means the end of linked list
	borrowedlist->list            = borrowedheader;
	borrowedheader->next	     = NULL;
	userheader->next              = NULL;
	booklist->length		     = 0;
	borrowedlist->length	     = 0;	
	currentuser			     = NULL;					//initialize the login statement
	User* admin			     = (User*)malloc(sizeof(User));
	char adminstr[10] = "admin";				
	admin->username = (char *)malloc(sizeof(adminstr));
	admin->password = (char *)malloc(sizeof(adminstr));
	strcpy(admin->username, adminstr);
	strcpy(admin->password, adminstr);
	admin->role = 1;
	add_user(userlist, admin);
	userlist->length		     = 1;
	printf("loading books...\n");
	load_books(bookfile_p, booklist);
	printf("loading borrowed books...\n");
	load_books(loanfile_p, borrowedlist);
	load_users(userfile_p, userlist);
	fclose(bookfile_p);									//closing the files
	fclose(userfile_p);
	fclose(loanfile_p);

    	interface(currentuser, booklist, borrowedlist, userlist);

	FILE* bookfile                = fopen(argv[1],"w");			//the first argment is the name of booklist storage
	FILE* userfile                = fopen(argv[2],"w");			//second is storage the user info
	FILE* loanfile                = fopen(argv[3],"w");
	store_books(bookfile, booklist);
	store_books(loanfile, borrowedlist);
	store_users(userfile, userlist);
	fclose(bookfile);									//closing the files
	fclose(userfile);
	fclose(loanfile);
	booklist->list = NULL;
	borrowedlist->list = NULL;
	userlist->list = NULL;
	free((void *)bookheader);									//free the space of head pionters
	free((void *)borrowedheader);
	free((void *)userheader);
	free((void *)currentuser);	
	printf("exist successfully! Bye-bye:)\n");						//free the space of linked lists
	system("pause");
	system("clear");
    	return 0;
}

