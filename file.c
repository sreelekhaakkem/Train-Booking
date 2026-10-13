#include <stdio.h>
#include "file.h"

void save(struct passenger p)
{
    FILE *fp;

    fp = fopen("passenger_info_txt", "a");

    if(fp == NULL)
    {
        printf("File opening failed\n");
        return;
    }

    fprintf(fp, "%d %s %s %d %s %d\n", p.train_no,  p.date, p.name,  p.age,  p.gender, p.seat_number);

    fclose(fp);
}
void syncfile(void)
{
    FILE *fp;
    struct passenger p;

    fp = fopen("passenger_info_txt", "a");

    if (fp == NULL)
    {
        printf("File opening failed\n");
        return;
    }

    while (fread(&p, sizeof(p), 1, fp) == 1)
    {
        printf("\nPassenger Details\n");
        printf("Name   : %s\n", p.name);
        printf("Age    : %d\n", p.age);
        printf("Gender : %s\n", p.gender);
    }

    fclose(fp);
}
