#include <chrono>
#include <string>
#include <thread>
#include <zmq.hpp>

std::string_view current_time() {
    auto now = std::chrono::system_clock::now();
    time_t fmt_time = std::chrono::system_clock::to_time_t(now);
    return static_cast<std::string_view>(ctime(&fmt_time));
}

int main() {
    zmq::context_t context(1);
    zmq::socket_t publisher(context, zmq::socket_type::pub);
    publisher.bind("tcp://*:5556");
    while (true) {
        std::this_thread::sleep_for(std::chrono::seconds(2));
        std::string_view now = current_time();
        zmq::message_t message{now.begin(), now.end()};
        publisher.send(std::move(message), zmq::send_flags::none);
    }
    return 0;
}