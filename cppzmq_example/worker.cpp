#include <string>
#include <zmq.hpp>

int main(int argc, char* args[]) {
    if (argc != 2) return -1;
    std::string prefix{std::string(args[1]) + ": "};
    zmq::context_t ctx(1);
    zmq::socket_t receiver(ctx, zmq::socket_type::pull);
    receiver.connect("tcp://localhost:5557");
    zmq::socket_t sender(ctx, zmq::socket_type::push);
    sender.connect("tcp://localhost:5558");
    while (true) {
        zmq::message_t message;
        zmq::recv_result_t r = receiver.recv(message);
        std::string_view str{prefix + message.to_string()};
        zmq::message_t result{str.begin(), str.end()};
        sender.send(std::move(result), zmq::send_flags::none);
    }
    return 0;
}