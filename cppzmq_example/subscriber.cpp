#include <thread>
#include <chrono>
#include <iostream>
#include <zmq.hpp>

int main() {
    zmq::context_t context(1);
    zmq::socket_t subscriber(context, zmq::socket_type::sub);
    subscriber.connect("tcp://localhost:5556");
    subscriber.setsockopt(ZMQ_SUBSCRIBE, "", 0);
    while (true) {
        zmq::message_t message;
        zmq::recv_result_t r = subscriber.recv(message);
        std::cout << "now: " << message.to_string_view() << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    return 0;
}