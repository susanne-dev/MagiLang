%{
	#include <iostream>
	#include <vector>
	#include <string>
	#include <math.h>
	#include "HeaderFiles/errorClass.hpp"
	#include "HeaderFiles/node.hpp"
	#include "HeaderFiles/math.hpp"

	extern FILE *yyin;

	using namespace ObjectCalc;

    int yylex();
	void yyerror(const char* msg) {
      fprintf(stderr, "%s\n", msg);
   }

	astNodeMem* root;
	std::vector<ObjectCalc::errorClass>* errorList;

	#define YYERROR_VERBOSE 1

	/*void ifmem (astNode* parent, astNode* ifn)
	{
		if ()
		{
			if(ifn->nodes[1]->type == token::BRACE || ifn->nodes[1]->type == token::ROOT)
			{
				ifn->nodes[1]->memory->MEMparent = parent->memory;
			}
			if(ifn->nodes.size() == 3)
			{
				if(ifn->nodes[2]->type == token::BRACE || ifn->nodes[2]->type == token::ROOT)
				{
					ifn->nodes[2]->memory->MEMparent = parent->memory;
				}
			}
		}
		else
		{
			ifmem(parent->parent, ifn);
		}
	}*/
%}

%union
{
	ObjectCalc::astNode* node;
	ObjectCalc::astNodeMem* cnode;
	ObjectCalc::token* t;
}

%right<t> IF ELSE
%left<t> OPERATOR0
%left<t> OPERATOR1
%left<t> OPERATOR2
%left<t> OPERATOR3
%left<t> UNIOPERATOR0 UNIOPERATOR1
%left<t> DOT
%token<t> SEMICOLON COMMENT
%token<t> LPAREN RPAREN LBRACK RBRACK LBRACE RBRACE
%token<t> NAME TYPE TAG UNKNOWN END
%token<node> CONSTANT
%type<cnode> tree lparen lbrack lbrace paren brack brace
%type<node> node powroot muldiv addsub equal type template
%type<node> ifstmnt ifempty iffull

%locations
%code requires {
	#include "HeaderFiles/node.hpp"
	#include "HeaderFiles/token.hpp"
}

%%

tree			:	{ $$ = root; }
				|	tree node { $1->append($2); }
				|	tree brace { $1->append($2); }
				|	tree ifstmnt { $1->append($2); }
				| 	tree SEMICOLON { delete $2; }
				|	tree END { delete $2; YYACCEPT; }

lparen			:	LPAREN { $$ = new astNodeMem($1); delete $1; yylloc.first_line = $$->location[0]; yylloc.first_column = $$->location[1]; }
				|	lparen node { $1->append($2); }
paren			:	lparen RPAREN { $$ = $1; $$->location[2] = $2->location[0]; $$->location[3] = $2->location[1]; delete $2; $$->type = token::PAREN }
				|	lparen END { $$ = $1; $$->location[2] = $2->location[0]; $$->location[3] = $2->location[1]; }

lbrack			:	LBRACK { $$ = new astNodeMem($1); delete $1; }
				|	lbrack node { $1->append($2); }
brack			:	lbrack RBRACK { $$ = $1; $$->location[2] = $2->location[0]; $$->location[3] = $2->location[1]; delete $2; $$->type = token::BRACK }
				|	lbrack END { $$ = $1; $$->location[2] = $2->location[0]; $$->location[3] = $2->location[1]; }

lbrace			:	LBRACE { $$ = new astNodeMem($1); delete $1; }
				|	lbrace node { $1->append($2); }
				|	lbrace brace { $1->append($2); $2->memory->MEMparent = $1->memory; }
				| 	lbrace SEMICOLON { delete $2; }
brace			:	lbrace RBRACE { $$ = $1; $$->location[2] = $2->location[0]; $$->location[3] = $2->location[1]; delete $2; $$->type = token::BRACE; }
				|	lbrace END { $$ = $1; $$->location[2] = $2->location[0]; $$->location[3] = $2->location[1]; $$->type = token::BRACE;}

node			: 	node UNIOPERATOR0 { $$ = new astNode($2); delete $2; $$->append($1); }
				|	UNIOPERATOR1 node { $$ = new astNode($1); delete $1; $$->append($2); }
				|	UNKNOWN { $$ = new astNode($1); delete $1; }
				|	addsub { $$ = $1; } | muldiv { $$ = $1; } | powroot { $$ = $1;} | equal { $$ = $1; }
				|	type { $$ = $1; }
				|	TAG	{ $$ = new astNode($1); delete $1; }
				|	CONSTANT { $$ = $1; }
				|	NAME { $$ = new astNode($1); delete $1; }
				|	NAME paren { $$ = new astNode($1); $$->type = token::OBJECTCALL; delete $1; $$->append($2); }
				|	TYPE brace { $$ = $2; $$->type=token::UNKNOWN; } //NEEDS a new type for arrays
				|	paren { $$ = $1; } | brack { $$ = $1; } /*| brace { $$ = new astNodeMem(*$1); /*Assume it is a code container and not an array* } Actually nvm other idea might solve MEM linking problem*/
				//|	node SEMICOLON { $1->append(new astNode($2)); delete $2; }
				|	error { $$ = new astNode(); $$->type = token::UNKNOWN; $$->location[0] = yylloc.last_line; $$->location[1] = yylloc.last_column; $$->chars = yytext; } //NOTE possibly injected instead of replacing.

template		:	"<" TYPE ">" { $$ = new astNode($1); $$->type = token::OBJECTCALL; $$->append(new astNode($2)); delete $2;  }
				|	"<"	error ">" { $$ = new astNode($1); $$->type = token::OBJECTCALL; $$->append(new astNode($2)); delete $2; }

ifstmnt			:	iffull { $$ = $1; } 
				|	ifempty { $$ = $1; }

iffull			:	ifempty ELSE node { $$ = $1; astNode* node = new astNode($2); delete $2; node->append($3); }
				| 	ifempty ELSE brace { $$ = $1; astNode* node = new astNode($2); delete $2; node->append($3); }

ifempty			:	IF paren node { $$ = new astNode($1); delete $1; $$->append($2); $$->append($3); }
				|	IF paren brace { $$ = new astNode($1); delete $1; $$->append($2); $$->append($3); }

type			: 	TYPE NAME { $$ = new astNode($1); $$->append(new astNode($2)); delete $1; delete $2; }	//Var declaration
				| 	TYPE NAME paren brace { $$ = new astNode($1); $$->append(new astNode($2)); delete $1; delete $2; $$->append($3); $$->append($4); } //Object declaration
				


addsub			:	node OPERATOR0 node 
				{
					$$ = new astNode(*$2);
					delete $2;
					$$->append($1);
					$$->append($3);
				}
				/* |	SEMICOLON OPERATOR0 node 
				{
					$$ = new astNode(*$2);
					delete $2;
					$$->append($1);
					$$->append($3);
					delete $1;
					$$->bad = true;
				}
				|	node OPERATOR0 SEMICOLON 
				{
					$$ = new astNode(*$2);
					delete $2;
					$$->append($1);
					$$->append($3);
					delete $3;
					$$->bad = true;
				} */

muldiv			: 	node OPERATOR1 node 
				{
					$$ = new astNode(*$2);
					delete $2;
					$$->append($1);
					$$->append($3);
				}	
				/* |	SEMICOLON OPERATOR1 node 
				{
					$$ = new astNode(*$2);
					delete $2;
					$$->append($1);
					$$->append($3);
					delete $1;
					$$->bad = true;
				}
				|	node OPERATOR1 SEMICOLON 
				{
					$$ = new astNode(*$2);
					delete $2;
					$$->append($1);
					$$->append($3);
					delete $3;
					$$->bad = true;
				} */

powroot			:	node OPERATOR2 node 
				{
					$$ = new astNode(*$2);
					delete $2;
					$$->append($1);
					$$->append($3);
				}
				/* |	SEMICOLON OPERATOR2 node 
				{
					$$ = new astNode(*$2);
					delete $2;
					$$->append($1);
					$$->append($3);
					delete $1;
					$$->bad = true;
				}
				|	node OPERATOR2 SEMICOLON 
				{
					$$ = new astNode(*$2);
					delete $2;
					$$->append($1);
					$$->append($3);
					delete $3;
					$$->bad = true;
				} */

equal			:	node OPERATOR3 node 
				{
					$$ = new astNode(*$2);
					delete $2;
					$$->append($1);
					$$->append($3);
				}
				/* |	SEMICOLON OPERATOR3 node 
				{
					$$ = new astNode(*$2);
					delete $2;
					$$->append($1);
					$$->append($3);
					delete $1;
					$$->bad = true;
				}
				|	node OPERATOR3 SEMICOLON 
				{
					$$ = new astNode(*$2);
					delete $2;
					$$->append($1);
					$$->append($3);
					delete $3;
					$$->bad = true;
				} */

%%

astNodeMem* parser_main(int argc, char *argv[], std::vector<ObjectCalc::errorClass>* errorListIn)
{
	/*
	stmnts:	stmnt { root->append(*$1); printf("????")}
	  |	stmnts stmnt { $1->append(*$2); printf("?!??!??!?!??!?")}
	*/
	root = new astNodeMem();
	root->type = token::ROOT;

	errorList = errorListIn;

	std::string fileName = argv[argc - 1];
	std::string fileEnding = ".oclc";

	if (fileName.length() > fileEnding.length())
	{
		if (fileName.compare(fileName.length() - fileEnding.length(), fileEnding.length(), fileEnding) == -1)
		{
			fileName += fileEnding;
		}
	}
	else
	{
		fileName += fileEnding;
	}

	//read = new char[line.substr(i).size() + 1];
	//strcpy(read, line.substr(i).c_str());

	yyin = fopen(fileName.c_str(), "r");

	if (!yyin) 
	{
		printf("\nError: Failed to run file. Make sure that the specified file exists\n\n");
		exit(0);
	}

	yyparse();

	return root;
}

int yyerror (char* s)
{
	printf("ERROR: %s\n", s);
	return 0;
}