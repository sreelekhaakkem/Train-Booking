#ifndef USER_H
#define USER_H

struct User
{
    char username[30];
    char password[50];
};

void signup();
int signin();

#endif
