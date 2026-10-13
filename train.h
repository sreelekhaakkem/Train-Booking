
#ifndef TRAIN_H
#define TRAIN_H
#define TRAIN_NAME_SIZE 50
#define SOURCE_SIZE  30
#define DESTINATION_SIZE 30
#define LOCATION_SIZE 50
struct Train 
{
    int train_no;
    char train_name[TRAIN_NAME_SIZE];
    char source[LOCATION_SIZE];
    char destination[LOCATION_SIZE];
    int total_seats;
    int available_seats;
    int waiting;
    int current_booking_seat_number;
};
int train_exists(int train_no);
void display_train();
void add_train(void);
void search_train(void);

#endif

