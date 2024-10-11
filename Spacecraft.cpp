//
// Created by burka on 11.10.2024.
//

#include "Spacecraft.h"

Spacecraft::Spacecraft() {

}

Spacecraft::Spacecraft(string nam, string typ) {
    name = nam;
    type = typ;
    isAvailable = true;
}

string Spacecraft::getName() {
    return name;
}

string Spacecraft::getType() {
    return type;
}
bool Spacecraft::getIsAvailable() {
    return isAvailable;
}
void Spacecraft::setIsAvailable(bool boolean) {
    isAvailable = boolean;
}
