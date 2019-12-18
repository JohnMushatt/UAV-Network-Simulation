//
// Created by john on 12/17/19.
//

#ifndef UAV_SIM_CONNECTION_HANDLER_H
#define UAV_SIM_CONNECTION_HANDLER_H

#include <iostream>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/enable_shared_from_this.hpp>

using namespace boost::asio;
using ip::tcp;
using std::cout;
using std::endl;


class connection_handler : public boost::enable_shared_from_this<connection_handler> {
#define MAX_MESSAGE_LENGTH 1024

private:
    tcp::socket socket;
    char *data[MAX_MESSAGE_LENGTH];
    char *response[MAX_MESSAGE_LENGTH];
public:
    typedef boost::shared_ptr<connection_handler> pointer;
    connection_handler(boost::asio::io_service &io_service);
    tcp::socket &get_socket();
    static pointer create_conn_handler(boost::asio::io_service &io_service);
    bool  start();
    void handle_read(const boost::system::error_code &error, size_t bytes_transferred);
    void handle_write(const boost::system::error_code &error, size_t bytes_transferred);
protected:
};


#endif //UAV_SIM_CONNECTION_HANDLER_H
