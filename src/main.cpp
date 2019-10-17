#include <iostream>
#include <vector>
#include <chrono>
#include <thread>

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
        std::string id = std::string("cmd_") + std::to_string(i);
        std::string type("cmd");
        double x = i;
        double y = i;
        double z = i;
        bool active = false;
        std::string cmd_key = std::to_string(i);
        std::string rf_in = std::to_string(i);
        std::string rf_out = std::to_string(i);

        std::shared_ptr<Command_UAV> cmdr = std::make_shared<Command_UAV>(
                id, type, x, y, z, active, cmd_key, rf_in, rf_out);
        cmd_drones.push_back(cmdr);
        std::cout << "Successfully added command uav with id: " << cmdr->getId() << std::endl;
    }

    std::cout << std::endl << "How many drones per swarm? ";
    unsigned int swarm_cnt;
    std::cin >> swarm_cnt;
    unsigned int count =0;
    for (int c = 0; c < cmd_cnt; c++) {
        for (int i = 0; i < swarm_cnt; i++) {
            std::string id = std::to_string(count);
            std::string type("basic_uav");
            double x = i;
            double y = i;
            double z = i;
            bool active = false;
            std::string cmd_id = cmd_drones.at(c)->getId();
            std::string rf_in = std::to_string(i);
            std::string rf_out = std::to_string(i);
            std::shared_ptr<Base_Drone> drone = std::make_shared<Basic_UAV>(id, type, cmd_id, x, y, z, active);
            cmd_drones.at(c)->addDrone(drone);
            count++;
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
    std::cout << "\nDisplaying drones in the network..." << std::endl;
    std::this_thread::sleep_for(std::chrono_literals::operator ""s(1));
    network->displayNetwork();
    std::cout << "\nInitializing Network..." << std::endl;
    std::this_thread::sleep_for(std::chrono_literals::operator ""s(2));
    network->initNetwork();
    return 0;
}