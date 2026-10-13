
#include <stdio.h>
#include <string.h>
#include "user.h"
int validate_password(char *password)
{
    int i;
    int upper = 0, lower = 0, digit = 0, special = 0;

    if (strlen(password) < 8)
        return 0;

    for (i = 0; password[i] != '\0'; i++)
    {
        if (password[i] >= 'A' && password[i] <= 'Z')
            upper = 1;
        else if (password[i] >= 'a' && password[i] <= 'z')
            lower = 1;
        else if (password[i] >= '0' && password[i] <= '9')
            digit = 1;
        else
            special = 1;
    }

    if (upper && lower && digit && special)
        return 1;

    return 0;
}

void signup(void)
{
    struct User u, temp;
    FILE *fp;
    int found;

    fp = fopen("users_info.txt", "a+");

    if (fp == NULL)
    {
        printf("File opening failed\n");
        return;
    }

    printf("Enter Username: ");
    scanf("%49s", u.username);

    /* Check username already exists */
    rewind(fp);
    found = 0;

    while (fscanf(fp, "%49s %49s",
                  temp.username, temp.password) == 2)
    {
        if (strcmp(u.username, temp.username) == 0)
        {
            found = 1;
            break;
        }
    }

    if (found)
    {
        printf("Username already exists\n");
        printf("Please enter another username\n");
        fclose(fp);
        return;
    }

    printf("Enter Password: ");
    scanf("%49s", u.password);

    if (validate_password(u.password) == 0)
    {
        printf("Invalid Password\n");
        printf("Password must contain minimum 8 characters,\n");
        printf("uppercase, lowercase, number and special character\n");
        fclose(fp);
        return;
    }

    fprintf(fp, "%s %s\n", u.username, u.password);

    fclose(fp);

    printf("Sign-up successful\n");
}
