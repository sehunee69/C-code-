#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "header_activity2.h"

void initStack(FlightStack *s) {
    s->top = -1;
}
int isStackEmpty(FlightStack s) {
    return (s.top == -1) ? 1 : 0;
}
int isStackFull(FlightStack s) {
    return (s.top == STACK_SIZE -1) ? 1 : 0;
}
void pushFlight(FlightStack *s, Flight f) {
    
    if(!isStackFull(*s)) {
        s->stack[++s->top] = f;
    }
    printf("%30s\n", "FLIGHT ADDED");
    displayFlightInfo(f);
}
Flight popFlight(FlightStack *s) {
    
    if(!isStackEmpty(*s)) {
        Flight removed = s->stack[s->top];
        s->top--;
        printf("%30s\n", "FLIGHT REMOVED");
        return removed;
    }
    
    Flight notFound = {.id = -1};
    return notFound;
}
Flight peekFlight(FlightStack s) {

    printf("%30s\n", "TOP FLIGHT");
    return s.stack[s.top];
}

void showFlights(FlightStack flight_list) {

    printf("%30s\n", "FLIGHT DEPARTURES");
printf("%-5s | %-15s | %-15s | %-12s | %-12s\n",
       "ID", "ORIGIN", "DESTINATION", "DEPART", "ARRIVAL");

for (int i = 0; i < flight_list.top; i++) {
    printf("%-5d | %-15s | %-15s |",
           flight_list.stack[i].id,
           flight_list.stack[i].origin,
           flight_list.stack[i].destination
    );

    displayTime(flight_list.stack[i].departure_time);
    printf("\t  ");
    displayTime(flight_list.stack[i].arrival_time);
    printf("\n");
}

}
void displayFlightInfo(Flight f) {

printf("%-5s | %-15s | %-15s | %-12s | %-12s\n",
       "ID", "ORIGIN", "DESTINATION", "DEPART", "ARRIVAL");

    printf("%-5d | %-15s | %-15s | %02d:%02d        | %02d:%02d\n",
           f.id,
           f.origin,
           f.destination,
           f.departure_time.hours,
           f.departure_time.minutes,
           f.arrival_time.hours,
           f.arrival_time.minutes);

}
void displayTime(Time t) {
    char meridian[3] = "AM";
    int hour = t.hours;

    if (hour >= 12) {
        meridian[0] = 'P';
        if (hour > 12) hour -= 12;
    } else if (hour == 0) {
        hour = 12;
    }

    printf("%02d:%02d %s", hour, t.minutes, meridian);
}

Time createTime(int h, int m) {

    Time t;
    t.hours = h;
    t.minutes = m;

    return t;
}