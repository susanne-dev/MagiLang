#pragma once

#include <iostream>
#include <vector>
#include <fcntl.h>
#ifdef _WIN32
	#include <io.h>
#endif
#include "memory.hpp"
#include "token.hpp"
#include "errorClass.hpp"
#include "oclcError.hpp"

namespace ObjectCalc
{
	struct astNode
	{
		astNode* parent = nullptr; //Not being set 
		std::vector<astNode*> nodes = std::vector<astNode*>();
		int location[4];
		token::token_type type;
		std::string chars;
		bool bad = false;

		void append(astNode* node)
		{
			nodes.push_back(node);
			node->parent = this;
		}

		astNode(token* t_)
		{
			location[0] = t_->location[0];
			location[1] = t_->location[1];
			location[3] = -1;
			location[4] = -1;

			chars = t_->chars;
			
			type = t_->type;
		}
		astNode(token t_)
		{
			location[0] = t_.location[0];
			location[1] = t_.location[1];
			location[3] = -1;
			location[4] = -1;

			chars = t_.chars;

			type = t_.type;
		}

		astNode()
		{
			location[0] = -1;
			location[1] = -1;
			location[3] = -1;
			location[4] = -1;

			type = token::ROOT;
		}

		virtual ~astNode()
		{
			for each (astNode* node in nodes)
			{
				delete node;
			}
		}

		operator std::string() const {
			std::string loc;
			if (type == token::PAREN || type == token::BRACK || type == token::BRACE || type == token::COMMENT) { loc = "S_Line[" + std::to_string(location[0]) + "] S_Col[" + std::to_string(location[1] - 1) + "] E_Line[" + std::to_string(location[2]) + "] E_Col[" + std::to_string(location[3]) + "]"; }
			else { loc = "Line[" + std::to_string(location[0]) + "] Col[" + std::to_string(location[1]) + "]"; }
			return "{Nodes: " + std::to_string(nodes.size()) + "} {Type: " + token::token_type_names[type] + " } {Chars: " + chars + "} {Location: " + loc + "}";
		}

		//bool operator==(const astNode &node) { return node.nodes == nodes && node.expectedTypes == expectedTypes && node.t == t && node.modifier == modifier && node.storage == storage; }

		friend std::ostream& operator<<(std::ostream& os, const astNode& n) {
			std::string loc;
			if (n.type == token::PAREN || n.type == token::BRACK || n.type == token::BRACE || n.type == token::COMMENT) { loc = "S_Line[" + std::to_string(n.location[0]) + "] S_Col[" + std::to_string(n.location[1] - 1) + "] E_Line[" + std::to_string(n.location[2]) + "] E_Col[" + std::to_string(n.location[3]) + "]"; }
			else { loc = "Line[" + std::to_string(n.location[0]) + "] Col[" + std::to_string(n.location[1]) + "]"; }
			return os << "{Nodes: " + std::to_string(n.nodes.size()) + "} {Type: " + token::token_type_names[n.type] + " } {Char: " + n.chars + "} {Location: " + loc + "}";
		}
	};

	struct astNodeInt : public astNode
	{
		long long value;
	};
	struct astNodeDec : public astNode
	{
		long double value;
	};
	struct astNodeStr : public astNode
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
	};
	struct astNodeBool : public astNode
	{
		bool value;
	};
	struct astNodeMem : public astNode
	{
		Memory::memNode* memory = new Memory::memNode(this);

		astNodeMem(astNode node)
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

		astNodeMem()
		{

		}

		~astNodeMem() override
		{	
			delete memory;

			for each (astNode * node in nodes)
			{
				delete node;
			}	
		}

		operator std::string() const {
			std::string loc;
			if (type == token::PAREN || type == token::BRACK || type == token::BRACE || type == token::COMMENT) { loc = "S_Line[" + std::to_string(location[0]) + "] S_Col[" + std::to_string(location[1] - 1) + "] E_Line[" + std::to_string(location[2]) + "] E_Col[" + std::to_string(location[3]) + "]"; }
			else { loc = "Line[" + std::to_string(location[0]) + "] Col[" + std::to_string(location[1]) + "]"; }
			return "{MEM capable} {Nodes: " + std::to_string(nodes.size()) + "} {Type: " + token::token_type_names[type] + " } {Chars: " + chars + "} {Location: " + loc + "}";
		}

		friend std::ostream& operator<<(std::ostream& os, const astNodeMem& n) {
			std::string loc;
			if (n.type == token::PAREN || n.type == token::BRACK || n.type == token::BRACE || n.type == token::COMMENT) { loc = "S_Line[" + std::to_string(n.location[0]) + "] S_Col[" + std::to_string(n.location[1] - 1) + "] E_Line[" + std::to_string(n.location[2]) + "] E_Col[" + std::to_string(n.location[3]) + "]"; }
			else { loc = "Line[" + std::to_string(n.location[0]) + "] Col[" + std::to_string(n.location[1]) + "]"; }
			return os << "{MEM capable} {Nodes: " + std::to_string(n.nodes.size()) + "} {Type: " + token::token_type_names[n.type] + " } {Char: " + n.chars + "} {Location: " + loc + "}";
		}
	};

	Memory::memNode* getMEM(astNode* node) //Travel up AST and return first memory capable node's memory
	{
		if (node->type == token::BRACE || node->type == token::ROOT)
		{
			return ((astNodeMem*)node)->memory;
		}
		else
		{
			return getMEM(node->parent);
		}
	}

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
	void printAST(std::string prefix, const astNode& node, bool isEnd, int counter, std::string mode)
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
					printAST(prefix + (isEnd ? "│   " : "    "), node.nodes[i], false, i, mode);
				else
					printAST(prefix + (isEnd ? "│   " : "    "), node.nodes[i], true, i, mode);
				counter++;
			}
		}
	}
#endif

	void printAST(const astNode& node, std::string prefix, std::map<std::string, bool> mode)
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