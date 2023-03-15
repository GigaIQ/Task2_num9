//
// Created by Артём on 12.03.2023.
//

#ifndef TASK2_NUM9_THREAD_H
#define TASK2_NUM9_THREAD_H

#include <iostream>
#include <vector>
#include "Process.h"
#include "Lib.h"

class Thread {
private:
    int id;
    int memoryUsage;
    int whoseProcess = 0;
    std::vector<Lib> connectedLibs;

public:
    Thread(int inputId, int inputMemoryUsage) : id(inputId), memoryUsage(inputMemoryUsage) {}

    void addLib(Lib lib) {
        connectedLibs.push_back(lib);

    }

    void deleteLibFomThread(int libId) {
        int index = -1;
        for (int i = 0; i < connectedLibs.size(); i++) {
            if (connectedLibs[i].getLibId() == libId) {
                index = i;
            }
        }
        connectedLibs.erase(connectedLibs.begin() + index);

    }

    std::vector<Lib> getConnectedLibs() {
        return connectedLibs;
    }

//    void deleteLib(int libId) {
//        int index = -1;
//        for (int i = 0; i < connectedLibs.size(); i++) {
//            if (connectedLibs[i].getLibId() == libId) {
//                index = i;
//            }
//        }
//        connectedLibs.erase(connectedLibs.begin() + index);
//    }

    void addWhoseProcess(int processId) {
        whoseProcess = processId;
    }

    int getId() {
        return id;
    }

    int getClearMemoryUsage() {
        return memoryUsage;
    }

    int getMemoryUsage() {
        int libsMemoryUsage = 0;
        for (int i = 0; i < connectedLibs.size(); ++i) {
            libsMemoryUsage += connectedLibs[i].getLibMemoryUsage();
        }
        return memoryUsage + libsMemoryUsage;
    }


    void getInfoAboutThread() {
        std::cout << "      Id - " << id << "; " << "Memory usage - " << memoryUsage << "; ";
//        << "Belong to the process with ID - " << whoseProcess;
        std::cout << std::endl;
        int libsMemoryUsage = 0;
        for (int i = 0; i < connectedLibs.size(); ++i) {
            libsMemoryUsage += connectedLibs[i].getLibMemoryUsage();
        }
        std::cout << "      General memory usage - " << memoryUsage + libsMemoryUsage << std::endl;
        std::cout << "      Libs info:" << std::endl;
        for (int i = 0; i < connectedLibs.size(); ++i) {
            connectedLibs[i].getLibInfo();
        }
        std::cout << std::endl;
    }

};



#endif //TASK2_NUM9_THREAD_H
