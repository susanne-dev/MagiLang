#include "node.hpp"
#include "errorClass.hpp"
#include "oclcError.hpp"

/*
		* Check that each node is of appropriate type															N
		* Check compatability																					N
		* Math																									N
		* Set memory																							N
		* Read memory																							N
		* Struct that contains registers and memory																N
		* Register definition																					N
			* Union of all four types
		* No other file than this one should access memory. Last time that happened everything was a mess.		Y & N
		* If an operation like = fails. The previous value should remain. I will not add NONE type
		* Memory tree paralell to AST																			N
		* When are they made and destroyed? Made by astNode creation?
		* Step by step int i = 5;
			* Check that name is <= 100 chrs.
			* Find first memory capable parent node
			* search MEMtree to find if name is already taken
				TRUE
				* ???
				FALSE
				* Go back to first memory capable parent node and reserve name and
				
		* Maybe do include multiple steps
*/

using namespace Memory;
using namespace ObjectCalc;

namespace Interpreter
{
	template <typename T>
	T getValue(astNode* node)
	{
		switch (n->type)
		{
		case ObjectCalc::token::NUMBER:
			break;
		case ObjectCalc::token::DECIMAL:
			break;
		case ObjectCalc::token::STRING:
			break;
		case ObjectCalc::token::BOOL:
			break;
		case ObjectCalc::token::LIST:
			break;
		case ObjectCalc::token::BINARY_OPERATOR:
			break;
		case ObjectCalc::token::UNARY_OPERATOR:
			break;
		case ObjectCalc::token::OBJECTCALL:
			break;
		case ObjectCalc::token::VARIABLE:
			break;
		case ObjectCalc::token::PAREN:
			break;
		default:
			break;
		}
	}

	void preRun(astNode* root, std::vector<errorClass>& errorList)
	{
		for each (astNode * n in root->nodes)
		{
			std::cout << token::token_type_names[n->type] << std::endl;

			switch (n->type)
			{
			case ObjectCalc::token::NUMBER:
				break;
			case ObjectCalc::token::DECIMAL:
				break;
			case ObjectCalc::token::STRING:
				break;
			case ObjectCalc::token::BOOL:
				break;
			case ObjectCalc::token::LIST:
				break;
			case ObjectCalc::token::BINARY_OPERATOR:
				break;
			case ObjectCalc::token::UNARY_OPERATOR:
				break;
			case ObjectCalc::token::TYPE:
				break;
			case ObjectCalc::token::IF:
				break;
			case ObjectCalc::token::ELSE:
				break;
			case ObjectCalc::token::OBJECTCALL:
				break;
			case ObjectCalc::token::VARIABLE:
				break;
			case ObjectCalc::token::RPAREN:
				errorList.push_back(errorClass("", n->location));
				break;
			case ObjectCalc::token::PAREN:
				break;
			case ObjectCalc::token::RBRACE:
				errorList.push_back(errorClass("", n->location));
				break;
			case ObjectCalc::token::BRACE:
				((astNodeMem*)n)->memory->MEMparent = getMEM(root);
				break;
			case ObjectCalc::token::RBRACK:
				errorList.push_back(errorClass("", n->location));
				break;
			case ObjectCalc::token::BRACK:
				break;
			case ObjectCalc::token::COMMA:
				break;
			case ObjectCalc::token::DOT:
				break;
			case ObjectCalc::token::SEMICOLON:
				break;
			case ObjectCalc::token::GOTO:
				break;
			case ObjectCalc::token::UNKNOWN:
				errorList.push_back(errorClass("", n->location));
				break;
			default:
				break;
			}
		}
	};

	void freeMEM(std::vector<memNode*> list)
	{
		for each (memNode* node in list)
		{
			delete node;
		}
	};

	void interpret(astNode* root, std::vector<errorClass>& errorList)
	{
		for each (astNode* n in root->nodes)
		{
			std::cout << token::token_type_names[n->type] << std::endl;

			if (n->bad) continue;

			switch (n->type)
			{
			case ObjectCalc::token::NUMBER:
				std::cout << ((astNodeInt*)n)->value << std::endl;
				break;
			case ObjectCalc::token::DECIMAL:
				std::cout << ((astNodeDec*)n)->value << std::endl;
				break;
			case ObjectCalc::token::STRING:
				std::cout << ((astNodeStr*)n)->value << std::endl;
				break;
			case ObjectCalc::token::BOOL:
				std::cout << ((astNodeBool*)n)->value << std::endl;
				break;
			case ObjectCalc::token::LIST:
				break;
			case ObjectCalc::token::BINARY_OPERATOR:
				interpret(n, errorList);
				break;
			case ObjectCalc::token::UNARY_OPERATOR:
				break;
			case ObjectCalc::token::TYPE:
				break;
			case ObjectCalc::token::IF:
				break;
			case ObjectCalc::token::ELSE:
				break;
			case ObjectCalc::token::OBJECTCALL:
				break;
			case ObjectCalc::token::VARIABLE:
				break;
			case ObjectCalc::token::RPAREN:
				break;
			case ObjectCalc::token::PAREN:
				break;
			case ObjectCalc::token::RBRACE:
				break;
			case ObjectCalc::token::BRACE:
				break;
			case ObjectCalc::token::RBRACK:
				break;
			case ObjectCalc::token::BRACK:
				break;
			case ObjectCalc::token::COMMA:
				break;
			case ObjectCalc::token::DOT:
				break;
			case ObjectCalc::token::SEMICOLON:
				break;
			case ObjectCalc::token::GOTO:
				break;
			case ObjectCalc::token::UNKNOWN:
				break;
				break;
			default:
				break;
			}
		}
	};
}

namespace Memory
{

	///
	/// NOTE: printMEM prints from leaf to root
	/// 

#ifdef _WIN32
	void printMEM(memNode* node, int& counter, std::map<std::string, bool> mode)
	{
		if (node->MEMparent != nullptr)
			printMEM(node->MEMparent, counter, mode);

		for (int i = 0; i < counter; i++)
		{
			std::wcout << L"    ";
		}
		counter++;

		std::wcout << L"└──";

		std::string s = mode["hardcore"] ? std::to_string(counter) + "   " + std::string(*node) + "\t" : std::string(*node) + "\t";

		std::wstring wide_string;
		wide_string.assign(s.begin(), s.end());
		if (mode["hardcore"] == true)
		{
			std::wcout << wide_string;
			std::wcout << node << std::endl;
		}
		else
		{
			std::wcout << wide_string << std::endl;
		}
	}
#else
	void printMEM(const memNode& node, int counter, std::string mode)
	{
		if (node->MEMparent != nullptr)
			printMEM(node->MEMparent, counter, mode);

		for (int i = 0; i < counter; i++)
		{
			std::cout << L"    ";
		}
		counter++;

		std::cout << "└──";

		std::string s = mode["hardcore"] ? std::to_string(counter) + "   " + std::string(node) + "\t" : std::string(node) + "\t";

		std::wstring wide_string;
		wide_string.assign(s.begin(), s.end());
		if (mode["hardcore"])
		{
			std::wcout << wide_string;
			std::wcout << node << std::endl;
		}
		else
		{
			std::wcout << wide_string << std::endl;
		}
	}
#endif

	void printMEM(memNode* node, std::map<std::string, bool> mode)
	{
		int counter = 0;
#ifdef _WIN32
		int outmode = _setmode(_fileno(stdout), _O_U16TEXT);
		printMEM(node, counter, mode);
		_setmode(_fileno(stdout), outmode);
#else
		printMEM(node, counter, mode);
#endif
	}

	void printMEM(astNode* astnode, std::map<std::string, bool> mode)
	{
		memNode* node;
		switch (astnode->type)
		{
		case token::LPAREN:
		case token::PAREN:
		case token::RPAREN:
		case token::LBRACK:
		case token::BRACK:
		case token::RBRACK:
		case token::LBRACE:
		case token::BRACE:
		case token::RBRACE:
		case token::ROOT:
			node = ((astNodeMem*)astnode)->memory;
			break;
		default:
			printMEM(astnode->parent, mode);
			break;
		}
		int counter = 0;
#ifdef _WIN32
		int outmode = _setmode(_fileno(stdout), _O_U16TEXT);
		printMEM(node, counter, mode);
		_setmode(_fileno(stdout), outmode);
#else
		printMEM(node, counter, mode);
#endif
	}
}