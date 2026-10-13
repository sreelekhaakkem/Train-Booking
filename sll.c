
#include <stdio.h>
#include <stdlib.h>
#include "sll.h"

/* Create a new passenger node */
Passenger *create_node(void)
{
    Passenger *new_node;

    new_node = malloc(sizeof(Passenger));

    if (new_node == NULL)
    {
        printf("Memory allocation failed!\n");
        return NULL;
    }

    printf("Enter Train Number: ");
    scanf("%d", &new_node->train_number);

    printf("Enter Date (DD-MM-YYYY): ");
    scanf("%19s", new_node->date);

    printf("Enter Seat Number: ");
    scanf("%d", &new_node->seat_number);

    printf("Enter Passenger Name: ");
    scanf(" %49[^\n]", new_node->name);

    printf("Enter Age: ");
    scanf("%d", &new_node->age);

    printf("Enter Gender: ");
    scanf("%9s", new_node->gender);

    new_node->next = NULL;

    return new_node;
}

/* Insert a passenger at the end of the list */
void insert_end(Passenger **head, Passenger *new_node)
{
    Passenger *temp;

    if (head == NULL || new_node == NULL)
        return;

    new_node->next = NULL;

    if (*head == NULL)
    {
        *head = new_node;
        return;
    }

    temp = *head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = new_node;
}

/* Display all passenger records */
void display_list(Passenger *head)
{
    Passenger *temp = head;

    if (temp == NULL)
    {
        printf("No passenger records found!\n");
        return;
    }

    while (temp != NULL)
    {
        printf("\n----------------------------\n");
        printf("Train Number : %d\n", temp->train_number);
        printf("Date         : %s\n", temp->date);
        printf("Seat Number  : %d\n", temp->seat_number);
        printf("Name         : %s\n", temp->name);
        printf("Age          : %d\n", temp->age);
        printf("Gender       : %s\n", temp->gender);

        temp = temp->next;
    }

    printf("----------------------------\n");
}

/* Delete a passenger using seat number */
void delete_node(Passenger **head, int seat_number)
{
    Passenger *temp;
    Passenger *prev = NULL;

    if (head == NULL || *head == NULL)
    {
        printf("Passenger list is empty!\n");
        return;
    }

    temp = *head;

    while (temp != NULL)
    {
        if (temp->seat_number == seat_number)
        {
            if (prev == NULL)
            {
                *head = temp->next;
            }
            else
            {
                prev->next = temp->next;
            }

            free(temp);
            printf("Passenger deleted successfully!\n");
            return;
        }

        prev = temp;
        temp = temp->next;
    }

    printf("Seat number %d not found!\n", seat_number);
}

/* Free all nodes */
void free_list(Passenger *head)
{
    Passenger *temp;

    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}
