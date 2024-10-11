//
// Created by burka on 11.10.2024.
//

#include "SpaceMissionManagementSystem.h"

#include <iostream>
#include <ostream>

#include "Mission.h"
#include "Spacecraft.h"

SpaceMissionManagementSystem::SpaceMissionManagementSystem() {
    spacecrafts = new Spacecraft[originalSize]; //CHANGE THIS
    missions = new Mission[originalSize];
}

SpaceMissionManagementSystem::~SpaceMissionManagementSystem() {
    delete[] spacecrafts;
    delete[] missions;
}

void SpaceMissionManagementSystem::addMission(const string name, const string launchDate, const string destination) {
    for(int i = 0; i < originalSize; i++) {

        if(missions[i].getName()==name) {
            cout << "Cannot add mission. Mission "<< name << " already exists." << endl;
            break;
        }
        if(missions[i].getName().empty()) {
            missions[i] = Mission(name, launchDate, destination);
            cout << "Added mission " <<name << "."<< endl;
            break;
        }
    }

}

void SpaceMissionManagementSystem::removeMission(const string name) {
    for(int i = 0; i < originalSize; i++) {
        if(missions[i].getName()==name) {
            missions[i].setSpacecraftsAvailable();
            //TODO
            //i should create a new array and copy without this element
            cout << "Removed mission "<< name << "." << endl;
            break;
        }
        if(i==originalSize-1){
            cout << "Cannot remove mission. Mission "<< name << " does not exist." << endl;
            break;
        }
    }

}

void SpaceMissionManagementSystem::addSpacecraft(const string name, const string type) {
    for(int i = 0; i < originalSize; i++) {
        if(spacecrafts[i].getName()==name) {
            cout << "Cannot add spacecraft. Spacecraft "<< name << " already exists." << endl;
            break;
        }
        if(spacecrafts[i].getName().empty()) {
            spacecrafts[i] = Spacecraft(name, type);
            cout << "Added spacecraft " <<name << "."<< endl;
            break;
        }
    }

}

void SpaceMissionManagementSystem::removeSpacecraft(const string name) {

}

void SpaceMissionManagementSystem::assignSpacecraftToMission(const string spacecraftName, const string missionName) {

}

void SpaceMissionManagementSystem::dropSpacecraftFromMission(const string spacecraftName) {

}

void SpaceMissionManagementSystem::showAllMissions() const {
    cout << "Missions in the space mission management system:" << endl;
    bool isNull = true;
    for(int i = 0; i < originalSize; i++) {
        if(!missions[i].getName().empty()) {
            isNull = false;
        }
    }
    if(isNull) {
        std::cout << "None"<< endl;
    }
    else {
        for(int i = 0; i < originalSize; i++) {
            if(!missions[i].getName().empty()) {
                cout << "Mission: "<<missions[i].getName()<< ", Launch Date: "<< missions[i].getDate() <<", Destination: " <<
                    ", Assigned Spacecraft Count: "<< missions[i].getCount() << endl;
            }
        }
    }
}

void SpaceMissionManagementSystem::showAllSpacecrafts() const {
    cout << "Spacecrafts in the space mission management system:" << endl;
    bool isNull = true;
    for(int i = 0; i < originalSize; i++) {
        if(!spacecrafts[i].getName().empty()) {
            isNull = false;
        }
    }
    if(isNull) {
        std::cout << "None"<< endl;
    }
    else {
        for(int i = 0; i < originalSize; i++) {
            if(!spacecrafts[i].getName().empty()) {
                cout << "Spacecraft: "<<spacecrafts[i].getName()<< ", Type: "<< spacecrafts[i].getType()<< ", Status: "<<
                    (spacecrafts[i].getIsAvailable() ? "Available" :  "Assigned") << endl;
            }
        }
    }
}

void SpaceMissionManagementSystem::showMission(const string name) const {

}

void SpaceMissionManagementSystem::showSpacecraft(const string name) const {

}
