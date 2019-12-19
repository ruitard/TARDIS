#include <iostream>
#include <string>
#include <zmq.hpp>

int main() {
    zmq::context_t context(1);
    zmq::socket_t socket(context, zmq::socket_type::req);
    socket.connect("tcp://localhost:5555");
    while (true) {
        std::cout << ">>> ";
        std::string str;
        getline(std::cin, str);
        zmq::message_t request{str.begin(), str.end()};
        socket.send(std::move(request), zmq::send_flags::none);
        zmq::message_t reply;
        zmq::recv_result_t r = socket.recv(reply);
        std::cout << reply.to_string_view() << std::endl;
    }
    return 0;
}