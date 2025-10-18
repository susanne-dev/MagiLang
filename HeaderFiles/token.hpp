#pragma once

#include <iostream>
#include <string>
#include <sstream>

namespace ObjectCalc
{
	void replaceAll(std::string& in, std::string remove, std::string replace)
	{
		int i = 0;
		int iLength = remove.length();
		while (true)
		{
			i = in.find(remove, i);
			if (i == std::string::npos)
				break;

			in.replace(i, iLength, replace);

			i += iLength;
		}
	}
	std::string unEscapeString(std::string in)
	{
		std::string out;

		for (auto ch : in)
		{
			switch (ch)
			{
			case '\'':
				out += "\\'";
				break;

			case '\"':
				out += "\\\"";
				break;

			case '\?':
				out += "\\?";
				break;

			case '\\':
				out += "\\\\";
				break;

			case '\a':
				out += "\\a";
				break;

			case '\b':
				out += "\\b";
				break;

			case '\f':
				out += "\\f";
				break;

			case '\n':
				out += "\\n";
				break;

			case '\r':
				out += "\\r";
				break;

			case '\t':
				out += "\\t";
				break;

			case '\v':
				out += "\\v";
				break;

			default:
				out += ch;
			}
		}
		return out;
	}

	void unEscapeString(std::string& out, std::string in)
	{
		for (auto ch : in)
		{
			switch (ch)
			{
			case '\'':
				out += "\\'";
				break;

			case '\"':
				out += "\\\"";
				break;

			case '\?':
				out += "\\?";
				break;

			case '\\':
				out += "\\\\";
				break;

			case '\a':
				out += "\\a";
				break;

			case '\b':
				out += "\\b";
				break;

			case '\f':
				out += "\\f";
				break;

			case '\n':
				out += "\\n";
				break;

			case '\r':
				out += "\\r";
				break;

			case '\t':
				out += "\\t";
				break;

			case '\v':
				out += "\\v";
				break;

			default:
				out += ch;
			}
		}
	}

	void escapeString(std::string& out, std::string in)
	{
		out = in;
		
		replaceAll(out, "\\\'", "\'");
		replaceAll(out, "\\\"", "\"");
		replaceAll(out, "\\\?", "\?");
		replaceAll(out, "\\\\", "\\");
		replaceAll(out, "\\a", "\a");
		replaceAll(out, "\\b", "\b");
		replaceAll(out, "\\f", "\f");
		replaceAll(out, "\\n", "\n");
		replaceAll(out, "\\r", "\r");
		replaceAll(out, "\\t", "\t");
		replaceAll(out, "\\v", "\v");
	}

	std::string escapeString(std::string in)
	{
		std::string out = in;

		replaceAll(out, "\\\'", "\'");
		replaceAll(out, "\\\"", "\"");
		replaceAll(out, "\\\?", "\?");
		replaceAll(out, "\\\\", "\\");
		replaceAll(out, "\\a", "\a");
		replaceAll(out, "\\b", "\b");
		replaceAll(out, "\\f", "\f");
		replaceAll(out, "\\n", "\n");
		replaceAll(out, "\\r", "\r");
		replaceAll(out, "\\t", "\t");
		replaceAll(out, "\\v", "\v");

		return out;
	}

	struct token
	{
		enum token_type
		{
			COMMENT,
			NUMBER,
			DECIMAL,
			STRING,
			BOOL,
			LIST,
			BINARY_OPERATOR,
			UNARY_OPERATOR,
			TYPE,
			OBJECTCALL,
			VARIABLE,
			TAG,
			IF,
			ELSE,
			LPAREN,
			RPAREN,
			PAREN,
			LBRACE,
			RBRACE,
			BRACE,
			LBRACK,
			RBRACK,
			BRACK,
			COMMA,
			DOT,
			SEMICOLON,
			GOTO,
			LAST,
			UNKNOWN,
			ROOT
		};

		static std::string token_type_names[30];



		token_type type {token_type::UNKNOWN};
		std::string chars;
		int location[4];



		token()
		{
			location[0] = -1;
			location[1] = -1;
			location[2] = -1;
			location[3] = -1;
		}
		token(token* t)
		{
			type = t->type;
			location[0] = t->location[0];
			location[1] = t->location[1];
			location[2] = t->location[2];
			location[3] = t->location[3];
		}
		token(int (l)[])
		{
			location[0] = l[0];
			location[1] = l[1];
			location[2] = l[2];
			location[3] = l[3];
		}

		static token_type typePrecedence(token_type t1, token_type t2)
		{
			return t1 > t2 ? t1 : t2;
		}
		
		operator std::string() const
		{ 
			return "{Type: " + token_type_names[type] + "} {Value: " + chars + "} {Line: " + std::to_string(location[0]) + ", Char: " + std::to_string(location[1]) + "}"; 
		}

		friend std::ostream& operator<<(std::ostream& os, const token& t) 
		{
			return os << "{Type: " + t.token_type_names[t.type] + "} {Value: " + t.chars + "} {Line: " + std::to_string(t.location[0]) + ", Char : " + std::to_string(t.location[1]) + "}";
		}

		bool operator == (const token& t) const
		{
			return (type == t.type && location[0] == t.location[0] && location[1] == t.location[1]);
		}
	};

	std::string token::token_type_names[30] = {
		"COMMENT",
		"NUMBER",
		"DECIMAL",
		"STRING",
		"BOOL",
		"LIST",
		"BINARY_OPERATOR", // + - / * etc
		"UNARY_OPERATOR", // ++ -- etc
		"TYPE",
		"OBJECTCALL",
		"VARIABLE",
		"TAG",
		"IF",
		"ELSE",
		"LPAREN",
		"RPAREN",
		"PAREN",
		"LBRACE",
		"RBRACE",
		"BRACE",
		"LBRACK",
		"RBRACK",
		"BRACK",
		"COMMA",
		"DOT",
		"SEMICOLON",
		"GOTO",
		"LAST",
		"UNKNOWN",
		"ROOT"
	};
}