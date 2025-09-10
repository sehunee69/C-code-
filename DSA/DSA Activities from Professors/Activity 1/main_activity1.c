#include <stdio.h>
#include "func_activity1.c"

int main() {

    Flights f_list;
    initFList(&f_list);

    Flight f;
    //flight 101
    f = createFlight();
    displayFlightInfo(f);
    addFlight(&f_list, f);
    // flight 102  
    f = createFlight();
    addFlight(&f_list, f);
    showFlights(f_list);

    //add here more flights

    //remove flight 101 
    Flight removed = removeFlight(&f_list, 101);
    printf("---Flight removed---\n");
    displayFlightInfo(removed);
    showFlights(f_list);


}