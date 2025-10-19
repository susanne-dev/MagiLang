#pragma once

#include <iostream>
#include <vector>
#include <fcntl.h>
#include <variant>
#ifdef _WIN32
	#include <io.h>
#endif
#include "memory.hpp"
#include "token.hpp"
#include "errorClass.hpp"
#include "mglError.hpp"

namespace MagiLang
{
	struct AstNode
	{
		AstNode* parent = nullptr; //Not being set 
		std::vector<AstNode*> nodes = std::vector<AstNode*>();
		uint32_t location[4];
		Token::token_type type;
		std::string chars;
		bool bad = false;

		void append(AstNode* node)
		{
			nodes.push_back(node);
			node->parent = this;
		}

		AstNode(Token* token)
		{
			location[0] = token->location[0];
			location[1] = token->location[1];
			location[3] = -1;
			location[4] = -1;

			chars = token->chars;
			
			type = token->type;
		}
		AstNode(Token token)
		{
			location[0] = token.location[0];
			location[1] = token.location[1];
			location[3] = -1;
			location[4] = -1;

			chars = token.chars;

			type = token.type;
		}

		AstNode()
		{
			location[0] = -1;
			location[1] = -1;
			location[3] = -1;
			location[4] = -1;

			type = Token::ROOT;
		}

		virtual ~AstNode()
		{
			for (AstNode* node : nodes)
			{
				delete node;
			}
		}

		operator std::string() const {
			std::string loc;
			if (type == Token::PAREN || type == Token::BRACK || type == Token::BRACE || type == Token::COMMENT) { loc = "S_Line[" + std::to_string(location[0]) + "] S_Col[" + std::to_string(location[1] - 1) + "] E_Line[" + std::to_string(location[2]) + "] E_Col[" + std::to_string(location[3]) + "]"; }
			else { loc = "Line[" + std::to_string(location[0]) + "] Col[" + std::to_string(location[1]) + "]"; }
			return "{Nodes: " + std::to_string(nodes.size()) + "} {Type: " + Token::token_type_names[type] + " } {Chars: " + chars + "} {Location: " + loc + "}";
		}

		//bool operator==(const astNode &node) { return node.nodes == nodes && node.expectedTypes == expectedTypes && node.t == t && node.modifier == modifier && node.storage == storage; }

		friend std::ostream& operator<<(std::ostream& os, const AstNode& n) {
			std::string loc;
			if (n.type == Token::PAREN || n.type == Token::BRACK || n.type == Token::BRACE || n.type == Token::COMMENT) { loc = "S_Line[" + std::to_string(n.location[0]) + "] S_Col[" + std::to_string(n.location[1] - 1) + "] E_Line[" + std::to_string(n.location[2]) + "] E_Col[" + std::to_string(n.location[3]) + "]"; }
			else { loc = "Line[" + std::to_string(n.location[0]) + "] Col[" + std::to_string(n.location[1]) + "]"; }
			return os << "{Nodes: " + std::to_string(n.nodes.size()) + "} {Type: " + Token::token_type_names[n.type] + " } {Char: " + n.chars + "} {Location: " + loc + "}";
		}
	};

	struct AstNodeConst : public AstNode
	{
		//Arrays not implemented
		using Value = std::variant<
			int8_t,  int16_t,  int32_t,  int64_t,
			uint8_t, uint16_t, uint32_t, uint64_t,
			_Float16, float,   double,
			bool,
			std::string
		>;
	};
	//if string then value is in .chars
	template <typename T>
	struct AstNodeVar : public AstNode
	{
		enum varNodeType
		{
			INT8,
			INT16,
			INT32,
			INT64,

			UINT8,
			UINT16,
			UINT32,
			UINT64,

			FLOAT16,
			FLOAT32,
			FLOAT64,

			BOOL,

			STRING,

			ARRAY,

			LIST
		};

		std::string varNodeTypeNames[15] = 
		{
			"INT8",
			"INT16",
			"INT32",
			"INT64",

			"UINT8",
			"UINT16",
			"UINT32",
			"UINT64",

			"FLOAT16",
			"FLOAT32",
			"FLOAT64",

			"BOOL",

			"STRING",

			"ARRAY",

			"LIST"
		};

		std::uint8_t bytesLookup[12] = 
		{
			1,
			2,
			4,
			8,

			1,
			2,
			4,
			8,

			2,
			4,
			8,

			1
		};

		T* value = nullptr;

		AstNodeVar(Token* token) : AstNode(t)

		uint16_t byteCount()
		{
			return bytesLookup[type];
		}
	};

	/*struct astNodeStr : public astNode
	{
		std::string value;

		operator std::string() const {
			std::string loc;
			if (type == token::PAREN || type == token::BRACK || type == token::BRACE || type == token::COMMENT) { loc = "S_Line[" + std::to_string(location[0]) + "] S_Col[" + std::to_string(location[1] - 1) + "] E_Line[" + std::to_string(location[2]) + "] E_Col[" + std::to_string(location[3]) + "]"; }
			else { loc = "Line[" + std::to_string(location[0]) + "] Col[" + std::to_string(location[1]) + "]"; }
			return "{Nodes: " + std::to_string(nodes.size()) + "} {Type: " + token::token_type_names[type] + " } {Chars: " + chars + "} {String: " + value + " } {Location: " + loc + "}";
		}

		friend std::ostream& operator<<(std::ostream& os, const astNodeStr& n) {
			std::string loc;
			if (n.type == token::PAREN || n.type == token::BRACK || n.type == token::BRACE || n.type == token::COMMENT) { loc = "S_Line[" + std::to_string(n.location[0]) + "] S_Col[" + std::to_string(n.location[1] - 1) + "] E_Line[" + std::to_string(n.location[2]) + "] E_Col[" + std::to_string(n.location[3]) + "]"; }
			else { loc = "Line[" + std::to_string(n.location[0]) + "] Col[" + std::to_string(n.location[1]) + "]"; }
			return os << "{Nodes: " + std::to_string(n.nodes.size()) + "} {Type: " + token::token_type_names[n.type] + " } {Char: " + n.chars + "} {String: " + n.value + " } {Location: " + loc + "}";
		}
	};*/

	struct AstNodeMem : public AstNode
	{
		StackFrame stack;
		AstNodeMem* memParent = nullptr;

		AstNodeMem(AstNode node)
		{
			parent = node.parent;
			nodes = node.nodes;
			location[0] = node.location[0];
			location[1] = node.location[1];
			location[2] = node.location[2];
			location[3] = node.location[3];
			type = node.type;
			chars = node.chars;
		}

		AstNodeMem()
		{

		}

		operator std::string() const {
			std::string loc;
			if (type == Token::PAREN || type == Token::BRACK || type == Token::BRACE || type == Token::COMMENT) { loc = "S_Line[" + std::to_string(location[0]) + "] S_Col[" + std::to_string(location[1] - 1) + "] E_Line[" + std::to_string(location[2]) + "] E_Col[" + std::to_string(location[3]) + "]"; }
			else { loc = "Line[" + std::to_string(location[0]) + "] Col[" + std::to_string(location[1]) + "]"; }
			return "{MEM capable} {Nodes: " + std::to_string(nodes.size()) + "} {Type: " + Token::token_type_names[type] + " } {Chars: " + chars + "} {Location: " + loc + "}";
		}

		friend std::ostream& operator<<(std::ostream& os, const AstNodeMem& n) {
			std::string loc;
			if (n.type == Token::PAREN || n.type == Token::BRACK || n.type == Token::BRACE || n.type == Token::COMMENT) { loc = "S_Line[" + std::to_string(n.location[0]) + "] S_Col[" + std::to_string(n.location[1] - 1) + "] E_Line[" + std::to_string(n.location[2]) + "] E_Col[" + std::to_string(n.location[3]) + "]"; }
			else { loc = "Line[" + std::to_string(n.location[0]) + "] Col[" + std::to_string(n.location[1]) + "]"; }
			return os << "{MEM capable} {Nodes: " + std::to_string(n.nodes.size()) + "} {Type: " + Token::token_type_names[n.type] + " } {Char: " + n.chars + "} {Location: " + loc + "}";
		}
	};

	/*Memory::memNode* getMEM(astNode* node) //Travel up AST and return first memory capable node's memory
	{
		if (node->type == token::BRACE || node->type == token::ROOT)
		{
			return ((astNodeMem*)node)->memory;
		}
		else
		{
			return getMEM(node->parent);
		}
	}*/

#ifdef _WIN32
	void printAST(std::wstring prefix, const astNode& node, bool isEnd, int counter, std::map<std::string, bool> mode)
	{
		std::wcout << prefix;

		std::wcout << (isEnd ? L"├──" : L"└──");

		std::string s = mode["hardcore"] ? std::to_string(counter) + "   " : "";

		s += node.type == token::STRING && mode["hardcore"] ? std::string(*(astNodeStr*)&node) : std::string(node) + "\t";

		std::wstring wide_string;
		wide_string.assign(s.begin(), s.end());
		if (mode["hardcore"] == true)
		{
			std::wcout << wide_string;
			std::wcout << &node << std::endl;
		}
		else
		{
			std::wcout << wide_string << std::endl;
		}

		if (node.nodes.size() > 0)
		{
			int counter = 1;
			for (int i = 0; i < node.nodes.size(); i++)
			{
				if (counter == node.nodes.size())
					printAST(prefix + (isEnd ? L"│   " : L"    "), *node.nodes[i], false, i, mode);
				else
					printAST(prefix + (isEnd ? L"│   " : L"    "), *node.nodes[i], true, i, mode);
				counter++;
			}
		}
	}
#else
	void printAST(std::string prefix, const AstNode& node, bool isEnd, int counter, std::map<std::string, bool> mode)
	{

		std::cout << prefix;

		std::cout << (isEnd ? "├──" : "└──");

		std::string s = mode["hardcore"] ? std::to_string(counter) + "   " + std::string(node) + "\t" : std::string(node) + "\t";

		std::wstring wide_string;
		wide_string.assign(s.begin(), s.end());
		if (mode["hardcore"])
		{
			std::wcout << wide_string;
			std::wcout << &node << std::endl;
		}
		else
		{
			std::wcout << wide_string << std::endl;
		}

		if (node.nodes.size() > 0)
		{
			int counter = 1;
			for (int i = 0; i < node.nodes.size(); i++)
			{
				if (counter == node.nodes.size())
					printAST(prefix + (isEnd ? "│   " : "    "), *node.nodes[i], false, i, mode);
				else
					printAST(prefix + (isEnd ? "│   " : "    "), *node.nodes[i], true, i, mode);
				counter++;
			}
		}
	}
#endif

	void printAST(const AstNode& node, std::string prefix, std::map<std::string, bool> mode)
	{
#ifdef _WIN32
		int outmode = _setmode(_fileno(stdout), _O_U16TEXT);
		printAST(std::wstring(prefix.begin(), prefix.end()), node, false, 0, mode);
		_setmode(_fileno(stdout), outmode);
#else
		printAST(prefix, node, false, 0, mode);
#endif
	}
}