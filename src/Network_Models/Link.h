//
// Created by johnm on 10/15/2019.
//

#ifndef UAV_SIM_LINK_H
#define UAV_SIM_LINK_H

#include "Node.h"
#include <memory>
using std::shared_ptr;
class Link {
public:
    Link(const shared_ptr<Node> &n1, const shared_ptr<Node> &n2, double weight);
private:
    double weight;
public:
    double getWeight() const;

    const shared_ptr<Node> &getN1() const;

    const shared_ptr<Node> &getN2() const;

private:
    shared_ptr<Node> n1;
    shared_ptr<Node> n2;
};


#endif //UAV_SIM_LINK_H
