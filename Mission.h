//
// Created by burka on 11.10.2024.
//

#ifndef MISSION_H
#define MISSION_H
#include <string>

#include "Spacecraft.h"
using namespace std;
class Mission {
public:
    Mission();
    Mission(string nam, string dat, string destinatio);
    string getName();
    string getDate();
    string getDestination();
    int getCount();
    void setSpacecraftsAvailable();
private:
    string name;
    string date;
    string destination;
    Spacecraft* spacecrafts;
};
#endif //MISSION_H
