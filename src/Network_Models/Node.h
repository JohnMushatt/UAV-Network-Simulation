//
// Created by johnm on 10/15/2019.
//

#ifndef UAV_SIM_NODE_H
#define UAV_SIM_NODE_H

#include "Drones/Base_Drone.h"
#include <memory>
using std::shared_ptr;
class Node {
public:
    Node(const shared_ptr<Base_Drone> &drone);
    /**
     * Flips the activity status of the node
     */
    void flipStatus();
    /**
     * Removes the current drone from the node and returns it
     * @return Current drone at the node
     */
    const shared_ptr<Base_Drone> &removeDrone();
    /**
     * Sets the current drone for the node
     * @param drone Drone to set for the node
     * @return True if succesfully set drone
     */
    bool setDrone(const shared_ptr<Base_Drone> &drone);
private:
    /**
     * Current drone at node
     */
    shared_ptr<Base_Drone> drone;
    /**
     * Activity status
     */
    bool active;
};


#endif //UAV_SIM_NODE_H
