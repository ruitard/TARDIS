#include <iostream>
#include <thread>
#include <zmq.hpp>

void serve(zmq::context_t& context) {
    zmq::socket_t socket(context, zmq::socket_type::rep);
    socket.connect("tcp://localhost:6000");
    while (true) {
        zmq::message_t msg;
        zmq::recv_result_t r = socket.recv(msg);
        socket.send(std::move(msg), zmq::send_flags::none);
    }
}

void request(zmq::context_t& context) {
    zmq::socket_t socket(context, zmq::socket_type::req);
    socket.connect("tcp://localhost:5559");
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
}

int main() {
    zmq::context_t context(1);
    zmq::socket_t frontend(context, zmq::socket_type::router);
    frontend.bind("tcp://*:5559");
    zmq::socket_t backend(context, zmq::socket_type::dealer);
    backend.bind("tcp://*:6000");
    std::thread service(serve, std::ref(context));
    service.detach();
    std::thread client(request, std::ref(context));
    client.detach();
    zmq::proxy(frontend, backend);
    return 0;
}