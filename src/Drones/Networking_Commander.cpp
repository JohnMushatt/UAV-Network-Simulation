//
// Created by john on 12/2/19.
//

#include "Networking_Commander.h"

Networking_Commander::Networking_Commander() {

}
/**
 * Reads message from socket, aysnc io
 * @param socket Socket to read from
 * @return String containing message
 */
std::__cxx11::string Networking_Commander::read_(tcp::socket &socket) {
    boost::asio::streambuf buffer;
    boost::asio::read_until(socket, buffer, "\n");

    string message = boost::asio::buffer_cast<const char *>(buffer.data());
    return message;
}
/**
 * Sends a message through the socket, async io
 * @param socket Socket to send message through
 * @param msg Message to send
 */
void Networking_Commander::send_(tcp::socket &socket, const string &msg) {
    const string message = msg + "\n";
    boost::asio::write(socket, boost::asio::buffer(message));

}