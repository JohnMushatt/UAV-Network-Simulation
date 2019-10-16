//
// Created by johnm on 10/14/2019.
//

#ifndef UAV_SIM_BASIC_UAV_H
#define UAV_SIM_BASIC_UAV_H

#include "Base_Drone.h"

class Basic_UAV : public Base_Drone {
public:
    Basic_UAV(const std::string &id, double x, double y, double z, bool active);
private:

};


#endif //UAV_SIM_BASIC_UAV_H
