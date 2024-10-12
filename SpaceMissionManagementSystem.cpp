//
// Created by burka on 11.10.2024.
//

#include "SpaceMissionManagementSystem.h"
#include <string>
#include <iostream>
#include <ostream>

#include "Mission.h"
#include "Spacecraft.h"
using namespace std;

SpaceMissionManagementSystem::SpaceMissionManagementSystem() {

}

SpaceMissionManagementSystem::~SpaceMissionManagementSystem() {
    for(int i = 0; i< missionSize; i++) {
        missions[i].remove();
    }
    delete[] spacecrafts;
    delete[] missions;

}

void SpaceMissionManagementSystem::addMission(const string name, const string launchDate, const string destination) {
    bool isOk = true;
    for (int i = 0; i < missionSize; i++) {
        if (missions[i].getName() == name) {
            cout << "Cannot add mission. Mission " << name << " already exists." << endl;
            isOk = false;
            break;
        }
    }
    if (isOk) {
        Mission *newArray = new Mission[missionSize + 1];
        for (int j = 0; j < missionSize; ++j) {
            newArray[j] = missions[j];
        }
        delete[] missions;
        missions = newArray;
        missionSize += 1;
        missions[missionSize-1] = Mission(name, launchDate, destination);
        cout << "Added mission " << name << "." << endl;
    }
}

void SpaceMissionManagementSystem::removeMission(const string name) {
    for (int i = 0; i < missionSize; i++) {
        if (missions[i].getName() == name) {
            missions[i].setSpacecraftsAvailable();
            //TODO
            //i should create a new array and copy without this element

            Mission *newArray = new Mission[missionSize - 1];
            int k =0;
            for (int j = 0; j < missionSize; ++j) {
                if(missions[j].getName()!=name) {
                    newArray[k] = missions[j];
                    k++;
                }
            }
            delete[] missions;
            missions = newArray;
            missionSize -= 1;
            cout << "Removed mission " << name << "." << endl;
            break;
        }
        if (i == missionSize - 1||missionSize==0) {
            cout << "Cannot remove mission. Mission " << name << " does not exist." << endl;
            break;
        }
    }
}

void SpaceMissionManagementSystem::addSpacecraft(const string name, const string type) {
    bool isOk = true;
    for (int i = 0; i < craftSize; i++) {
        if (spacecrafts[i].getName() == name) {
            cout << "Cannot add spacecraft. Spacecraft " << name << " already exists." << endl;
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
        spacecrafts[craftSize-1] = Spacecraft(name, type);
        cout << "Added spacecraft " << name << "." << endl;
    }
}

void SpaceMissionManagementSystem::removeSpacecraft(const string name) {
    for (int i = 0; i < craftSize; i++) {
        if (spacecrafts[i].getName() == name) {
            if(spacecrafts[i].getIsAvailable()) {
                Spacecraft *newArray = new Spacecraft[craftSize - 1];
                int k =0;
                for (int j = 0; j < craftSize; ++j) {
                    if(spacecrafts[j].getName()!=name) {
                        newArray[k] = spacecrafts[j];
                        k++;
                    }
                }
                delete[] spacecrafts;
                spacecrafts = newArray;
                craftSize -= 1;
                cout << "Removed spacecraft " << name << "." << endl;
            }
            else {
                cout << "Cannot remove spacecraft. Spacecraft "<< name<<" is assigned to a mission. " << endl;
            }
            break;
        }
        if (i == craftSize - 1||craftSize==0) {
            cout << "Cannot remove spacecraft. Spacecraft " << name << " does not exist." << endl;
            break;
        }
    }
}

void SpaceMissionManagementSystem::assignSpacecraftToMission(const string spacecraftName, const string missionName) {
    bool isOk = true;
    for(int i = 0; i<craftSize;i++) {
        if(spacecrafts[i].getName() == spacecraftName&&isOk) {
            if(!spacecrafts[i].getIsAvailable()) {
                //TODO complete the cout
                cout<<"Cannot assign spacecraft. Spacecraft "<< spacecraftName<<" is already assigned to mission"<< "." << endl;
                isOk = false;
            }
            for(int j = 0; j<missionSize && isOk;j++) {
                if(missions[j].getName()==missionName) {
                    spacecrafts[i].setIsAvailable(false);
                    missions[j].addSpacecraft(spacecrafts[i]);
                    isOk = false;
                    break;
                }
                if((j==missionSize - 1||missionSize==0) &&isOk){
                    cout<< "Cannot assign spacecraft. Mission "<< missionName<<" does not exist."<< endl;
                    isOk = false;
                    break;
                }
            }
        }
        if(i==craftSize - 1 &&isOk) {
            cout<< "Cannot assign spacecraft. Spacecraft "<< spacecraftName<<" does not exist."<< endl;
            isOk = false;
            break;
        }
    }
}

void SpaceMissionManagementSystem::dropSpacecraftFromMission(const string spacecraftName) {

}

void SpaceMissionManagementSystem::showAllMissions() const {
    cout << "Missions in the space mission management system:" << endl;
    bool isNull = true;
    for (int i = 0; i < missionSize; i++) {
        if (!missions[i].getName().empty()) {
            isNull = false;
        }
    }
    if (isNull) {
        std::cout << "None" << endl;
    } else {
        for (int i = 0; i < missionSize; i++) {
            if (!missions[i].getName().empty()) {
                cout << "Mission: " << missions[i].getName() << ", Launch Date: " << missions[i].getDate() <<
                        ", Destination: " <<
                        ", Assigned Spacecraft Count: " << missions[i].getCount() << endl;
            }
        }
    }
}

void SpaceMissionManagementSystem::showAllSpacecrafts() const {
    cout << "Spacecrafts in the space mission management system:" << endl;
    bool isNull = true;
    for (int i = 0; i < craftSize; i++) {
        if (!spacecrafts[i].getName().empty()) {
            isNull = false;
        }
    }
    if (isNull) {
        std::cout << "None" << endl;
    } else {
        for (int i = 0; i < craftSize; i++) {
            if (!spacecrafts[i].getName().empty()) {
                cout << "Spacecraft: " << spacecrafts[i].getName() << ", Type: " << spacecrafts[i].getType() <<
                        ", Status: " <<
                        (spacecrafts[i].getIsAvailable() ? "Available" : "Assigned") << endl;
            }
        }
    }
}

void SpaceMissionManagementSystem::showMission(const string name) const {

}

void SpaceMissionManagementSystem::showSpacecraft(const string name) const {

}
