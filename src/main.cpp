#include <iostream>
#include <vector>
#include "Drones/Base_Drone.h"
#include "Drones/Command_UAV.h"
#include "Drones/Basic_UAV.h"
#include "Missions/Mission.h"

int main() {
    std::cout << "Starting simulation" << std::endl;
    std::vector<std::shared_ptr<Command_UAV>> cmd_drones;
    int cmd_cnt;
    std::cout << "How many command drones? ";
    std::cin >> cmd_cnt;
    std::cout << std::endl;
    for (int i = 0; i < cmd_cnt; i++) {
        std::shared_ptr<Command_UAV> cmdr = std::make_shared<Command_UAV>(
                std::to_string(i), i, i, i, false, std::to_string(i), std::to_string(i),
                std::to_string(i));
        cmd_drones.push_back(cmdr);
        std::cout << "Successfully added command uav with id: " << cmdr->getId() << std::endl;
    }

    std::cout << "\nHow many drones per swarm? ";
    unsigned int swarm_cnt;
    std::cin >> swarm_cnt;
    for (int c = 0; c < cmd_cnt; c++) {
        for (int i = 0; i < swarm_cnt; i++) {
            std::shared_ptr<Base_Drone> drone = std::make_shared<Basic_UAV>(std::to_string(i), i, i, i, false);
            cmd_drones.at(c)->addDrone(drone);
        }
    }
    return 0;
}