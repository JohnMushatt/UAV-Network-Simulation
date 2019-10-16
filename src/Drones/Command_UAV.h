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

    Command_UAV(std::string id, double x, double y, double z, bool active,
                std::string command_key, std::string rf_in, std::string rf_out);

    /**
     * Adds drone to the sawrm if possible
     * @param drone Drone to add to swarm
     * @return True if succesfully added drone to the swarm
     */
    bool addDrone(const shared_ptr<Base_Drone> &drone);

    /**
     * Returns the current swarm associated with the command uav
     * @return Vector containing shared_ptr<Base_Drone> objects that are
     *         part of the current swarm
     */
    std::vector<shared_ptr<Base_Drone>> &getSwarm();

    /**
     * Send a message to the current swarm
     * Message should propogate to only drones within the current network,
     * however this message will be relayed across the network through other drones
     * if thge target(s) is outside of the swarm
     * @param targets Vector containing target drone(s) to receive message
     * @param mission Mission to give to target drone(s)
     * @return True if message was succesfully delivered
     */
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
