//
// Created by johnm on 10/15/2019.
//

#ifndef UAV_SIM_NETWORK_H
#define UAV_SIM_NETWORK_H

#include "Node.h"
#include "Model.h"
#include "Link.h"
#include "Drones/Base_Drone.h"
#include <iostream>
#include <memory>

using std::shared_ptr;

#include <exception>

using std::exception;

#include <vector>

using std::vector;

class Network {
public:
    Network();

    Network(vector<shared_ptr<Base_Drone>> &drones);

    /**
     * Sets the current network model to a certain type e.g. star, mesh, tree, etc.
     * @return True if succesfully changed network model
     */
    bool setNetworkModel(shared_ptr<Model> &model);

    /**
     * Adds a node to the network
     * @param node Node to add to the network
     * @return True if succesfully added node to network
     */
    bool addNode(const shared_ptr<Node> &node);

    /**
     * Attempts to add a Base_Drone object to the network
     * @param drone Object of type Base_Drone to add
     * @return True if succesfully added object
     */
    bool addDrone(const shared_ptr<Base_Drone> &drone);

    bool addDrone(const vector<shared_ptr<Base_Drone>> &drone);

    /**
     * Adds a link between two existing nodes
     * @param n1 Source node to link
     * @param n2 Target node to link
     * @param weight Link weight
     * @return True if link between n1 and n2 can and was succesfully made
     */
    bool addLink(const shared_ptr<Node> &n1, const shared_ptr<Node> &n2, double weight);

    /**
     * Returns the shortest path between two nodes in the network based on desired search method
     * @param src Node to search FROM
     * @param des Node to search TO
     * @param method Search method to use
     * @return Vector containing in-order list of nodes to travel by. This method will
     *         most likely be mutexed/locked in some way to ensure that computed path is
     *         the most optimzed path at the current time given the search method.
     */
    vector<shared_ptr<Node>> getShortestPath(const shared_ptr<Node> src, const shared_ptr<Node> des, int method);

    /**
     * Updates the network based on new nodes, links, and status of nodes. The update to the network
     * is based on the current network model/policy
     * MESH MODE : Applies the self-healing model to retain connectivity of network
     * TREE MODE : TODO
     * STAR MODE : TODO
     * GRID MODE : TODO
     * @return
     */
    vector<shared_ptr<Node>> updateNetwork();

    /**
     * Sets the network limit for # of drones per command uav
     * @param limit # of drones allowed per command uav
     */
    void setNetworkLimit(unsigned int limit);

private:
    /**
     * node_list contains the current list of nodes within the network. Includes both
     * connected and unconnected nodes.
     */
    vector<shared_ptr<Node>> node_list;
    /**
     * link_list contains the current list of links between all nodes. Includes both
     * connected and unconnected nodes.
     */
    vector<shared_ptr<Link>> link_list;
    /**
     * drones contains the current set of drones handled by the network
     * Objects of type Base_Drone are not gauranteed to be connected to other drones
     */
    vector<shared_ptr<Base_Drone>> drones;
    /**
     * Limit for the # of nodes in the network
     * Can be resized
     */
    unsigned int network_limit;
    /**
     * Model for the network to enforce
     */
    shared_ptr<Model> model;
};


#endif //UAV_SIM_NETWORK_H
