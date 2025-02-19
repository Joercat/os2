#ifndef WEB_SERVER_H
#define WEB_SERVER_H

#include "os.h"

class WebServer {
private:
    int server_fd;
    SimpleOS& os;
    static const char* HTML_CONTENT;

    void handleRequest(int socket);
    void sendResponse(int socket, const std::string& content);

public:
    WebServer(SimpleOS& simpleOS);
    void start();
    ~WebServer();
};

#endif
