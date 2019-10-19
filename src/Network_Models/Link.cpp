//
// Created by johnm on 10/15/2019.
//

#include "Link.h"

Link::Link(const shared_ptr<Node> &n1, const shared_ptr<Node> &n2, double weight) {
    if (n1.get() == nullptr || n2.get() == nullptr) {
        throw std::invalid_argument("Either n1 or n2 reference a nullptr");
    } else {
        if (n1 == n2 || n2 == n1) {
            throw std::invalid_argument("n1 cannot be equal to n2");
        } else {
            this->n1 = n1;
            this->n2 = n2;
        }
    }

    if (weight <= 0) {
        throw std::invalid_argument("Weight cannot be 0 nor negative");
    } else {
        this->weight = weight;
    }
}

double Link::getWeight() const {
    return this->weight;
}

const shared_ptr<Node> &Link::getN1() const {
    return n1;
}

const shared_ptr<Node> &Link::getN2() const {
    return n2;
}

bool Link::operator==(Link const &obj) {
    if ((this->getN1()->operator==(obj.getN1()) && this->getN2() == obj.getN2()) ||
        (this->getN1() == obj.getN2() && this->getN2() == this->getN1())) {
        return true;
    }
    return false;
}
bool Link::operator==(const shared_ptr<Link> &obj) {
    if ((this->getN1()->operator==(obj->getN1()) && this->getN2() == obj->getN2()) ||
        (this->getN1()->operator==(obj->getN2())&& this->getN2()->operator==(this->getN1()))) {
        return true;
    }
    return false;
}