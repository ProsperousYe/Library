//
// Created by 28262 on 2022/3/7.
//
#include <stdio.h>
#include <stdlib.h>
#include "visitor.h"
#include "user.h"
#include "book_management.h"
void register_an_account(UserList* userlist){
    char c_password[40];
    while(1){
	    User* currentuser =(User *)malloc(sizeof(User));
	    printf("please input the username:");
	    scanf("%c\n", currentuser->username);
	    printf("please input the password:");
	    scanf("%c\n", currentuser->password);
	    printf("please confirm your password:");
	    scanf("%c\n", c_password);
	    if(!strcmp(currentuser->password, c_password)){
		printf("the confirm password is not correct, please re-input:");
		free((void *)currentuser);	
		continue;
		}
	    else {
		User* current = userlist->list->next;
		while(current->next){
			current=current->next;
		} 
		current->next = currentuser;
		currentuser->next = NULL;
		userlist->length ++;
		printf("Congratuations! The account is created success!\n");
		printf("Welcome to this Library system:)");
		break;
	}
    }
     
}

void visitor_login(User* currentuser,UserList* userlist, int login){
	User* current = userlist->list->next;//compare the user imformation!
	printf("please input the username:");
	scanf("%c\n", currentuser->username);
	printf("please input the password:");
	scanf("%c\n", currentuser->password);
	while(current->next){
		if(strcmp(current->username, currentuser->username) && strcmp(current->password, currentuser->password)){
			currentuser = current;
			login = 1;
			return;
		} else {
			current = current->next;
			continue;
		}
	}
	printf("Sorry! the username or password may not exsist, please cheak them:(");
}
