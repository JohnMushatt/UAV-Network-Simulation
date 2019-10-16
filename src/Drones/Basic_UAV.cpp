//
// Created by johnm on 10/14/2019.
//

#include "Basic_UAV.h"

Basic_UAV::Basic_UAV(const std::string &id, const std::string &type, double x, double y, double z, bool active)
        : Base_Drone(id, type, x, y, z, active) {

}

std::string Basic_UAV::buildPacket(std::shared_ptr<Mission> mission) {
    return nullptr;
}

const std::string &Basic_UAV::getCmdId() const {
    return cmd_id;
}
