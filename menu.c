#include <stdio.h>
#include "menu.h"
#include "user.h"
#include "train.h"
#include "booking.h"
#include "cancellation.h"
#include "waiting_list.h"

void menu()
{
    int choice;
    int login_status = 0;

    while(1)
    {
      
        printf(------- TRAIN TICKET BOOKING--------\n");

            printf("1. Display Trains\n");
            printf("2. Reserve Ticket\n");
            printf("3. Cancel Ticket\n");
            printf("4. Booking Details\n");
            printf("5. Waiting List\n");
            printf("6. Logout\n");
            printf("7. Exit\n");
        }

        printf("\nEnter choice: ");
        scanf("%d", &choice);
            switch(choice)
            {
                case 1:
                    display_trains();
                    break;

                case 2:
                    book_ticket();
                    break;

                case 3:
                    cancel_ticket();
                    break;

                case 4:
                    booking_details();
                    break;

                case 5:
                    display_waiting();
                    break;

                case 6:
                    login_status = 0;
                    printf("\nLogged out successfully!\n");
                    break;

                case 7:
                    printf("\nThank you!\n");
                    return;

                default:
                    printf("\nInvalid choice!\n");
	    }
