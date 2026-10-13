 Train Ticket Booking System

 1. Project Description
  The Train Ticket Booking System is a console-based application developed using the C programming language. It allows users to register, log in, book tickets, cancel tickets, and view booking details. The admin  can add train information.

 2. Technologies Used
  Programming Language: C
  Compiler: GCC
  Operating System: Linux
  File Handling: Text files

 3. Features
  User Features
  User Signup
  User Signin
  Reserve Train Tickets
  Cancel Tickets
  View Booking Details
  Display Available Trains

  Admin Features
  Admin Login
  Add Train Details
  Admin Logout

 4. Project Files
   main1.c – Main program
   menu.c – User menu
   signup.c – User registration
   signin.c – User and admin login
   admin.c – Admin menu
   booking.c – Ticket booking
   booking_detailes.c – Booking details
   cancellation.c – Ticket cancellation
   train.c – Train-related functions
   trainbooking.c – Train booking operations
   waiting.c  – Waiting list operations
   validation.c – Input validation
   file.c – File handling
   sll.c – Linked list operations
   user.c – User-related operations
   user.h train.h m.h – Header files

 5. Compilation
   Compile the project using GCC:

    bash
  gcc -o train main1.c menu.c signup.c signin.c booking.c booking_detailes.c trainbooking.c cancellation.c user.c train.c waiting.c validation.c sll.c file.c admin.c


 6. Execution
   Run the program:

    bash
   ./train

 7. Main Menu
  1. Signup
  2. Signin
  3. Exit

 8. User Menu
  R/r – Reserve Ticket
  C/c – Cancel Ticket
  B/b – Booking Details
  Q/q – Quit

 9. Admin Menu
  A/a – Add Train
  Q/q – Logout

 10. Data Storage
  The application stores user, train, and booking information in text files

 11. Conclusion
  This project demonstrates the use of C programming concepts such as functions, structures, file handling, conditional statements, loops, and modular programming to implement a basic train ticket booking system.
