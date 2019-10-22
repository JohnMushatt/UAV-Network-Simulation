//
// Created by johnm on 10/18/2019.
//

#include "gtest/gtest.h"
#include "Network_Models/Link.h"
#include "Network_Models/Node.h"
#include "Drones/Basic_UAV.h"
#include "Drones/Base_Drone.h"
#include "Network_Models/Network.h"
#include <memory>

using std::shared_ptr;

#include <vector>

using std::vector;

class Networks_Test : public ::testing::Test {
protected:
    vector<shared_ptr<Base_Drone>> base_drones;
    vector<shared_ptr<Command_UAV>> cmd_drones;
    vector<shared_ptr<Link>> links;
    vector<shared_ptr<Node>> nodes;
    unsigned int limit_low = 5;
    unsigned int limit_high = 100;
    shared_ptr<Network> network;

    virtual void SetUp() {
        network = std::make_shared<Network>();
    }

    virtual void TearDown() {

    }
};

TEST_F(Networks_Test, Test_addDrone_LOW) {
    this->network->setNetworkLimit(limit_low);
    shared_ptr<Basic_UAV> drone = std::make_shared<Basic_UAV>("1", "basic_uav", "cmd1", 0, 0, 0, false);
    EXPECT_TRUE(this->network->addDrone(drone));
    this->network->removeDrone(drone);
}

TEST_F(Networks_Test, Test_addDrone_HIGH) {
    this->network->setNetworkLimit(limit_high);
    shared_ptr<Basic_UAV> drone = std::make_shared<Basic_UAV>("1", "basic_uav", "cmd1", 0, 0, 0, false);
    EXPECT_TRUE(this->network->addDrone(drone));
    this->network->removeDrone(drone);

}

TEST_F(Networks_Test, Test_addNode_LOW) {
    this->network->setNetworkLimit(limit_low);
    shared_ptr<Basic_UAV> drone = std::make_shared<Basic_UAV>("1", "basic_uav", "cmd1", 0, 0, 0, false);
    this->network->addDrone(drone);
    shared_ptr<Node> node = std::make_shared<Node>(drone);
    EXPECT_TRUE(this->network->addNode(node));
    this->network->removeDrone(drone);

}

TEST_F(Networks_Test, Test_addNode_HIGH) {
    this->network->setNetworkLimit(limit_high);
    shared_ptr<Basic_UAV> drone = std::make_shared<Basic_UAV>("1", "basic_uav", "cmd1", 0, 0, 0, false);
    this->network->addDrone(drone);
    shared_ptr<Node> node = std::make_shared<Node>(drone);
    EXPECT_TRUE(this->network->addNode(node));
    this->network->removeNode(node);
    this->network->removeDrone(drone);
}

TEST_F(Networks_Test, Test_addLink_LOW) {
    this->network->setNetworkLimit(limit_low);
    shared_ptr<Basic_UAV> drone1 = std::make_shared<Basic_UAV>("1", "basic_uav", "cmd1", 0, 0, 0, false);
    this->network->addDrone(drone1);
    shared_ptr<Node> node1 = std::make_shared<Node>(drone1);
    this->network->addNode(node1);
    shared_ptr<Basic_UAV> drone2 = std::make_shared<Basic_UAV>("2", "basic_uav", "cmd1", 1, 1, 1, false);
    this->network->addDrone(drone2);
    shared_ptr<Node> node2 = std::make_shared<Node>(drone2);
    this->network->addNode(node2);
    EXPECT_TRUE(this->network->addLink(node1, node2, 1));
}

TEST_F(Networks_Test, Test_addLink_HIGH) {
    this->network->setNetworkLimit(limit_high);
    shared_ptr<Basic_UAV> drone1 = std::make_shared<Basic_UAV>("1", "basic_uav", "cmd1", 0, 0, 0, false);
    this->network->addDrone(drone1);
    shared_ptr<Node> node1 = std::make_shared<Node>(drone1);
    this->network->addNode(node1);
    shared_ptr<Basic_UAV> drone2 = std::make_shared<Basic_UAV>("2", "basic_uav", "cmd1", 1, 1, 1, false);
    this->network->addDrone(drone2);
    shared_ptr<Node> node2 = std::make_shared<Node>(drone2);
    this->network->addNode(node2);
    EXPECT_TRUE(this->network->addLink(node1, node2, 1));
}

TEST_F(Networks_Test, Test_removeLink_LOW) {
    this->network->setNetworkLimit(limit_low);
    shared_ptr<Basic_UAV> drone1 = std::make_shared<Basic_UAV>("1", "basic_uav", "cmd1", 0, 0, 0, false);
    this->network->addDrone(drone1);
    shared_ptr<Node> node1 = std::make_shared<Node>(drone1);
    this->network->addNode(node1);
    shared_ptr<Basic_UAV> drone2 = std::make_shared<Basic_UAV>("2", "basic_uav", "cmd1", 1, 1, 1, false);
    this->network->addDrone(drone2);
    shared_ptr<Node> node2 = std::make_shared<Node>(drone2);
    this->network->addNode(node2);
    this->network->addLink(node1, node2, 1);
    shared_ptr<Link> link = std::make_shared<Link>(node1, node2, 1);

    std::cout << "Testing removeLink() returns true on valid call..." << std::endl;
    EXPECT_TRUE(this->network->removeLink(link));
    if (HasFailure()) {
        std::cout<< "removeLink() returned false on a valid call"<<std::endl;
    }
    else {
        std::cout << "removeLink() returned true on a valid call" << std::endl;
    }
    std::cout << "Testing if removeLink() actually removed the link..." << std::endl;
    EXPECT_FALSE(this->network->linkExists(node1, node2));
    if (HasFailure()) {
        std::cout<< "removeLink() failed to actually remove the link from the network"<<std::endl;
    }
    else {
        std::cout << "removeLink() succesfully removed the link from the network" << std::endl;
    }
}
TEST_F(Networks_Test,Test_linkSwarm) {
    
}
