#include <stdio.h>
#include "func_activity2.c"

int main() {

    FlightStack fs;
    initStack(&fs);

    Flight f[] = {1, "Alaska", "New York", {10, 00}, {14, 30},
                    2, "New York", "Alaska", {12, 30}, {16, 00},
                    3, "Japan", "Singapore", {14, 30}, {18, 00},
                    4, "Philippines", "New Zealand", {16, 00}, {20, 30},
                    5, "Germany", "Japan", {18, 00}, {22, 30}
                };

    for(int i = 0; i < 5; i++) {
        pushFlight(&fs, f[i]);
    }
    
    
    Flight removed = popFlight(&fs);
    displayFlightInfo(removed);
    
    Flight top = peekFlight(fs);
    displayFlightInfo(top);

    return 0;
}