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

class Link_Tests : public ::testing::Test {
protected:
    vector<shared_ptr<Base_Drone>> drones;
    shared_ptr<Link> test_link;
    shared_ptr<Node> n1;
    shared_ptr<Node> n2;
    shared_ptr<Node> null_node = nullptr;

    virtual void SetUp() {
        shared_ptr<Basic_UAV> d1 = std::make_shared<Basic_UAV>("d1", "basic_uav", "N/A", 0, 0, 0, true);
        shared_ptr<Basic_UAV> d2 = std::make_shared<Basic_UAV>("d2", "basic_uav", "N/A", 1, 1, 1, true);

        drones.push_back(d1);
        drones.push_back(d2);

        n1 = std::make_shared<Node>(d1);
        n2 = std::make_shared<Node>(d2);

    }

    virtual void TearDown() {
        drones.clear();
    }
};

TEST_F(Link_Tests, Valid_Link) {
    test_link = std::make_shared<Link>(n1, n2, 1);
    EXPECT_EQ(test_link->getN1(), n1);
    EXPECT_EQ(test_link->getN2(), n2);
    EXPECT_EQ(test_link->getWeight(), 1);
}

TEST_F(Link_Tests, Invalid_Link_NullNode) {
    EXPECT_ANY_THROW(std::make_shared<Link>(n1, null_node, 1));

}
TEST_F(Link_Tests, Invalid_Link_BadWeight) {
    EXPECT_ANY_THROW(std::make_shared<Link>(n1, null_node, -1));

}