#include <stdio.h>

#include "waiting_list.h"

struct Waiting
{
    int train_number;

    char date[20];

    char name[50];

    int age;

    char gender[10];

    int waiting_number;
};

void add_waiting_passenger()
{
    struct Waiting w;

    FILE *fp;

    fp = fopen("waiting_list", "a");

    if(fp == NULL)
    {
        printf("\nUnable to open waiting list file!\n");
        return;
    }

    printf("\nEnter waiting passenger name: ");
    scanf("%49s", w.name);

    printf("Enter age: ");
    scanf("%d", &w.age);

    printf("Enter gender: ");
    scanf("%9s", w.gender);

    printf("Enter train number: ");
    scanf("%d", &w.train_number);

    printf("Enter journey date: ");
    scanf("%19s", w.date);

    printf("Enter waiting number: ");
    scanf("%d", &w.waiting_number);

    fprintf(fp, "%d %s %s %d %s %d\n",
            w.train_number,
            w.date,
            w.name,
            w.age,
            w.gender,
            w.waiting_number);

    fclose(fp);

    printf("\nPassenger added to waiting list.\n");
}

void display_waiting()
{
    struct Waiting w;

    FILE *fp;

    fp = fopen("waiting_list", "r");

    if(fp == NULL)
    {
        printf("\nWaiting list is empty.\n");
        return;
    }

    printf("\n============================================\n");
    printf("              WAITING LIST\n");
    printf("============================================\n");

    while(fscanf(fp, "%d %19s %49s %d %9s %d",
                 &w.train_number,
                 w.date,
                 w.name,
                 &w.age,
                 w.gender,
                 &w.waiting_number) == 6)
    {
        printf("\nWaiting Number : %d\n",
               w.waiting_number);

        printf("Train Number   : %d\n",
               w.train_number);

        printf("Journey Date   : %s\n",
               w.date);

        printf("Name           : %s\n",
               w.name);

        printf("Age            : %d\n",
               w.age);

        printf("Gender         : %s\n",
               w.gender);
    }

    fclose(fp);
}
