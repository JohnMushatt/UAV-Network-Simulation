//
// Created by johnm on 10/15/2019.
//

#include "Node.h"

Node::Node(const shared_ptr<Base_Drone> &drone) {
    this->drone = drone;
    this->active = false;
}

void Node::flipStatus() {
    this->active = !this->active;
}

const shared_ptr<Base_Drone> &Node::removeDrone() {
    shared_ptr<Base_Drone> drone = this->drone;
    this->drone = nullptr;
}
//TODO Maybe have return type be whatever previous drone was here?
bool Node::setDrone(const shared_ptr<Base_Drone> &drone) {
    this->drone=drone;
}