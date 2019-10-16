//
// Created by johnm on 10/14/2019.
//

#ifndef UAV_SIM_BASE_DRONE_H
#define UAV_SIM_BASE_DRONE_H

#include <string>
#include "Missions/Mission.h"
#include <stdlib.h>
#include <utility>
#include <iostream>
#include <exception>
using std::exception;
#include <memory>
using std::shared_ptr;
class Base_Drone {
public:

    Base_Drone(const std::string &id, double x, double y, double z, bool active);

    const std::string &getId() const;

    double getX() const;

    double getY() const;

    double getZ() const;

    bool isActive() const;

    bool setActiveMission(Mission *mission);

    bool removeActiveMission();

    const std::vector<std::shared_ptr<Mission>> &getPreviousMissions() const;

    virtual std::string buildPacket(std::shared_ptr<Mission> mission);
    const std::shared_ptr<Mission> &getCurrentMission() const;

    void setCurrentMission(const std::shared_ptr<Mission> &currentMission);

private:
    std::string id;
    double x, y, z;
    bool active;
    std::shared_ptr<Mission> current_mission;
    std::vector<std::shared_ptr<Mission>> previous_missions;
};


#endif //UAV_SIM_BASE_DRONE_H
