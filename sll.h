#ifndef SLL_H
#define SLL_H

typedef struct Passenger
{
    int train_number;
    char date[20];
    int seat_number;
    char name[50];
    int age;
    char gender[10];

    struct Passenger *next;

} Passenger;

/* Function declarations */
Passenger *create_node(void);

void insert_end(Passenger **head, Passenger *new_node);

void display_list(Passenger *head);

void delete_node(Passenger **head, int seat_number);

void free_list(Passenger *head);

#endif
