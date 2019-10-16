//
// Created by johnm on 10/15/2019.
//

#include "Link.h"

Link::Link(const shared_ptr<Node> &n1, const shared_ptr<Node> &n2, double weight) {
    this->n1 = n1;
    this->n2 = n2;
    this->weight = weight;
}

double Link::getWeight() const {
    return weight;
}

const shared_ptr<Node> &Link::getN1() const {
    return n1;
}

const shared_ptr<Node> &Link::getN2() const {
    return n2;
}
