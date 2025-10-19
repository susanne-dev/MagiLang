#include "node.hpp"
#include "errorClass.hpp"
#include "mglError.hpp"

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
using namespace MagiLang;

namespace Interpreter
{
	template <typename T>
	T getValue(astNode* node)
	{
		switch (node->type)
		{
		case MagiLang::token::NUMBER:
			break;
		case MagiLang::token::DECIMAL:
			break;
		case MagiLang::token::STRING:
			break;
		case MagiLang::token::BOOL:
			break;
		case MagiLang::token::LIST:
			break;
		case MagiLang::token::BINARY_OPERATOR:
			break;
		case MagiLang::token::UNARY_OPERATOR:
			break;
		case MagiLang::token::OBJECTCALL:
			break;
		case MagiLang::token::VARIABLE:
			break;
		case MagiLang::token::PAREN:
			break;
		default:
			break;
		}
	}

	void preRun(astNode* root, std::vector<errorClass>& errorList)
	{
		for (astNode * node : root->nodes)
		{
			std::cout << token::token_type_names[node->type] << std::endl;

			switch (node->type)
			{
			case MagiLang::token::NUMBER:
				break;
			case MagiLang::token::DECIMAL:
				break;
			case MagiLang::token::STRING:
				break;
			case MagiLang::token::BOOL:
				break;
			case MagiLang::token::LIST:
				break;
			case MagiLang::token::BINARY_OPERATOR:
				break;
			case MagiLang::token::UNARY_OPERATOR:
				break;
			case MagiLang::token::TYPE:
				break;
			case MagiLang::token::IF:
				break;
			case MagiLang::token::ELSE:
				break;
			case MagiLang::token::OBJECTCALL:
				break;
			case MagiLang::token::VARIABLE:
				break;
			case MagiLang::token::RPAREN:
				errorList.push_back(errorClass("", node->location));
				break;
			case MagiLang::token::PAREN:
				break;
			case MagiLang::token::RBRACE:
				errorList.push_back(errorClass("", node->location));
				break;
			case MagiLang::token::BRACE:
				((astNodeMem*)node)->memory->MEMparent = getMEM(root);
				break;
			case MagiLang::token::RBRACK:
				errorList.push_back(errorClass("", node->location));
				break;
			case MagiLang::token::BRACK:
				break;
			case MagiLang::token::COMMA:
				break;
			case MagiLang::token::DOT:
				break;
			case MagiLang::token::SEMICOLON:
				break;
			case MagiLang::token::GOTO:
				break;
			case MagiLang::token::UNKNOWN:
				errorList.push_back(errorClass("", node->location));
				break;
			default:
				break;
			}
		}
	};

	void freeMEM(std::vector<memNode*> list)
	{
		for (memNode* node : list) // LOOK HERE: this said astNode* node before. If memory leaks occur look here
		{
			delete node;
		}
	};

	void interpret(astNode* root, std::vector<errorClass>& errorList)
	{
		for (astNode* node : root->nodes)
		{
			std::cout << token::token_type_names[node->type] << std::endl;

			if (node->bad) continue;

			switch (node->type)
			{
			case MagiLang::token::NUMBER:
				std::cout << ((astNodeInt*)node)->value << std::endl;
				break;
			case MagiLang::token::DECIMAL:
				std::cout << ((astNodeDec*)node)->value << std::endl;
				break;
			case MagiLang::token::STRING:
				std::cout << ((astNodeStr*)node)->value << std::endl;
				break;
			case MagiLang::token::BOOL:
				std::cout << ((astNodeBool*)node)->value << std::endl;
				break;
			case MagiLang::token::LIST:
				break;
			case MagiLang::token::BINARY_OPERATOR:
				interpret(node, errorList);
				break;
			case MagiLang::token::UNARY_OPERATOR:
				break;
			case MagiLang::token::TYPE:
				break;
			case MagiLang::token::IF:
				break;
			case MagiLang::token::ELSE:
				break;
			case MagiLang::token::OBJECTCALL:
				break;
			case MagiLang::token::VARIABLE:
				break;
			case MagiLang::token::RPAREN:
				break;
			case MagiLang::token::PAREN:
				break;
			case MagiLang::token::RBRACE:
				break;
			case MagiLang::token::BRACE:
				break;
			case MagiLang::token::RBRACK:
				break;
			case MagiLang::token::BRACK:
				break;
			case MagiLang::token::COMMA:
				break;
			case MagiLang::token::DOT:
				break;
			case MagiLang::token::SEMICOLON:
				break;
			case MagiLang::token::GOTO:
				break;
			case MagiLang::token::UNKNOWN:
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
	void printMEM(const memNode& node, int counter, std::map<std::string, bool> mode)
	{
		if (node.MEMparent != nullptr)
			printMEM(*node.MEMparent, counter, mode);

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

	void printMEM(memNode* node, int counter, std::map<std::string, bool> mode)
	{
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