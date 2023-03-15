//
// Created by Артём on 13.03.2023.
//

#ifndef TASK2_NUM9_LIB_H
#define TASK2_NUM9_LIB_H

#include "Thread.h"
#include "Process.h"


class Lib {
private:
    int id;
    int whoseThread = 0;
    int memoryUsage;

public:
    Lib(int inputId, int inputMemoryUsage) : id(inputId), memoryUsage(inputMemoryUsage) {}

    int getLibId() {
        return id;
    }

    int getLibMemoryUsage() {
        return memoryUsage;
    }

    void getLibInfo() {
        std::cout << "              Id - " << id << "; " << "Memory usage - " << memoryUsage << "; " << std::endl;;
    }
};


#endif //TASK2_NUM9_LIB_H
