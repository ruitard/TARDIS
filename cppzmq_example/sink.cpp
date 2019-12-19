#include <iostream>
#include <zmq.hpp>

int main() {
    zmq::context_t context(1);
    zmq::socket_t receiver(context, zmq::socket_type::pull);
    receiver.bind("tcp://*:5558");
    while (true) {
        zmq::message_t message;
        zmq::recv_result_t r = receiver.recv(message);
        std::cout << message.to_string_view() << std::endl;
    }
    return 0;
}