//
// Created by johnm on 10/14/2019.
//

#include "Command_UAV.h"

Command_UAV::Command_UAV(std::string id, double x, double y, double z, bool active,
                         std::string command_key, std::string rf_qin, std::string rf_out) : Base_Drone(id, x, y,
                                                                                                              z,
                                                                                                              active) {
    this->command_key=command_key;
    this->rf_in=rf_in;
    this->rf_out=rf_out;
}
bool Command_UAV::addDrone(const shared_ptr<Base_Drone> &drone) {
    try {
        this->swarm.push_back(drone);
        return true;
    }
    catch (exception &e) {
        std::cout << "Error in adding drone to swarm: " << e.what() << std::endl;
        return false;
    }

}
