//
// Created by burka on 11.10.2024.
//

#ifndef SPACECRAFT_H
#define SPACECRAFT_H
#include <string>
using namespace std;
class Spacecraft {
public:
    Spacecraft();
    Spacecraft(string nam, string typ);
    string getName();
    string getType();
    bool getIsAvailable();
    void setIsAvailable(bool boolean);

private:
    string name;
    string type;
    bool isAvailable;

};

#endif //SPACECRAFT_H
