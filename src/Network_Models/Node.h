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
    bool removeDrone();

    /**
     * Sets the current drone for the node
     * @param drone Drone to set for the node
     */
    void setDrone(const shared_ptr<Base_Drone> &drone);

    /**
     * Equals operator overload
     * @param obj Objected to check against
     * @return True if this = obj
     */
    bool operator==(Node const &obj);
    bool operator==(const shared_ptr<Node> &obj);

    const shared_ptr<Base_Drone> &getDrone() const;

    const bool getStatus();
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
