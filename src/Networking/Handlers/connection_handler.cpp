//
// Created by john on 12/17/19.
//

#include "connection_handler.h"


connection_handler::connection_handler(boost::asio::io_service &io_service) :
        socket(io_service) {
}

connection_handler::pointer connection_handler::create_conn_handler(boost::asio::io_service &io_service) {
    return pointer(new connection_handler(io_service));
}

tcp::socket &connection_handler::get_socket() {
    return this->socket;
}

bool connection_handler::start() {
    this->socket.async_read_some(
            boost::asio::buffer(data, MAX_MESSAGE_LENGTH),
            boost::bind(&connection_handler::handle_read,
                        shared_from_this(),
                        boost::asio::placeholders::error,
                        boost::asio::placeholders::bytes_transferred));

    this->socket.async_write_some(
            boost::asio::buffer(response, MAX_MESSAGE_LENGTH),
            boost::bind(&connection_handler::handle_write,
                        shared_from_this(),
                        boost::asio::placeholders::error,
                        boost::asio::placeholders::bytes_transferred));
}

void connection_handler::handle_read(const boost::system::error_code &error, size_t bytes_transferred) {
    if (!error) {
        cout << data << endl;
    } else {
        std::cerr << "error: " << error.message() << std::endl;
        socket.close();
    }
}

void connection_handler::handle_write(const boost::system::error_code &error, size_t bytes_transferred) {
    if (!error) {
        cout << "Server sent Hello message!" << endl;
    } else {
        std::cerr << "error: " << error.message() << endl;
        socket.close();
    }
}