//
// Created by johnm on 10/14/2019.
//

#ifndef UAV_SIM_BASIC_UAV_H
#define UAV_SIM_BASIC_UAV_H

#include "Base_Drone.h"

class Basic_UAV : public Base_Drone {
public:
    Basic_UAV(const std::string &id, const std::string &type, const std::string &cmd_type, double x, double y, double z,
              bool active);

    std::string buildPacket(std::shared_ptr<Mission> mission);

    const std::string &getCmdId() const;

private:
    std::string cmd_id;
};


#endif //UAV_SIM_BASIC_UAV_H
