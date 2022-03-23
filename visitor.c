//
// Created by 28262 on 2022/3/7.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "visitor.h"
#include "user.h"
#include "book_management.h"
void register_an_account(UserList* userlist){
    char c_password[100];
    char temp[100];
    while(1){
	    User* currentuser =(User *)malloc(sizeof(User));
	    printf("please input the username:");
	    scanf("%s\n", temp);
	    currentuser->username = (char *)malloc(sizeof(strlen(temp)));
	    strcpy(currentuser->username, temp);
	    printf("please input the password:");
	    scanf("%s\n", temp);
	    currentuser->password = (char *)malloc(sizeof(strlen(temp)));
	    strcpy(currentuser->password, temp);
	    printf("please confirm your password:");
	    scanf("%s\n", c_password);
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
	User* current = userlist->list->next;
	char temp_username[100];
	char temp_password[100];
	printf("please input the username:");
	scanf("%s\n", temp_username);
	printf("please input the password:");
	scanf("%s\n", temp_password);
	while(current->next != NULL){
		if(strcmp(temp_username, current->username) && strcmp(temp_password, current->password)){
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
