#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "header_activity1.h"

void initFList(Flights *l) {

    l->flights = malloc(sizeof(Flight));
    l->count = 0;
    l->max = 1;
}

Flight createFlight() {

    Flight f;

    printf("Flight ID: ");
    scanf("%d", &f.id);

    printf("Input Origin: ");
    scanf("%s", f.origin);

    printf("Input destination: ");
    scanf("%s", f.destination);

    int hrs, min;
    //time
    printf("Enter departure time: HH:MM ");
    scanf("%d %d", &hrs, &min);
    f.departure_time = createTime(hrs, min);
    //arrival
    printf("Enter arrival time: ");
    scanf("%d %d", &hrs, &min);
    f.arrival_time = createTime(hrs, min);

    return f;
}
void addFlight(Flights *flight_list, Flight f) {

    if(flight_list->count == flight_list->max) {
        flight_list->max *= 2;
        flight_list->flights = realloc(flight_list->flights, flight_list->max * sizeof(Flight));
    } 

    flight_list->flights[flight_list->count++] = f;

}
Flight removeFlight(Flights *flightlist, int flightid) {

    for(int i = 0; i < flightlist->count; i++) {
        if(flightlist->flights[i].id == flightid) {
            Flight removedFlight = flightlist->flights[i];

            for(int j = i; j < flightlist->count - 1; j++) {
                flightlist->flights[j] = flightlist->flights[j + 1];
            }
            flightlist->count--;
            return removedFlight;
        }
    }
    Flight notFound = {.id = -1};
    return notFound;
}
void showFlights(Flights flight_list) {

    printf("%30s\n", "FLIGHT DEPARTURES");
printf("%-5s | %-15s | %-15s | %-12s | %-12s\n",
       "ID", "ORIGIN", "DESTINATION", "DEPART", "ARRIVAL");

for (int i = 0; i < flight_list.count; i++) {
    printf("%-5d | %-15s | %-15s |",
           flight_list.flights[i].id,
           flight_list.flights[i].origin,
           flight_list.flights[i].destination
    );

    displayTime(flight_list.flights[i].departure_time);
    printf("\t  ");
    displayTime(flight_list.flights[i].arrival_time);
    printf("\n");
}

}
void displayFlightInfo(Flight f) {

        printf("%30s\n", "FLIGHT 1");
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
