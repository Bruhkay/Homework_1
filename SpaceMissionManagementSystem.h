//
// Created by burka on 11.10.2024.
//
#ifndef SPACEMISSIONMANAGEMENTSYSTEM_H
#define SPACEMISSIONMANAGEMENTSYSTEM_H
#include <string>

#include "Mission.h"
#include "Spacecraft.h"
using namespace std;
class SpaceMissionManagementSystem {
public:
    SpaceMissionManagementSystem();
    ~SpaceMissionManagementSystem();
    void addMission( const string name, const string launchDate, const string destination );
    void removeMission( const string name );
    void addSpacecraft( const string name, const string type );
    void removeSpacecraft( const string name );
    void assignSpacecraftToMission( const string spacecraftName, const string missionName );
    void dropSpacecraftFromMission( const string spacecraftName );
    void showAllMissions() const;
    void showAllSpacecrafts() const;
    void showMission( const string name ) const;
    void showSpacecraft( const string name ) const;
private:
    int missionSize = 0;
    int craftSize = 0;
    Spacecraft* spacecrafts= new Spacecraft[craftSize]; //CHANGE THIS
    Mission* missions = new Mission[missionSize];

};
#endif //SPACEMISSIONMANAGEMENTSYSTEM_H
