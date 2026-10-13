#include <stdio.h>
#include <string.h>

#include "cancellation.h"

struct CancelPassenger
{
    int train_number;
    char date[20];

    int seat_number;

    char name[50];
    int age;
    char gender[10];
};

void cancel_ticket()
{
    struct CancelPassenger p;

    int train_number;
    char date[20];
    int seat_number;

    int found = 0;

    FILE *fp;
    FILE *temp;

    printf("\n========== CANCEL TICKET ==========\n");

    printf("Enter train number: ");
    scanf("%d", &train_number);

    printf("Enter journey date: ");
    scanf("%19s", date);

    printf("Enter seat number: ");
    scanf("%d", &seat_number);

    fp = fopen("passenger_info", "r");

    if(fp == NULL)
    {
        printf("\nNo passenger information found.\n");
        return;
    }

    temp = fopen("temp_passenger", "w");

    if(temp == NULL)
    {
        printf("\nUnable to create temporary file.\n");
        fclose(fp);
        return;
    }

    while(fscanf(fp, "%d %19s %d %49s %d %9s",
                 &p.train_number,
                 p.date,
                 &p.seat_number,
                 p.name,
                 &p.age,
                 p.gender) == 6)
    {
        if(p.train_number == train_number &&
           strcmp(p.date, date) == 0 &&
           p.seat_number == seat_number)
        {
            found = 1;

            printf("\nPassenger %s cancelled.\n",
                   p.name);

            continue;
        }

        fprintf(temp, "%d %s %d %s %d %s\n",
                p.train_number,
                p.date,
                p.seat_number,
                p.name,
                p.age,
                p.gender);
    }

    fclose(fp);
    fclose(temp);

    remove("passenger_info");

    rename("temp_passenger", "passenger_info");

    if(found)
    {
        printf("\nTicket cancelled successfully!\n");
        printf("Seat %d is now available.\n",
               seat_number);
    }
    else
    {
        printf("\nBooking not found!\n");
    }
}
