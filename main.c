#define CreateBookNode(p) p=(Book *)malloc(sizeof(Book));
#define CreateUserNode(p) p=(User *)malloc(sizeof(User));
#define DeleteNode(p) free((void *)p);
#include <stdio.h>
#include <stdlib.h>
#include "interface.h"
#include "user.h"
#include "book_management.h"

//int role = 0; difine the user role, visitor for 0, user for 1 and admin for 2
//change to user the struct CurrentUser to record the current user info

int main(){
	CurrentUser* currentuser = (CurrentUser*)malloc(sizeof(CurrentUser));
	Book* booklist = (Book*)malloc(sizeof(Book));
	Book* borrowedlist = (Book*)malloc(sizeof(Book));
	User* userlist = (User*)malloc(sizeof(User));
	int login = 0;
    	interface(currentuser, booklist, borrowedlist, userlist, login);
	free(currentuser);
	free(booklist);
	free(borrowedlist);
	free(userlist);
    	return 0;
}

