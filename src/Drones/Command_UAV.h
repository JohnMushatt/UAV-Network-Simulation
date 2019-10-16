//
// Created by johnm on 10/14/2019.
//

#ifndef UAV_SIM_COMMAND_UAV_H
#define UAV_SIM_COMMAND_UAV_H

/**
 * Command uav acts as a central server for a swarm of various drones
 * Opens a port and communications with local drones which will be
 * referred to as nodes.
 */
#include "Base_Drone.h"
//#include <boost/asio.hpp>

class Command_UAV : public Base_Drone {
public:

    Command_UAV( std::string id, double x, double y, double z, bool active,
                std::string command_key, std::string rf_in, std::string rf_out);

    bool addDrone(const shared_ptr<Base_Drone> &drone);



    bool issueOrder(std::vector<shared_ptr<Base_Drone>> targets, shared_ptr<Mission> mission);
private:
    //Special key for verifying order
    std::string command_key;
    //Radio frequency to receive
    std::string rf_in;
    //Radio frequency to send
    std::string rf_out;
    //Drones under command
    std::vector<std::shared_ptr<Base_Drone>> swarm;
};


#endif //UAV_SIM_COMMAND_UAV_H
