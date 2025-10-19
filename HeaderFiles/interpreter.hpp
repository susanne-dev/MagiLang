#include "node.hpp"
#include "errorClass.hpp"
#include "mglError.hpp"

using namespace Memory;
using namespace MagiLang;

namespace Interpreter
{
    void preRun(AstNode* parent, memNode* memParent, std::vector<errorClass>& errorList, uint16_t &bytes)
    {
        for (AstNode * node : parent->nodes)
		{
			std::cout << Token::token_type_names[node->type] << std::endl;

			switch (node->type)
			{
			case MagiLang::Token::VARIABLE:
                //add to bytes
				break;
			case MagiLang::Token::BRACE:
				uint16_t localBytes = 0;
                preRun(node, (memNode*)node, errorList, localBytes);
                ((memNode*)node)->stack = StackFrame(localBytes);
                ((memNode*)node)->MEMparent = memParent;
				break;
			case MagiLang::Token::RPAREN:
			case MagiLang::Token::LPAREN:
			case MagiLang::Token::RBRACE:
			case MagiLang::Token::LBRACE:
			case MagiLang::Token::RBRACK:
			case MagiLang::Token::LBRACK:
			case MagiLang::Token::UNKNOWN:
				errorList.push_back(errorClass("", node->location));
				break;
			default:
                preRun(node, memParent, errorList, bytes);
				break;
			}
		}
    }
}