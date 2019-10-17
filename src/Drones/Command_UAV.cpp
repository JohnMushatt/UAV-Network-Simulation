//
// Created by johnm on 10/14/2019.
//

#include "Command_UAV.h"

Command_UAV::Command_UAV(const std::string id, const std::string &type,double x, double y, double z, bool active,
                         std::string command_key, std::string rf_in, std::string rf_out) : Base_Drone(id,type, x, y,
                                                                                                       z,
                                                                                                       active) {
    this->command_key = command_key;
    this->rf_in = rf_in;
    this->rf_out = rf_out;
}

std::vector<shared_ptr<Base_Drone>> &Command_UAV::getSwarm() {
    return this->swarm;
}
std::string Command_UAV::buildPacket(std::shared_ptr<Mission> mission) {

}
bool Command_UAV::addDrone(const shared_ptr<Base_Drone> &drone) {
    try {
        this->swarm.push_back(drone);
        std::cout << "Added drone with id: " << drone->getId() << " to command drone: " << this->getId() << std::endl;
        return true;
    }
    catch (exception &e) {
        std::cout << "Error in adding drone to swarm: " << e.what() << std::endl;
        return false;
    }
}

