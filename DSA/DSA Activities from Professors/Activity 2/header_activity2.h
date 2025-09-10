#ifndef HEADER_ACTIVITY2_H_INCLUDED
#define HEADER_ACTIVITY2_H_INCLUDED

#define STACK_SIZE 5

typedef struct {
    int hours;
    int minutes;
} Time;

typedef struct {
    int id;
    char origin[50];
    char destination[50];
    Time departure_time;
    Time arrival_time;
} Flight;

typedef struct {
    Flight stack[STACK_SIZE];
    int top;
} FlightStack;

void initStack(FlightStack *s);
int isStackEmpty(FlightStack s);
int isStackFull(FlightStack s);
void pushFlight(FlightStack *s, Flight f);
Flight popFlight(FlightStack *s);
Flight peekFlight(FlightStack s);
void displayTime(Time t);
Time createTime(int h, int m);
void displayFlightInfo(Flight f);
void showFlights(FlightStack flight_list);

#endif