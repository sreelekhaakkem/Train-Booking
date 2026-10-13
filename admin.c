#include<stdio.h>
#include<string.h>
#include"user.h"
#include"train.h"
void admin_menu(void)
{
    char choice;

    while(1)
    {
        printf("\n");
        printf("========== ADMIN MENU ==========\n");
        printf("A/a : Add Train\n");
        printf("Q/q : Logout\n");
        printf("Enter your choice: ");

        scanf(" %c", &choice);

        if(choice == 'A' || choice == 'a')
        {
            add_train();
        }
        else if(choice == 'Q' || choice == 'q')
        {
            printf("Admin logout successful.\n");
            break;
        }
        else
        {
            printf("Invalid choice.\n");
        }
    }
  }

