#include <stdio.h>
#include <stdlib.h>
#include "interface.h"
#include "user.h"
#include "book_management.h"

//int role = 0; difine the user role, visitor for 0, user for 1 and admin for 2
//change to user the struct CurrentUser to record the current user info

int main(){
	User* currentuser = (User*)malloc(sizeof(User));
	BookList* booklist = (BookList*)malloc(sizeof(BookList));
	BookList* borrowedlist = (BookList*)malloc(sizeof(BookList));
	UserList* userlist = (UserList*)malloc(sizeof(UserList));
	int login = 0; //initialize
    	interface(currentuser, booklist, borrowedlist, userlist, login);
	free(currentuser); //colsing the system
	free(booklist);
	free(borrowedlist);
	free(userlist);
    	return 0;
}

