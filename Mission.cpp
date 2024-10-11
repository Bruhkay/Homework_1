//
// Created by burka on 11.10.2024.
//

#include "Mission.h"

#include <algorithm>
#include <bits/ranges_algo.h>

Mission::Mission() {
}
Mission::Mission(string nam, string dat, string destinatio) {
    name = nam;
    date = dat;
    destination = destinatio;
    spacecrafts = new Spacecraft[50];
}

string Mission::getName() {
    return name;
}

string Mission::getDate() {
    return date;
}

string Mission::getDestination() {
    return destination;
}
int Mission::getCount() {
    int count = 0;
    for (int i = 0; i < 50; i++) {
        if(!spacecrafts[i].getName().empty()) {
            count++;
        }
    }
    return count;
}
void Mission::setSpacecraftsAvailable(){
    for (int i = 0; i < 50; i++) {
        spacecrafts[i].setIsAvailable(true);
    }
}
