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
	    currentuser->role = 0;
	    printf("please input the username:");
	    scanf("%s", temp);
	    currentuser->username = (char *)malloc(sizeof(strlen(temp)+1));
	    strcpy(currentuser->username, temp);
	    printf("please input the password:");
	    scanf("%s", temp2);
	    currentuser->password = (char *)malloc(sizeof(strlen(temp2)+1));
	    strcpy(currentuser->password, temp2);
	    printf("please confirm your password:");
	    scanf("%s", c_password);
	    if(strcmp(temp2, c_password)){
		printf("the confirm password is not correct, please re-input:(\n");
		free((void *)currentuser);	
		continue;
		} else {
		if(add_user(userlist, currentuser) == 0){
			userlist->length ++;
			printf("Congratuations! The account is created successfully!\n");
			printf("Welcome to this Library system:)\n");
			printf("%s",userlist->list->next->next->password);
			break;
		} else {
			printf("register failed:(");
			break;		
		}
	}
    }
	//printf("%s",userlist->list->password);
	//puts(userlist->list->password);
}


User* visitor_login(User* currentuser,UserList* userlist){
	if(userlist->length <= 1){
		printf("please register first!");
	}	
	User* current = userlist->list->next;
	User* admin = (User*)malloc(sizeof(User));
	char temp_username[100];
	char temp_password[100];
	printf("please input the username:");
	scanf("%s", temp_username);
	printf("please input the password:");
	scanf("%s", temp_password);
	while(1) {
		if(current != NULL){
			if((strcmp(current->username, temp_username) == 0 && strcmp(current->password, temp_password) == 0)){
				printf("login successfully!\n");
				return current;
			} else {
				printf("finding...\n");
				current = current->next;
			}
		} else {
			printf("Sorry! the username or password may not exist, please cheak them:(\n");
			return NULL;
		}
	}

}
