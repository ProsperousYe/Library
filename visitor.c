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
    char temp2[100];
    while(1){
	    User* currentuser =(User *)malloc(sizeof(User));
	    printf("please input the username:");
	    scanf("%s", temp);
	    currentuser->username = (char *)malloc(sizeof(strlen(temp)));
	    strcpy(currentuser->username, temp);
	    printf("please input the password:");
	    scanf("%s", temp2);
	    currentuser->password = (char *)malloc(sizeof(strlen(temp2)));
	    strcpy(currentuser->password, temp2);
	    printf("please confirm your password:");
	    scanf("%s", c_password);
	    if(strcmp(temp2, c_password)){
		printf("the confirm password is not correct, please re-input:(\n");
		free((void *)currentuser);	
		continue;
		} else {
		add_user(userlist, currentuser);
		userlist->length ++;
		printf("Congratuations! The account is created successfully!\n");
		printf("Welcome to this Library system:)\n");
		break;
	}

    }
}


void visitor_login(User* currentuser,UserList* userlist, int login){
	User* current = userlist->list;
	char temp_username[100];
	char temp_password[100];
	printf("please input the username:");
	scanf("%s", temp_username);
	printf("please input the password:");
	scanf("%s", temp_password);
	while(current->next != NULL){
		if((strcmp(temp_username, current->username) == 0) && (strcmp(temp_password, current->password) == 0)){
			printf("login successfully!");				
			currentuser = current;
			login = 1;
			return;
		} else {
			current = current->next;
			continue;		
		}
	}
	printf("Sorry! the username or password may not exsist, please cheak them:(\n");
}
