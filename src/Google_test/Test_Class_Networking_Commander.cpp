//
// Created by john on 12/2/19.
//

#include "gtest/gtest.h"
#include "Drones/Networking_Commander.h"
#include <memory>

using std::shared_ptr;
using std::make_shared;

#include <vector>

using std::vector;

class Networking_Test : public ::testing::Test {
protected:
    shared_ptr<Networking_Commander> cmd_net;
    virtual void setup() {
        cmd_net = make_shared<Networking_Commander>();
    }

    virtual void TearDown() {

    }

};
TEST_F(Networking_Test,Test_SendingMessage) {
    boost::asio::io_service io;
    tcp::acceptor acceptor_(io,tcp::endpoint(tcp::v4(),3000));
    tcp::socket socket_(io);
    acceptor_.accept(socket_);
    string message = this->cmd_net->read_(socket_);

}