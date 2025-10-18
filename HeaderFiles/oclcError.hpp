#pragma once
#include <stdlib.h>
#include <string>
#include <iostream>

namespace ObjectCalc
{
	extern bool isRunning;

	/*void oclcError(std::string message, const int(&pos)[4])
	{
		if (isRunning) std::cout << "\n-----------------------------------------------------------------------" << std::endl;
		std::cout << "\n\n{" + message + "} {Start: " + std::to_string(pos[0]) + " " + std::to_string(pos[1]) + "} {End: " + std::to_string(pos[2]) + " " + std::to_string(pos[3]) + "}\n\n";
		exit(0);
	}
	void oclcError(std::string message, int (&pos)[4])
	{
		if (isRunning) std::cout << "\n-----------------------------------------------------------------------" << std::endl;
		std::cout << "\n\n{" + message + "} {Start: " + std::to_string(pos[0]) + " " + std::to_string(pos[1]) + "} {End: " + std::to_string(pos[2]) + " " + std::to_string(pos[3]) + "}\n\n";
		exit(0);
	}*/
	void oclcError(std::string message, const int(&pos)[2])
	{
		if (isRunning) std::cout << "\n-----------------------------------------------------------------------" << std::endl;
		std::cout << "\n\n{" + message + "} {At: " + std::to_string(pos[0]) + " " + std::to_string(pos[1]) + "}\n\n";
		exit(0);
	}
	void oclcError(std::string message, int(&pos)[2])
	{
		if (isRunning) std::cout << "\n-----------------------------------------------------------------------" << std::endl;
		std::cout << "\n\n{" + message + "} {At: " + std::to_string(pos[0]) + " " + std::to_string(pos[1]) + "}\n\n";
		exit(0);
	}
}