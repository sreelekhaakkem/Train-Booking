#include <stdio.h>
#include <string.h>

#include "train.h"

int train_exists(int train_number)
{
    FILE *fp;
    struct Train train;

    fp = fopen("train_info", "r");

    if(fp == NULL)
        return 0;

    while(fscanf(fp, "%d %49s %49s %49s %d",
                 &train.train_number,
                 train.train_name,
                 train.source,
                 train.destination,
                 &train.total_seats) == 5)
    {
        if(train.train_number == train_number)
        {
            fclose(fp);
            return 1;
        }
    }

    fclose(fp);

    return 0;
}

void add_train()
{
    struct Train train;

    FILE *fp;

    printf("\n========== ADD TRAIN ==========\n");

    printf("Enter train number: ");
    scanf("%d", &train.train_number);

    if(train_exists(train.train_number))
    {
        printf("\nTrain number already exists!\n");
        return;
    }

    printf("Enter train name: ");
    scanf("%49s", train.train_name);

    printf("Enter source: ");
    scanf("%49s", train.source);

    printf("Enter destination: ");
    scanf("%49s", train.destination);

    printf("Enter total seats: ");
    scanf("%d", &train.total_seats);

    fp = fopen("train_info", "a");

    if(fp == NULL)
    {
        printf("\nUnable to open train file!\n");
        return;
    }

    fprintf(fp, "%d %s %s %s %d\n",
            train.train_number,
            train.train_name,
            train.source,
            train.destination,
            train.total_seats);

    fclose(fp);

    printf("\nTrain added successfully!\n");
}

void display_trains()
{
    FILE *fp;
    struct Train train;

    fp = fopen("train_info", "r");

    if(fp == NULL)
    {
        printf("\nNo train information available.\n");
        return;
    }

    printf("\n============================================================\n");
    printf("                    AVAILABLE TRAINS\n");
    printf("============================================================\n");

    printf("%-10s %-20s %-15s %-15s %-10s\n",
           "Number",
           "Train",
           "Source",
           "Destination",
           "Seats");

    printf("------------------------------------------------------------\n");

    while(fscanf(fp, "%d %49s %49s %49s %d",
                 &train.train_number,
                 train.train_name,
                 train.source,
                 train.destination,
                 &train.total_seats) == 5)
    {
        printf("%-10d %-20s %-15s %-15s %-10d\n",
               train.train_number,
               train.train_name,
               train.source,
               train.destination,
               train.total_seats);
    }

    fclose(fp);

    printf("============================================================\n");
}

int get_train_seats(int train_number)
{
    FILE *fp;
    struct Train train;

    fp = fopen("train_info", "r");

    if(fp == NULL)
        return 0;

    while(fscanf(fp, "%d %49s %49s %49s %d",
                 &train.train_number,
                 train.train_name,
                 train.source,
                 train.destination,
                 &train.total_seats) == 5)
    {
        if(train.train_number == train_number)
        {
            fclose(fp);
            return train.total_seats;
        }
    }

    fclose(fp);

    return 0;
}
