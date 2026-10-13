#ifndef TRAIN_H
#define TRAIN_H

struct Train
{
    int train_number;
    char train_name[50];
    char source[50];
    char destination[50];
    int total_seats;
};

struct SeatInfo
{
    int total_seats;
    int waiting_list;
    int current_booking_seat_number;
};

void add_train();
void display_trains();
int train_exists(int train_number);
int get_train_seats(int train_number);

#endif
