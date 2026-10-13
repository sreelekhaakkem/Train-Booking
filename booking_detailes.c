#include <stdio.h>
#include <string.h>

struct Passenger
{
    int train_number;
    char date[20];
    int seat_number;
    char name[50];
    int age;
    char gender[10];
};

void booking_details()
{
    struct Passenger p;
    FILE *fp;

    int train_number;
    int seat_number;
    int found = 0;
    char date[20];

    printf("\n===== BOOKING DETAILS =====\n");

    printf("Enter train number: ");
    scanf("%d", &train_number);

    printf("Enter journey date (DD-MM-YYYY): ");
    scanf("%19s", date);

    printf("Enter seat number: ");
    scanf("%d", &seat_number);

    fp = fopen("passenger_info", "r");

    if(fp == NULL)
    {
        printf("No booking records found!\n");
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

            printf("\n----- PASSENGER DETAILS -----\n");
            printf("Train Number : %d\n", p.train_number);
            printf("Journey Date : %s\n", p.date);
            printf("Seat Number  : %d\n", p.seat_number);
            printf("Name         : %s\n", p.name);
            printf("Age          : %d\n", p.age);
            printf("Gender       : %s\n", p.gender);
            printf("-----------------------------\n");

            break;
        }
    }

    fclose(fp);

    if(found == 0)
    {
        printf("Booking details not found!\n");
    }
}
