//
// Created by johnm on 10/18/2019.
//

#include "gtest/gtest.h"
#include "Network_Models/Link.h"
#include "Network_Models/Node.h"
#include "Drones/Basic_UAV.h"
#include "Drones/Base_Drone.h"
#include <memory>

using std::shared_ptr;

#include <vector>

using std::vector;

class Nodes_Test : public ::testing::Test {
protected:
    shared_ptr<Node> valid_node1, valid_node2;
    shared_ptr<Node> invalid_node;
    shared_ptr<Link> test_link;
    shared_ptr<Basic_UAV> d1, d2;

    virtual void SetUp() {
        d1 = std::make_shared<Basic_UAV>("d1", "basic_uav", "N/A", 0, 0, 0, true);
        d2 = std::make_shared<Basic_UAV>("d2", "basic_uav", "N/A", 1, 1, 1, true);

        valid_node1 = std::make_shared<Node>(d1);
        valid_node2 = std::make_shared<Node>(d2);
    }

    virtual void TearDown() {

    }
};

TEST_F(Nodes_Test, Valid_Constructor) {
    EXPECT_EQ(valid_node1->getDrone()->getId(), d1->getId());
    EXPECT_EQ(valid_node2->getDrone()->getId(), d2->getId());
}

TEST_F(Nodes_Test, Invalid_Constructor) {
    EXPECT_ANY_THROW(std::make_shared<Node>(nullptr));
}

TEST_F(Nodes_Test, Test_getDrone) {
    EXPECT_EQ(valid_node1->getDrone(), d1);
}

TEST_F(Nodes_Test, Test_Equals) {
    EXPECT_EQ(valid_node1, valid_node1);
    EXPECT_NE(valid_node1, valid_node2);
}

TEST_F(Nodes_Test, Test_setDrone) {
    valid_node1->setDrone(d2);
    EXPECT_EQ(valid_node1->getDrone(), valid_node2->getDrone());
    valid_node1->setDrone(d1);
}

TEST_F(Nodes_Test, Test_removeDrone) {
    valid_node1->removeDrone();
    EXPECT_EQ(valid_node1->getDrone(), nullptr);
    valid_node1->setDrone(d1);
}

TEST_F(Nodes_Test, Test_flipStatus) {
    valid_node1->flipStatus();
    EXPECT_TRUE(valid_node1->getStatus());
    valid_node1->flipStatus();
    EXPECT_FALSE(valid_node1->getStatus());
}