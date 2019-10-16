#include <iostream>
#include <vector>
#include "Drones/Base_Drone.h"
#include "Drones/Command_UAV.h"
#include "Drones/Basic_UAV.h"
#include "Missions/Mission.h"
#include "Network_Models/Network.h"
#include "Network_Models/Model.h"

int main() {
    std::cout << "---------------Starting simulation---------------\n\n" << std::endl;
    /**
    * Build base network
    */
    shared_ptr<Network> network = std::make_shared<Network>();
    std::cout << "What should the network limit be? ";
    unsigned int limit;
    std::cin >> limit;
    network->setNetworkLimit(limit);
    std::vector<std::shared_ptr<Command_UAV>> cmd_drones;
    int cmd_cnt;
    std::cout << "How many command drones? ";
    std::cin >> cmd_cnt;
    std::cout << std::endl;
    for (int i = 0; i < cmd_cnt; i++) {
        std::shared_ptr<Command_UAV> cmdr = std::make_shared<Command_UAV>(
                std::to_string(i), std::string("cmd"), i, i, i, false, std::to_string(i), std::to_string(i),
                std::to_string(i));
        cmd_drones.push_back(cmdr);
        std::cout << "Successfully added command uav with id: " << cmdr->getId() << std::endl;
    }

    std::cout << std::endl << "How many drones per swarm? ";
    unsigned int swarm_cnt;
    std::cin >> swarm_cnt;
    for (int c = 0; c < cmd_cnt; c++) {
        for (int i = 0; i < swarm_cnt; i++) {
            std::shared_ptr<Base_Drone> drone = std::make_shared<Basic_UAV>(std::to_string(i + c),
                                                                            std::string("basic_uav"), i, i, i, false);
            cmd_drones.at(c)->addDrone(drone);

        }
    }

    /**
     * Add normal drones to the network
     */
    for (size_t i = 0; i < cmd_cnt; i++) {
        shared_ptr<Command_UAV> cmdr = cmd_drones.at(i);
        network->addDrone(cmdr);
        /**
         * Get current swarm and add it to the network
         * NOTE: Swarms should only contain unique drones much
         * like a Set
         */
        network->addDrone(cmdr->getSwarm());
    }
    network->displayNetwork();
    return 0;
}