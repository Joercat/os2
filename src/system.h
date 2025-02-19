#ifndef SYSTEM_H
#define SYSTEM_H

#include <memory>
#include <map>
#include "process.h"

class System {
private:
    std::map<int, std::shared_ptr<Process>> processTable;
    int nextPid;

public:
    System() : nextPid(1) {}
    int createProcess(const std::string& name);
    void terminateProcess(int pid);
    std::shared_ptr<Process> getProcess(int pid);
    std::vector<std::shared_ptr<Process>> listProcesses();
};

#endif
