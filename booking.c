#include <stdio.h>
#include <string.h>

#include "booking.h"
#include "train.h"
#include "waiting_list.h"

struct Passenger
{
    int train_number;
    char date[20];

    int seat_number;

    char name[50];
    int age;
    char gender[10];
};

int seat_already_booked(int train_number,
                        char date[],
                        int seat_number)
{
    FILE *fp;
    struct Passenger p;

    fp = fopen("passenger_info", "r");

    if(fp == NULL)
        return 0;

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
            fclose(fp);
            return 1;
        }
    }

    fclose(fp);

    return 0;
}

int find_available_seat(int train_number, char date[])
{
    int total_seats;
    int seat;

    total_seats = get_train_seats(train_number);

    for(seat = 1; seat <= total_seats; seat++)
    {
        if(!seat_already_booked(train_number, date, seat))
        {
            return seat;
        }
    }

    return -1;
}

void book_ticket()
{
    struct Passenger p;

    FILE *fp;

    int number_of_seats;
    int i;
    int seat;

    printf("\n========== RESERVE TICKET ==========\n");

    printf("Enter train number: ");
    scanf("%d", &p.train_number);

    if(!train_exists(p.train_number))
    {
        printf("\nTrain not found!\n");
        return;
    }

    printf("Enter journey date (DD-MM-YYYY): ");
    scanf("%19s", p.date);

    printf("Enter number of seats: ");
    scanf("%d", &number_of_seats);

    if(number_of_seats <= 0)
    {
        printf("\nInvalid number of seats!\n");
        return;
    }

    fp = fopen("passenger_info", "a");

    if(fp == NULL)
    {
        printf("\nUnable to open passenger file!\n");
        return;
    }

    for(i = 0; i < number_of_seats; i++)
    {
        seat = find_available_seat(p.train_number, p.date);

        if(seat == -1)
        {
            printf("\nNo seat available for passenger %d.\n",
                   i + 1);

            printf("Passenger added to waiting list.\n");

            add_waiting_passenger();

            continue;
        }

        p.seat_number = seat;

        printf("\nPassenger %d\n", i + 1);

        printf("Enter name: ");
        scanf("%49s", p.name);

        printf("Enter age: ");
        scanf("%d", &p.age);

        printf("Enter gender (Male/Female): ");
        scanf("%9s", p.gender);

        fprintf(fp, "%d %s %d %s %d %s\n",
                p.train_number,
                p.date,
                p.seat_number,
                p.name,
                p.age,
                p.gender);

        printf("\nSeat %d booked successfully!\n",
               p.seat_number);
    }

    fclose(fp);

    printf("\nBooking completed.\n");
}

void booking_details()
{
    struct Passenger p;

    FILE *fp;

    int train_number;
    char date[20];
    int seat_number;

    int found = 0;

    printf("\n========== BOOKING DETAILS ==========\n");

    printf("Enter train number: ");
    scanf("%d", &train_number);

    printf("Enter journey date: ");
    scanf("%19s", date);

    printf("Enter seat number: ");
    scanf("%d", &seat_number);

    fp = fopen("passenger_info", "r");

    if(fp == NULL)
    {
        printf("\nNo booking information found.\n");
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

            printf("\n-----------------------------\n");
            printf("Train Number : %d\n", p.train_number);
            printf("Date         : %s\n", p.date);
            printf("Seat Number  : %d\n", p.seat_number);
            printf("Name         : %s\n", p.name);
            printf("Age          : %d\n", p.age);
            printf("Gender       : %s\n", p.gender);
            printf("-----------------------------\n");

            break;
        }
    }

    fclose(fp);

    if(!found)
    {
        printf("\nBooking not found!\n");
    }
}
