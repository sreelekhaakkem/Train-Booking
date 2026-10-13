#include <stdio.h>
#include <string.h>
#include "user.h"
#include"m.h"
void admin_menu(void);
int signin(void)
{
    struct User u, temp;
    FILE *fp;
    int attempt;
    int found;

    for (attempt = 1; attempt <= 3; attempt++)
    {
        found = 0;

        printf("\nEnter Username: ");
        scanf("%s", u.username);

        printf("Enter Password: ");
        scanf("%s", u.password);
	if(strcmp(u.username, "madhu") == 0 &&
           strcmp(u.password, "Madhu@22") == 0)
        {
            printf("\nAdmin login successful!\n");

            admin_menu();

            return 0;
        }
        fp = fopen("users_info.txt", "r");

        if (fp == NULL)
        {
            printf("No users found\n");
            return 0;
        }

        while (fscanf(fp, "%49s %49s",
                      temp.username, temp.password) == 2)
        {
            if (strcmp(u.username, temp.username) == 0 &&
                strcmp(u.password, temp.password) == 0)
            {

                found = 1;
                break;
            }
        }

        fclose(fp);

        if (found)
        {
            printf("\nLogin successful\n");
            return 1;
        }
    printf("\nInvalid username or password\n");    
  
    }

    printf("\nMaximum login attempts reached\n");
 }
