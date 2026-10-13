#include <stdio.h>
#include "train.h"
/* Check whether train number already exists */
int train_exists(int train_no)
{
    struct Train t;
    FILE *fp;

    fp = fopen("train_info.txt", "r");

    if(fp == NULL)
        return 0;

    while(fscanf(fp, "%d %49s %49s %49s %d",
                 &t.train_no,
                 t.train_name,
                 t.source,
                 t.destination,
                 &t.total_seats) == 5)
    {
        if(t.train_no == train_no)
        {
            fclose(fp);
            return 1;
        }
    }

    fclose(fp);
    return 0;
}
/* Add a new train */
void add_train(void)
{
    struct Train t;
    FILE *fp;
    printf("\n------- ADD TRAIN--------\n");
    printf("Enter train number: ");
   if(scanf("%d", &t.train_no)!=1)
	   return;
    if(train_exists(t.train_no))
    {
        printf("Train number already exists!\n");
        return;
    }
    printf("Enter train name: ");
   if(scanf("%49s", t.train_name)!=1)
    return;
    printf("Enter source: ");
    if(scanf("%49s", t.source)!=1)
     return;	    

    printf("Enter destination: ");
   if(scanf("%49s", t.destination)!=1)
    return;
    printf("Enter total seats: ");
   if(scanf("%d",&t.total_seats)!=1||t.total_seats<=0)
    {
        printf("Invalid number of seats!\n");
        return;
    }

    fp = fopen("train_info.txt", "a");

    if(fp == NULL)
    {
        printf("Unable to open train file!\n");
        return;
    }

    fprintf(fp, "%d %s %s %s %d\n",
            t.train_no,
            t.train_name,
            t.source,
            t.destination,
            t.total_seats);

    fclose(fp);

    printf("\nTrain added successfully!\n");
}

/* Display all available trains */
void display_train()
{
    struct Train t;
    FILE *fp;
    int found = 0;

    fp = fopen("train_info.txt", "r");

    if(fp == NULL)
    {
        printf("\nNo train records found!\n");
        return;
    }
    printf("\n--------------- AVAILABLE TRAINS-------------------\n");
    printf("%-12s %-20s %-15s %-15s %-10s\n",
           "Train No",
           "Train Name",
           "Source",
           "Destination",
           "Seats");
    while(fscanf(fp, "%d %49s %49s %49s %d",
			    &t.train_no, 
			    t.train_name,
			    t.source,
			    t.destination,
			    &t.total_seats) == 5)
    {
        printf("%-12d %-20s %-15s %-15s %-10d\n", t.train_no,t.train_name,t.source,t.destination,t.total_seats);

        found = 1;
    }

    if(!found)
        printf("No train records available!\n");

    fclose(fp);
}

/* Get total seats for a particular train */
int get_train_seats(int train_no)
{
    struct Train t;
    FILE *fp;
    fp = fopen("train_info.txt", "r");

    if(fp == NULL)
        return 0;

    while(fscanf(fp, "%d %49s %49s %49s %d",
                 &t.train_no,
                 t.train_name,
                 t.source,
                 t.destination,
                 &t.total_seats) == 5)
    {
        if(t.train_no == train_no)
        {
            fclose(fp);
            return t.total_seats;
        }
    }

    fclose(fp);
    return 0;
}

void search_train(void)
{
    struct Train t;
    FILE *fp;
    int train_no;
    int found = 0;

    printf("\nEnter train number to search: ");

    if (scanf("%d", &train_no) != 1)
        return;

    fp = fopen("train_info.txt", "r");

    if (fp == NULL)
    {
        printf("No train records found!\n");
        return;
    }

    while (fscanf(fp, "%d %49s %49s %49s %d",
                  &t.train_no,
                  t.train_name,
                  t.source,
                  t.destination,
                  &t.total_seats) == 5)
    {
        if (t.train_no == train_no)
        {
            printf("\nTrain found!\n");
            printf("Train Number: %d\n", t.train_no);
            printf("Train Name: %s\n", t.train_name);
            printf("Source: %s\n", t.source);
            printf("Destination: %s\n", t.destination);
            printf("Total Seats: %d\n", t.total_seats);

            found = 1;
            break;
        }
    }

    if (!found)
        printf("Train not found!\n");

    fclose(fp);
}

