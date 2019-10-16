//
// Created by johnm on 10/15/2019.
//

#include "Network.h"

Network::Network(vector<shared_ptr<Base_Drone>> &drones) {
    this->drones = drones;
}

Network::Network() {

}

bool Network::addNode(const shared_ptr<Node> &node) {
    //Try to add node to vector
    try {
        if (node_list.size() < network_limit) {
            this->node_list.push_back(node);
            std::cout << "Added node!" << std::endl;
            return true;
        } else {
            std::cout << "Network node limit reached" << std::endl;
            return false;
        }
    }
        //Catch exception if we cannot add to it
    catch (exception &e) {
        std::cerr << "Error caught in adding node: " << e.what() << std::endl;
        return false;
    }

}

bool Network::addDrone(const shared_ptr<Base_Drone> &drone) {
    try {
        if (this->drones.size() < network_limit) {
            this->drones.push_back(drone);
            std::cout<<"Succesfully added drone!"<<std::endl;

            return true;
        } else {
            return false;
        }
    }
    catch (exception &e) {
        std::cerr << "Error with adding drone: " << e.what() << std::endl;
    }
}

bool Network::addDrone(const vector<shared_ptr<Base_Drone>> &drone) {
    try {
        if (this->drones.size() + drone.size() < network_limit) {
            for (size_t i = 0; i < drone.size(); i++) {
                this->drones.push_back(drone.at(i));
                std::cout<<"Succesfully added drone!"<<std::endl;
                return true;
            }

        } else {
            return false;
        }
    }
    catch (exception &e) {
        std::cerr << "Error adding list of drone: " << e.what() << std::endl;
    }
}

bool Network::addLink(const shared_ptr<Node> &n1, const shared_ptr<Node> &n2, double weight) {
    //Try to add link between two nodes
    //TODO Check if weight is valid
    //TODO Check if current node can support the additional link
    try {
        shared_ptr<Link> link = std::make_shared<Link>(n1, n2, weight);
        std::cout << "Added link!" << std::endl;
        return true;
    }
    catch (exception &e) {
        std::cout << "Error caught in adding link: " << e.what() << std::endl;
        return false;
    }

}

//TODO Decide how the network model object will influence the network
bool Network::setNetworkModel(shared_ptr<Model> &model) {
    try {
        this->model = model;
        return true;
    }
    catch (exception &e) {
        std::cerr << "Error with setting network model: " << e.what() << std::endl;
        return false;
    }
}

void Network::setNetworkLimit(unsigned int limit) {
    this->network_limit=limit;
}