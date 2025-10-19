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
	T getValue(AstNode* node)
	{
		switch (node->type)
		{
		case MagiLang::Token::NUMBER:
			break;
		case MagiLang::Token::DECIMAL:
			break;
		case MagiLang::Token::STRING:
			break;
		case MagiLang::Token::BOOL:
			break;
		case MagiLang::Token::LIST:
			break;
		case MagiLang::Token::BINARY_OPERATOR:
			break;
		case MagiLang::Token::UNARY_OPERATOR:
			break;
		case MagiLang::Token::FUNCTIONCALL:
			break;
		case MagiLang::Token::VARIABLE:
			break;
		case MagiLang::Token::PAREN:
			break;
		default:
			break;
		}
	}

	void preRun(AstNode* root, std::vector<errorClass>& errorList)
	{
		for (AstNode * node : root->nodes)
		{
			std::cout << Token::token_type_names[node->type] << std::endl;

			switch (node->type)
			{
			case MagiLang::Token::NUMBER:
				break;
			case MagiLang::Token::DECIMAL:
				break;
			case MagiLang::Token::STRING:
				break;
			case MagiLang::Token::BOOL:
				break;
			case MagiLang::Token::LIST:
				break;
			case MagiLang::Token::BINARY_OPERATOR:
				break;
			case MagiLang::Token::UNARY_OPERATOR:
				break;
			case MagiLang::Token::TYPE:
				break;
			case MagiLang::Token::IF:
				break;
			case MagiLang::Token::ELSE:
				break;
			case MagiLang::Token::FUNCTIONCALL:
				break;
			case MagiLang::Token::VARIABLE:
				break;
			case MagiLang::Token::RPAREN:
				errorList.push_back(errorClass("", node->location));
				break;
			case MagiLang::Token::PAREN:
				break;
			case MagiLang::Token::RBRACE:
				errorList.push_back(errorClass("", node->location));
				break;
			case MagiLang::Token::BRACE:
				((AstNodeMem*)node)->memory->MEMparent = getMEM(root);
				break;
			case MagiLang::Token::RBRACK:
				errorList.push_back(errorClass("", node->location));
				break;
			case MagiLang::Token::BRACK:
				break;
			case MagiLang::Token::COMMA:
				break;
			case MagiLang::Token::DOT:
				break;
			case MagiLang::Token::SEMICOLON:
				break;
			case MagiLang::Token::GOTO:
				break;
			case MagiLang::Token::UNKNOWN:
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

	void interpret(AstNode* root, std::vector<errorClass>& errorList)
	{
		for (AstNode* node : root->nodes)
		{
			std::cout << Token::token_type_names[node->type] << std::endl;

			if (node->bad) continue;

			switch (node->type)
			{
			case MagiLang::Token::NUMBER:
				std::cout << ((astNodeInt*)node)->value << std::endl;
				break;
			case MagiLang::Token::DECIMAL:
				std::cout << ((astNodeDec*)node)->value << std::endl;
				break;
			case MagiLang::Token::STRING:
				std::cout << ((astNodeStr*)node)->value << std::endl;
				break;
			case MagiLang::Token::BOOL:
				std::cout << ((astNodeBool*)node)->value << std::endl;
				break;
			case MagiLang::Token::LIST:
				break;
			case MagiLang::Token::BINARY_OPERATOR:
				interpret(node, errorList);
				break;
			case MagiLang::Token::UNARY_OPERATOR:
				break;
			case MagiLang::Token::TYPE:
				break;
			case MagiLang::Token::IF:
				break;
			case MagiLang::Token::ELSE:
				break;
			case MagiLang::Token::FUNCTIONCALL:
				break;
			case MagiLang::Token::VARIABLE:
				break;
			case MagiLang::Token::RPAREN:
				break;
			case MagiLang::Token::PAREN:
				break;
			case MagiLang::Token::RBRACE:
				break;
			case MagiLang::Token::BRACE:
				break;
			case MagiLang::Token::RBRACK:
				break;
			case MagiLang::Token::BRACK:
				break;
			case MagiLang::Token::COMMA:
				break;
			case MagiLang::Token::DOT:
				break;
			case MagiLang::Token::SEMICOLON:
				break;
			case MagiLang::Token::GOTO:
				break;
			case MagiLang::Token::UNKNOWN:
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

	void printMEM(AstNode* astnode, std::map<std::string, bool> mode)
	{
		memNode* node;
		switch (astnode->type)
		{
		case Token::LPAREN:
		case Token::PAREN:
		case Token::RPAREN:
		case Token::LBRACK:
		case Token::BRACK:
		case Token::RBRACK:
		case Token::LBRACE:
		case Token::BRACE:
		case Token::RBRACE:
		case Token::ROOT:
			node = ((AstNodeMem*)astnode)->memory;
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