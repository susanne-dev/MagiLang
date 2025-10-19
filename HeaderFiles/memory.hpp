#include <iostream>
#include <sstream>
#include <map>
#include <vector>

namespace MagiLang
{
	struct AstNode;
}

using namespace MagiLang;

namespace Memory
{
	struct StackFrame
	{
		void* location;
		char* pointer; //Points to end of last element
		uint16_t size;

		StackFrame()
		{
			location = nullptr;
			pointer = nullptr;
			size = 0;
		}

		StackFrame(uint16_t bytes) // StackFrame is not responsible for knowing the amount of uint16_t's needed.
		{
			location = malloc(bytes);
			pointer = (char*)location;
			size = bytes;
		}

		void* push(uint16_t bytes)
		{
			if (pointer + bytes > location + size)
            	return nullptr;
			
			pointer += bytes;
			
			return pointer - bytes;
		}

		// No pop(), hard to implement and I don't even need it

		~StackFrame()
		{
			if (location != nullptr)
				free(location);
		}
	};

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

	//TODO: remove
	/*struct memNode
	{
		memNode* MEMparent = nullptr;
		astNode* ASTparent = nullptr;
		StackFrame stack ;

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

		friend std::ostream& operator<<(std::ostream& os, const memNode& n) 
		{
			os << "{memNode} ";
			os << "MEMparent: " << n.MEMparent << ", ASTparent: " << n.ASTparent << "\n";

			

			return os;
		}

		friend std::wostream& operator<<(std::wostream& os, const memNode& n) 
		{
			os << L"{memNode} ";
			os << L"MEMparent: " << n.MEMparent << L", ASTparent: " << n.ASTparent << L"\n";

			

			return os;
		}
	};*/
}