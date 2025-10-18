#include "interpreter.hpp"
#include "../lex.yy.c"
#include <random>
#include <vector>

std::map<std::string, bool> cmdList = {
	{"run", false},
	{"debug", false},
	{"devbug", false},
	{"hardcore", false},
    {"testing", false}
};

///void test, void run, ID load, void dispose(ID)

int load()
{
    std::random_device rd;  // Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> distrib(10000000, 99999999);
    return distrib(gen);
}

void dispose()
{

}

void run(int argc, char* argv[])
{
    std::cout << "/////////RUNNING/////////" << std::endl;

    if (argc < 2)
    {
        std::cout << "\nUsage:\n\toclc --run \"file path\"" << std::endl;
        return;
    }

    std::vector<ObjectCalc::errorClass> errorList;

    astNode* root = parser_main(argc, argv, &errorList);

    if (cmdList["devbug"]) printAST(*root, "", cmdList);

    Interpreter::preRun(root, errorList); //Link memories, evaluate node health, etc

    if (cmdList["devbug"]) //get left-most leaf
    {
        std::cout << "after///" << std::endl;
        astNode* node = root;
    loop:
        if (node->nodes.size() > 0)
        {
            node = node->nodes[0];
            goto loop;
        }
        else
        {
            std::cout << *node << std::endl;
            printMEM(node, cmdList);
        }
    }

    //ADD: Process errors and evaluete if run is possible

    //Interpreter::interpret(root, errorList);

    delete root;
}

void test(int argc, char* argv[])
{

}