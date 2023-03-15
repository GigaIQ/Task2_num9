//
// Created by Артём on 12.03.2023.
//

#ifndef TASK2_2_PROCESS_H
#define TASK2_2_PROCESS_H

#include <iostream>
#include <vector>
#include <algorithm>
#include "Thread.h"
#include "Lib.h"

class Thread;

class Process {
private:
    int id;
    int whoseProcess;
    int memoryUsage = 0;
    std::vector<Thread> connectedThreads;

public:
    Process(int inputId) : id(inputId) {}

    std::vector<Thread> getThreads() {
        return connectedThreads;
    }

    void getProcessInfo() {
        std::cout << "Process info:" << std::endl;
        std::cout << "Id - " << id << std::endl;
//        std::cout << "Memory usage - " << memoryUsage << std::endl;
        int threadsMemoryUsage = 0;
        for (int i = 0; i < connectedThreads.size(); ++i) {
            threadsMemoryUsage += connectedThreads[i].getMemoryUsage();
        }

        std::cout << "General memory usage - " << memoryUsage + threadsMemoryUsage << std::endl;
        std::cout << "Thread info:" << std::endl;
        for (int i = 0; i < connectedThreads.size(); ++i) {
            connectedThreads[i].getInfoAboutThread();
        }
        std::cout << std::endl;
    }

    void addThread(Thread thread) {
        connectedThreads.push_back(thread);
//        thread.addWhoseProcess(id);
    }

    void addLib(Thread toWhatThread, Lib whatLib) {
        std::vector<Lib> libs = toWhatThread.getConnectedLibs();
        Thread tempThread(toWhatThread.getId(), toWhatThread.getClearMemoryUsage());
        for (int i = 0; i < libs.size(); ++i) {
            tempThread.addLib(libs[i]);
        }
        tempThread.addLib(whatLib);
        deleteThreadFomProcess(toWhatThread.getId());
        addThread(tempThread);
//        toWhatThread.addLib(whatLib);
    }

    void deleteLib(Thread fromWhatThread, int libIdToDelete) {
        std::vector<Lib> libs = fromWhatThread.getConnectedLibs();
        int correctIdCheck = 0;
        for (int i = 0; i < libs.size(); ++i) {
            if (libs[i].getLibId() == libIdToDelete) {
                correctIdCheck = 1;
            }
        }
        if (correctIdCheck == 1) {
            Thread tempThread(fromWhatThread.getId(), fromWhatThread.getClearMemoryUsage());
            fromWhatThread.deleteLibFomThread(libIdToDelete);

            std::vector<Lib> newLibs = fromWhatThread.getConnectedLibs();
            for (int i = 0; i < newLibs.size(); ++i) {
                tempThread.addLib(newLibs[i]);
            }
            deleteThreadFomProcess(fromWhatThread.getId());
            addThread(tempThread);
        } else {
            std::cout << "Lib with this ID does not exist, nothing to delete" << std::endl;
        }
    }

    void deleteProcess() {

    }

    void deleteThreadFomProcess(int threadId) {
        int checkThreadId = 0;
        for (int i = 0; i < connectedThreads.size(); i++) {
            if (connectedThreads[i].getId() == threadId) {
                checkThreadId = 1;
            }
        }
        if (checkThreadId == 1) {
            int index = -1;
            for (int i = 0; i < connectedThreads.size(); i++) {
                if (connectedThreads[i].getId() == threadId) {
                    index = i;
                }
            }
            connectedThreads.erase(connectedThreads.begin() + index);
        } else{
            std::cout << "Thread with this ID does not exist, nothing to delete" << std::endl;
        }

    }

};


#endif //TASK2_2_PROCESS_H
