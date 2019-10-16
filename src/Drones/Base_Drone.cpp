//
// Created by johnm on 10/14/2019.
//

#include "Base_Drone.h"

const std::string &Base_Drone::getId() const {
    return id;
}

double Base_Drone::getX() const {
    return x;
}

double Base_Drone::getY() const {
    return y;
}

double Base_Drone::getZ() const {
    return z;
}

bool Base_Drone::isActive() const {
    return active;
}

Base_Drone::Base_Drone(const std::string &id, const std::string &type, double x, double y, double z, bool active) {
    this->id = id;
    this->x = x;
    this->y = y;
    this->z = z;
    this->active = active;
    this->type=type;
}

const std::vector<std::shared_ptr<Mission>> &Base_Drone::getPreviousMissions() const {
    return previous_missions;
}

const std::shared_ptr<Mission> &Base_Drone::getCurrentMission() const {
    return current_mission;
}

std::string Base_Drone::buildPacket(std::shared_ptr<Mission> mission) {
    return nullptr;
}

void Base_Drone::setCurrentMission(const std::shared_ptr<Mission> &currentMission) {
    this->current_mission = currentMission;
}

const std::string &Base_Drone::getType() const {
    return type;
}

