#ifndef SIMPLE_OS_H
#define SIMPLE_OS_H

#include <vector>
#include <string>

class SimpleOS {
private:
    std::vector<std::string> processes;
    bool running;

public:
    SimpleOS();
    void start();
    void addProcess(const std::string& process);
    std::string getProcessList();
    bool isRunning() const { return running; }
};

#endif
