//
// Created by john on 12/2/19.
//

#ifndef UAV_SIM_NETWORKING_BASIC_DRONE_H
#define UAV_SIM_NETWORKING_BASIC_DRONE_H

#include "Drones/Basic_UAV.h"
#include <iostream>
#include <boost/asio.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/thread/thread.hpp>
#include <boost/bind.hpp>
#include <memory>
using std::shared_ptr;
using std::make_shared;


using namespace boost::asio;
using ip::tcp;
using std::string;
using std::cout;
using std::endl;
class Networking_Basic_Drone {
    Networking_Basic_Drone();
    string read_(tcp::socket &socket);
    void send_(tcp::socket &socket, const string &msg);
private:
    shared_ptr<Basic_UAV> dr;
};


#endif //UAV_SIM_NETWORKING_BASIC_DRONE_H
