#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <socket.h>
#include <in.h>
#include <unistd.h>

class SimpleOS {
private:
    std::vector<std::string> processes;
    bool running;

public:
    SimpleOS() : running(false) {}

    void start() {
        running = true;
        std::cout << "OS Started" << std::endl;
    }

    void addProcess(const std::string& process) {
        processes.push_back(process);
    }

    std::string getProcessList() {
        std::string list;
        for (const auto& p : processes) {
            list += p + "\n";
        }
        return list;
    }
};

class WebServer {
private:
    int server_fd;
    SimpleOS& os;

    static const char* HTML_CONTENT;

public:
    WebServer(SimpleOS& simpleOS) : os(simpleOS) {
        server_fd = socket(AF_INET, SOCK_STREAM, 0);
        struct sockaddr_in address;
        address.sin_family = AF_INET;
        address.sin_addr.s_addr = INADDR_ANY;
        address.sin_port = htons(8080);

        bind(server_fd, (struct sockaddr*)&address, sizeof(address));
        listen(server_fd, 3);
    }

    void start() {
        while (true) {
            int new_socket = accept(server_fd, nullptr, nullptr);
            char buffer[1024] = {0};
            read(new_socket, buffer, 1024);
            
            std::string response = "HTTP/1.1 200 OK\nContent-Type: text/html\n\n";
            response += HTML_CONTENT;
            
            write(new_socket, response.c_str(), response.length());
            close(new_socket);
        }
    }
};

const char* WebServer::HTML_CONTENT = R"(
<!DOCTYPE html>
<html>
<head>
    <title>Simple OS</title>
    <style>
        body { 
            font-family: Arial; 
            margin: 40px; 
            background: #f0f0f0;
        }
        .console {
            background: black;
            color: #00ff00;
            padding: 20px;
            border-radius: 5px;
            min-height: 200px;
        }
        .controls {
            margin-top: 20px;
        }
        button {
            padding: 10px 20px;
            margin: 5px;
        }
    </style>
</head>
<body>
    <h1>Simple OS Interface</h1>
    <div class="console" id="output"></div>
    <div class="controls">
        <button onclick="startOS()">Start OS</button>
        <button onclick="addProcess()">Add Process</button>
        <button onclick="listProcesses()">List Processes</button>
    </div>
</body>
</html>
)";

int main() {
    SimpleOS os;
    WebServer server(os);
    server.start();
    return 0;
}
