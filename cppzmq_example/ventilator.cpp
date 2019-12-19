#include <string>
#include <iostream>
#include <thread>
#include <chrono>
#include <zmq.hpp>

int main() {
    zmq::context_t context(1);
    zmq::socket_t sender(context, zmq::socket_type::push);
    sender.bind("tcp://*:5557");
    std::string task{"Hello World!"};
    while (true) {
        zmq::message_t message{task.begin(), task.end()};
        sender.send(std::move(message), zmq::send_flags::none);
        std::this_thread::sleep_for(std::chrono::seconds(2));     
    }
    return 0;
}