//
// Created by johnm on 10/15/2019.
//

#include "Node.h"

Node::Node(const shared_ptr<Base_Drone> &drone) {
    if (drone.get() == nullptr) {
        throw std::invalid_argument("Drone cannot reference a nullptr");
    } else {
        this->drone = drone;
        this->active = false;
    }
}
const bool Node::getStatus() {
    return this->active;
}
void Node::flipStatus() {
    this->active = !this->active;
}

bool Node::operator==(Node const &obj) {
    if (this->getDrone()->getId() == obj.getDrone()->getId()) {
        return true;
    }
    return false;
}

bool Node::removeDrone() {
    this->drone = nullptr;
    if (this->drone == nullptr) {
        return true;
    }
    return false;
}

//TODO Maybe have return type be whatever previous drone was here?
void Node::setDrone(const shared_ptr<Base_Drone> &drone) {
    this->drone = drone;
}

const shared_ptr<Base_Drone> &Node::getDrone() const {
    return drone;
}
