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
    void remove();
    Spacecraft getSpacecrafts(int number);
    Mission(string nam, string dat, string destinatio);
    string getName();
    string getDate();
    string getDestination();
    void addSpacecraft(Spacecraft& spacecraft);
    int getCount();
    void setSpacecraftsAvailable();
private:
    string name;
    string date;
    string destination;
    int craftSize=0;
    Spacecraft* spacecrafts;
};
#endif //MISSION_H
