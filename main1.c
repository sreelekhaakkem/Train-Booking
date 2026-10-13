#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"booking.h"
#include"user.h"
#include"train.h"
#include"m.h"
void menu2(void);
void signup(void);
int signin(void);
void display_train(void);
int main()
{
        char ch;
        printf("-------------MENU-1---------------\n");
        printf("1.signup\n 2.signin\n");
        printf("enter the choice\n");
        scanf("%c",&ch);
        switch (ch)
        {
                case'1':signup();
	
                        break;
                case'2':
			signin();
			{

                        menu2();
			}
                        break;
              default:printf("invalid choice\n");
      }
}	
