#include <iostream>
#include <sstream>
#include <map>
#include <vector>

namespace ObjectCalc
{
	struct astNode;
}

using namespace ObjectCalc;

namespace Memory
{
	struct Register
	{
		long long NUM;
		long double DEC;
		std::string	STR;
		bool BOOL;
	};

	struct Storage //Interpreter memory
	{
		Register registerA;
		Register registerB;
		bool success; //Did the sub node operation succeed? vital for knowing if + as subnde of = can do math.
	};

	struct memNode
	{
		memNode* MEMparent = nullptr;
		astNode* ASTparent = nullptr;
		std::vector<char*> names;
		std::map<char*, long long*> NUMs;
		std::map<char*, long double*> DECs;
		std::map<char*, std::string*> STRs;
		std::map<char*, bool*> BOOLs;
		std::map<char*, astNode*> OBJECTs;

		memNode(astNode* parent)
		{
			ASTparent = parent;
		}

		operator std::string() const 
		{
			std::stringstream ss;
			ss << MEMparent;
			std::string outpt = "{MEMparent: " + ss.str() + "}";
			ss.str("");
			ss << ASTparent;
			outpt += " {ASTparent: " + ss.str() + "}";
			return outpt;
		}
	};
}