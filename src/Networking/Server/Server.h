//
// Created by john on 12/18/19.
//

#ifndef UAV_SIM_SERVER_H
#define UAV_SIM_SERVER_H

#include <iostream>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/enable_shared_from_this.hpp>


#include "Networking/Handlers/connection_handler.h"
using namespace boost::asio;
using ip::tcp;
using std::cout;
using std::endl;
class Server {

private:
    tcp::acceptor acceptor_;
    void start_accept();
public:
    Server(boost::asio::io_service &io_service);
    void handle_accept(connection_handler::pointer connection, const boost::system::error_code &error)''
};


#endif //UAV_SIM_SERVER_H
