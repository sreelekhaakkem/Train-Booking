#include<stdio.h>
void cancellation(void)
{
    int train_number;
    char date[15];
    int seat_number;
    printf("\nEnter Train Number: ");
    scanf("%d", &train_number);

    printf("Enter Date of Journey: ");
    scanf("%s", date);

    printf("Enter Seat Number: ");
    scanf("%d", &seat_number);
    printf("Ticket cancelled\n");

    /*
       Later:
       1. Open passengers_info
       2. Find train number
       3. Find date
       4. Find seat number
       5. Remove passenger
       6. Update available seats
    */
}
