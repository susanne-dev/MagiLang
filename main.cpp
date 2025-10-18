#include <fstream>
#include <iostream>
#include "HeaderFiles/main.hpp"

using namespace ObjectCalc;

namespace ObjectCalc
{
    bool isRunning = false;
}

int main(int argc, char* argv[]) 
{
    token* t = new token();
    astNode temp = astNode();

    for (int i = 1; i < argc; i++)
    {
        if (((std::string)argv[i]).substr(0, 2) == "--")
        {
            std::string cmd = ((std::string)argv[i]).substr(2);

            if (cmdList.count(cmd) == 1)
            {
                cmdList[cmd] = !cmdList[cmd];
                goto SKIP;
            }
            std::cout << "Uknown command: \"";
            std::cout << argv[i];
            std::cout << "\"" << std::endl;
        }
    SKIP:
        ;
    }

    if (cmdList["run"]) run(argc, argv);
    if (cmdList["testing"]) test(argc, argv);

    return 0;
}