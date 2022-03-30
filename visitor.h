//
// Created by 28262 on 2022/3/7.
//

#ifndef LIBRARY_VISITOR_H
#define LIBRARY_VISITOR_H
#include "user.h"
void register_an_account();

User* visitor_login(User* currentuser,UserList* userlist);

void quit();
#endif //LIBRARY_VISITOR_H
