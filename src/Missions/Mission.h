//
// Created by johnm on 10/14/2019.
//

#ifndef UAV_SIM_MISSION_H
#define UAV_SIM_MISSION_H

#include <vector>
#include <chrono>
#include <string>
class Mission {
public:
    Mission();
private:
    std::string mission_type;
    std::string target_drone_id;
    std::vector<std::string> path;
    std::chrono::system_clock::time_point start_time;
    std::chrono::system_clock::time_point end_time;
    std::chrono::system_clock::time_point current_time;
    bool completed;
};


#endif //UAV_SIM_MISSION_H
