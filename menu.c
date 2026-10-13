#include <stdio.h>
#include "train.h"
#include "booking.h"
void booking_details(void);
void cancellation(void);
void booking(void);
void menu2(void)
{
    char choice;

    while(1)
    {
        printf("\n---------MENU-2--------\n");
        printf("R/r. Reserve Ticket\n");
        printf("C/c. Cancel Ticket\n");
        printf("B/b. Booking Details\n");
        printf("Q/q.Quit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);
        switch (choice)
        {
            case 'R':
            case 'r':
		    display_train();
		    booking();
                    break;

            case 'C':
            case 'c':
		  display_train();  
                  cancellation();
                  break;

            case 'B':
            case 'b':
                booking_details();
                break;

            case 'Q':
            case 'q':
                printf("Thank you!\n");
                break;

            default:
                printf("Invalid choice!\n");
               
        	}

        
    }

  }   
