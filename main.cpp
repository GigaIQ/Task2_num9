#include <iostream>

#include "Process.h"
#include "Thread.h"
#include "Lib.h"

int main() {
    int input = -1;
    int processId = 0;
    std::cout << "Enter process id" << std::endl;
    std::cin >> processId;
    std::cout << std::endl;
    Process process(processId);
    while(input != 0) {

        std::cout << "Choose action" << std::endl;
        std::cout << "1 - show" << std::endl;
        std::cout << "2 - add thread" << std::endl;
        std::cout << "3 - add lib" << std::endl;
        std::cout << "4 - delete thread" << std::endl;
        std::cout << "5 - delete lib" << std::endl;
        std::cout << "6 - find lib by ID" << std::endl;

        std::cout << "0 - exit" << std::endl;

        std::cin >> input;

        switch (input) {
            case 0: {
                break;
            }
            case 1: {
                process.getProcessInfo();
                break;
            }
            case 2: {
                std::cout << "Input thread id" << std::endl;
                int threadId = 0;
                int isSameId = 0;
                std::cin >> threadId;

                std::vector<Thread> threads = process.getThreads();
                for (int i = 0; i < threads.size(); ++i) {
                    if (threads[i].getId() == threadId) {
                        isSameId = 1;
                    }
                }
                if (isSameId == 1) {
                    std::cout << "Thread with this ID already exist! Try another ID" << std::endl;
                    break;
                }
                int threadMemory = 0;
                std::cout << std::endl << "Input thread own memory usage" << std::endl;
                std::cin >> threadMemory;
                Thread thread(threadId, threadMemory);
                process.addThread(thread);
                std::cout << "Thread was added" << std::endl;
                break;
            }
            case 3: {
                std::cout << "In what thread? (id)" << std::endl;
                int threadId = 0;
                std::cin >> threadId;
                int idCorrect = 0;
                int threadNum = 0;
                std::vector<Thread> threads = process.getThreads();
                for (int i = 0; i < threads.size(); ++i) {
                    if (threads[i].getId() == threadId) {
                        idCorrect = 1;
                        threadNum = i;
                    }
                }
                if (idCorrect == 1) {
                    std::cout << "Input lib id" << std::endl;
                    int libId = 0;
                    int libMemory = 0;

                    std::cin >> libId;

                    std::cout << std::endl << "Input lib memory usage" << std::endl;
                    std::cin >> libMemory;
                    Lib lib(libId, libMemory);
                    process.addLib(threads[threadNum], lib);
                    std::cout << "Thread was added" << std::endl;
                    break;
                } else {
                    std::cout << "Incorrect id" << std::endl;
                    break;
                }
                break;
            }
            case 4: {
                std::cout << "What thread delete?" << std::endl;
                int threadId = 0;
                std::cin >> threadId;
                process.deleteThreadFomProcess(threadId);
                std::cout << "Thread was deleted" << std::endl;
                break;
            }
            case 5: {
                std::cout << "In what thread lib delete? (id)" << std::endl;
                int threadId = 0;
                std::cin >> threadId;
                int idCorrect = 0;
                int threadNum = 0;
                std::vector<Thread> threads = process.getThreads();
                for (int i = 0; i < threads.size(); ++i) {
                    if (threads[i].getId() == threadId) {
                        idCorrect = 1;
                        threadNum = i;
                    }
                }
                if (idCorrect == 1) {
                    std::cout << "Lib id to delete" << std::endl;
                    int libId = 0;
                    std::cin >> libId;
                    process.deleteLib(threads[threadNum], libId);
                    std::cout << "Lib was deleted" << std::endl;
                    break;
                } else {
                    std::cout << "Incorrect id" << std::endl;
                    break;
                }
                break;
            }
            case 6: {
                std::cout << "What lib found? (ID)" << std::endl;
                int libId = -1;
                std::cin >> libId;
                process.findLibById(libId);
                break;
            }

        }
    }

    return 0;
}
