//
// Created by burka on 11.10.2024.
//

#include "Mission.h"
#include <iostream>

using namespace std;

Mission::Mission() {
}
void Mission::remove() {
    delete[] spacecrafts;
}
Spacecraft Mission::getSpacecrafts(int number) {
    return spacecrafts[number];
}

Mission::Mission(string nam, string dat, string destinatio) {
    name = nam;
    date = dat;
    destination = destinatio;
    spacecrafts = new Spacecraft[0];
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
    return craftSize;
}

void Mission::setSpacecraftsAvailable() {
    for (int i = 0; i < craftSize; i++) {
        spacecrafts[i].setIsAvailable(true);
    }
}
void Mission::addSpacecraft(Spacecraft& spacecraft) {
    bool isOk = true;
    for (int i = 0; i < craftSize; i++) {
        if (spacecrafts[i].getName() == spacecraft.getName()) {
            cout << "Cannot add spacecraft. Spacecraft " << spacecraft.getName() << " already exists." << endl;
            isOk = false;
            break;
        }
    }
    if (isOk) {
        Spacecraft *newArray = new Spacecraft[craftSize + 1];
        for (int j = 0; j < craftSize; ++j) {
            newArray[j] = spacecrafts[j];
        }
        delete[] spacecrafts;
        spacecrafts = newArray;
        craftSize += 1;
        spacecrafts[craftSize-1] = spacecraft;
        cout<< "original: "<<&spacecraft << endl;
        cout<< "array: "<<&spacecrafts[craftSize-1] << endl; //TODO memory location ayni degil
        cout << "Assigned spacecraft " << spacecraft.getName() <<" to mission "<< name<< "." << endl;
    }
}

