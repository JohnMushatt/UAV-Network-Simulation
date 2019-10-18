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