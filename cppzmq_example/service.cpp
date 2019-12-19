#include <iostream>
#include <zmq.hpp>
#include <fmt/format.h>

int main() {
    {
        auto [major, minor, patch] = zmq::version();
        fmt::print("version: {}.{}.{}\n", major, minor, patch);
    }
    zmq::context_t context(1);
    zmq::socket_t socket(context, zmq::socket_type::rep);
    socket.bind("tcp://*:5555");
    while (true) {
        zmq::message_t msg;
        zmq::recv_result_t r = socket.recv(msg);
        socket.send(std::move(msg), zmq::send_flags::none);
    }
    return 0;
}