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
            std::cout << "Succesfully added drone!" << std::endl;
            if (drone->getType().compare(std::string("cmd")) == 0) {
                shared_ptr<Command_UAV> cmd = std::shared_ptr<Command_UAV>(static_cast<Command_UAV *>(drone.get()));
                this->cmd_drones.push_back(cmd);
            }

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
                std::cout << "Succesfully added drone!" << std::endl;
            }
            return true;

        } else {
            return false;
        }
    }
    catch (exception &e) {
        std::cerr << "Error adding list of drone: " << e.what() << std::endl;
        return false;
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

void Network::initNetwork() {
    /**
     * Assign nodes to each drone
     */

    for (size_t i = 0; i < this->drones.size(); i++) {
        shared_ptr<Node> node = std::make_shared<Node>(this->drones.at(i));
        node->flipStatus();
        this->node_list.push_back(node);
    }
    for (size_t i = 0; i < this->cmd_drones.size(); i++) {
        /**
         * Get current commander drone
         */
        shared_ptr<Command_UAV> cmdr = this->cmd_drones.at(i);
        /**
         * Get the node for this commander drone
         */
        shared_ptr<Node> cmdr_node = this->findNode(cmdr->getId());
        /**
         * We initially connect all drones part of current commander drone's
         * swarm to it.
         */
        for (size_t j = 0; j < this->drones.size(); j++) {
            /**
             * Black magic static casting!!
             * Not really, static cast current drone to be of type Basic_UAV, since we know the type is right
             * This is most likely violating a major policy of polymorphism/inheritance but not fixing right now!
             */
            if (this->drones.at(j)->getType().compare(std::string("basic_uav")) == 0) {
                //Basic_UAV *uav = static_cast<Basic_UAV *>(this->drones.at(j).get());
                shared_ptr<Basic_UAV> dr = std::static_pointer_cast<Basic_UAV>(this->drones.at(j));
                /**
                 * If we have a drone that is part of the swarm
                 */
                if (dr->getCmdId().compare(cmdr->getId()) == 0) {
                    shared_ptr<Node> drone_node = this->findNode(dr->getId());
                    shared_ptr<Link> link = std::make_shared<Link>(cmdr_node, drone_node, 1 + i + j);
                    link_list.push_back(link);
                    std::cout << "Link between nodes (" << link->getN1()->getDrone()->getId() << ","
                              << link->getN2()->getDrone()->getId() << ") created!" << std::endl;
                }
            }
        }
    }
}

shared_ptr<Node> Network::findNode(const std::string &id) {
    for (size_t i = 0; i < this->node_list.size(); i++) {
        if (this->node_list.at(i)->getDrone()->getId().compare(id) == 0) {
            return this->node_list.at(i);
        }
    }
    return nullptr;
}

/**
 * Displays the current status of the network
 */
void Network::displayNetwork() {


    /**
     * Display command uav status
     */
    using std::cout;
    using std::endl;

    cout << "**********Command drones in the network**********" << endl;
    for (size_t i = 0; i < this->drones.size(); i++) {
        if (this->drones.at(i)->getType().compare(std::string("cmd")) == 0) {
            //Command_UAV *current_drone = static_cast< Command_UAV *>(this->drones.at(i).get());
            shared_ptr<Command_UAV> cmd = std::static_pointer_cast<Command_UAV>(this->drones.at(i));
            cout << "ID: " << cmd->getId() << " | Drones under control: "
                 << std::to_string(cmd->getSwarm().size()) << endl;
        }

    }
    cout << "**********Basic drones in the network**********" << endl;
    for (size_t i = 0; i < this->drones.size(); i++) {
        if (this->drones.at(i)->getType().compare(std::string("basic_uav")) == 0) {
            //Basic_UAV *current_drone = static_cast<Basic_UAV *>(this->drones.at(i).get());
            shared_ptr<Basic_UAV> basic_uav = std::static_pointer_cast<Basic_UAV>(this->drones.at(i));
            cout << "ID: " << basic_uav->getId() << " Current command drone: " << basic_uav->getCmdId()
                 << " | Active status: "
                 << std::to_string(basic_uav->isActive()) << endl;
        }

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
    this->network_limit = limit;
}
//TODO needs to be tested!
bool Network::linkExists(const shared_ptr<Node> &n1, const shared_ptr<Node> &n2) {
    for (size_t i = 0; i < this->link_list.size(); i++) {
        const shared_ptr<Link> link = this->link_list.at(i);
        /**
         * Check if either (Link_n1 == n1 and  Link_n2 == n2) OR (Link_n1 == n2 and Link_n2 == n1)
         */
        if (((link->getN1() == n1) && (link->getN2() == n2)) || ((link->getN1() == n2) && (link->getN2() == n1))) {
            return true;
        }
    }
    return false;
}

void Network::linkDronesToCommander(const vector<shared_ptr<Base_Drone>> &drones) {
    /**
     * Loop through the vector of drones
     */
    for (size_t i = 0; i < drones.size(); i++) {
        /**
         * We assume that the node already exists and the drones
         * only contains non-command_uav objects
         */
        /**
         * Base drone
         */
        shared_ptr<Basic_UAV> drone = std::static_pointer_cast<Basic_UAV>(drones.at(i));
        shared_ptr<Node> drone_node = this->findNode(drone->getId());
        /**
         * Command uav
         */
        shared_ptr<Node> cmd_node = this->findNode(drone->getCmdId());
        shared_ptr<Command_UAV> cmd = std::static_pointer_cast<Command_UAV>(cmd_node->getDrone());
        /**
         * If there currently is no connection to the commander drone
         */
        if (!(this->linkExists(drone_node, cmd_node))) {
            this->addLink(drone_node, cmd_node, i);

        }
    }
}

bool Network::linkSwarm(const vector<shared_ptr<Base_Drone>> &drones) {
    for (size_t i = 0; i < drones.size(); i++) {
        shared_ptr<Base_Drone> current_drone = drones.at(i);

        for (size_t j = 0; j < drones.size(); j++) {
            shared_ptr<Base_Drone> other_drone = drones.at(j);
            if(other_drone) {

            }
        }
    }
}