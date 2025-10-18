#pragma once

#include <iostream>
#include "token.hpp"

namespace ObjectCalc
{
	struct errorClass
	{
		std::string message = "EMPTY ERROR MESSAGE";
		int location[4] = {0, 0, 0, 0};
		token t = token();
		std::string value = "EMPTY";
		astNode* node;

		errorClass()
		{

		}

		errorClass(std::string m, const int (&l)[4])
		{
			message = m;
			location[0] = l[0];
			location[1] = l[1];
			location[2] = l[2];
			location[3] = l[3];
		}

		errorClass(std::string m, int (&l)[])
		{
			message = m;
			location[0] = l[0];
			location[1] = l[1];
			location[2] = l[2];
			location[3] = l[3];
		}

		errorClass(std::string m, astNode* n, int(&l)[])
		{
			message = m;
			node = n;
			location[0] = l[0];
			location[1] = l[1];
			location[2] = l[2];
			location[3] = l[3];
		}

		errorClass(std::string m, astNode* n, const int(&l)[4])
		{
			message = m;
			node = n;
			location[0] = l[0];
			location[1] = l[1];
			location[2] = l[2];
			location[3] = l[3];
		}

		operator std::string() const { return "{Message: " + message + "} {Value: " + escapeString(value) + "} {Start: " + std::to_string(location[0]) + " " + std::to_string(location[1]) + "} {End: " + std::to_string(location[2]) + " " + std::to_string(location[3]) + "}"; }

		friend std::ostream& operator<<(std::ostream& os, const errorClass& e) {
			return os << "{Message: " + e.message + "} {Token: " + std::string(e.t) + "} {Value: " + escapeString(e.value) + "} {Start: " + std::to_string(e.location[0]) + " " + std::to_string(e.location[1]) + "} {End: " + std::to_string(e.location[2]) + " " + std::to_string(e.location[3]) + "}";
		}
	};
}