%{
	#include "parser.tab.h"
	#include "parser.tab.c"
	#include <iostream>
	#include "HeaderFiles/node.hpp"

	#define YY_USER_ACTION { if (yylloc.last_line == yylineno) { yylloc.last_column += yyleng; } else { yylloc.last_column = 1; yylloc.last_line = yylineno; } }
	//printf("YY_USER_ACTION");
	//yyleng

	std::string strings;
%}

%option noyywrap
%option yylineno

%s IN_COMMENT
%s IN_STRING

%%

"//"[^\n]*?		;

<INITIAL>{
"/*"			BEGIN(IN_COMMENT); 
\"				BEGIN(IN_STRING); strings = "";
}
	/* the * in [^*\n]+ is necessary for some fucking reason */
<IN_COMMENT>{
<<EOF>>			BEGIN(INITIAL); 
"*/"      		BEGIN(INITIAL); 
[^*\n]+   		// eat comment in chunks
"*"       		// eat the lone star
\n        		yylineno++;
}		

<IN_STRING>{
\\\"       		strings += yytext; 
\"      		{ 
					BEGIN(INITIAL);
					astNodeStr* temp = new astNodeStr();
					temp->chars = "String";
					temp->value = strings;
					temp->type = token::STRING;
					temp->location[0] = yylineno; temp->location[1] = yylloc.last_column; 
					yylval.node = temp;
					return CONSTANT;
				}
<<EOF>>     	{ 
					BEGIN(INITIAL);
					astNodeStr* temp = new astNodeStr();
					temp->chars = "String";
					temp->value = strings;
					temp->type = token::STRING;
					temp->location[0] = yylineno; temp->location[1] = yylloc.last_column; 
					yylval.node = temp;
					return CONSTANT;
				}
[^\"\n]+		strings += yytext;
\n        		strings += yytext; yylineno++;
}



[ \n\t\r\b\s ]+	;

"Num"|"Str"|"Dec"|"Bool"|"Object"|"List" {
											yylval.t = new token();
											yylval.t->type = token::TYPE;
											yylval.t->chars = yytext;
											yylval.t->location[0] = yylineno; yylval.t->location[1] = yylloc.last_column; 
											return TYPE;
										}


"if" 	{
			yylval.t = new token();
			yylval.t->type = token::IF;
			yylval.t->chars = yytext;
			yylval.t->location[0] = yylineno; yylval.t->location[1] = yylloc.last_column; 
			return IF;
		}
"else" 	{
			yylval.t = new token();
			yylval.t->type = token::ELSE;
			yylval.t->chars = yytext;
			yylval.t->location[0] = yylineno; yylval.t->location[1] = yylloc.last_column; 
			return ELSE;
		}

	
[0-9]+			{ 
					astNodeInt* temp = new astNodeInt();
					temp->chars = yytext;
					temp->value = std::stoll(yytext);
					temp->type = token::NUMBER; 
					temp->location[0] = yylineno; temp->location[1] = yylloc.last_column; 
					yylval.node = temp;
					return CONSTANT;
				}
[0-9]+"."[0-9]+ { 
					astNodeDec* temp = new astNodeDec();
					temp->chars = yytext;
					temp->value = std::stold(yytext);
					temp->type = token::DECIMAL; 
					temp->location[0] = yylineno; temp->location[1] = yylloc.last_column; 
					yylval.node = temp;
					return CONSTANT;
				}
"true"			{ 
					astNodeBool* temp = new astNodeBool();
					temp->chars = yytext;
					temp->value = true;
					temp->type = token::BOOL;
					yylval.t->location[0] = yylineno; temp->location[1] = yylloc.last_column; 
					yylval.node = temp;
					return CONSTANT;
				}
"false"			{ 
					astNodeBool* temp = new astNodeBool();
					temp->chars = yytext;
					temp->value = false;
					temp->type = token::BOOL;
					yylval.t->location[0] = yylineno; temp->location[1] = yylloc.last_column; 
					yylval.node = temp;
					return CONSTANT;
				}

[a-zA-Z_][a-zA-Z0-9_]* 	{
							yylval.t = new token();
							yylval.t->chars = yytext;
							yylval.t->type = token::VARIABLE;
							yylval.t->location[0] = yylineno; yylval.t->location[1] = yylloc.last_column; 
							return NAME;
						}

"."				{
					yylval.t = new token(); 
					yylval.t->type = token::BINARY_OPERATOR; 
					yylval.t->chars = yytext; 
					yylval.t->location[0] = yylineno; yylval.t->location[1] = yylloc.last_column; 
					return DOT;
				}

" + "|" - "			{
					yylval.t = new token();
					yylval.t->type = token::BINARY_OPERATOR;
					yylval.t->chars = yytext;
					yylval.t->location[0] = yylineno; yylval.t->location[1] = yylloc.last_column; 
					return OPERATOR0;
				}
" * "|" / "			{
					yylval.t = new token();
					yylval.t->type = token::BINARY_OPERATOR;
					yylval.t->chars = yytext;
					yylval.t->location[0] = yylineno; yylval.t->location[1] = yylloc.last_column; 
					return OPERATOR1;
				}
"**"		{
					yylval.t = new token();
					yylval.t->type = token::BINARY_OPERATOR;
					yylval.t->chars = yytext;
					yylval.t->location[0] = yylineno; yylval.t->location[1] = yylloc.last_column; 
					return OPERATOR2;
				}
"="|"=="		{
					yylval.t = new token();
					yylval.t->type = token::BINARY_OPERATOR;
					yylval.t->chars = yytext;
					yylval.t->location[0] = yylineno; yylval.t->location[1] = yylloc.last_column; 
					return OPERATOR3;
				}

"++"|"--"		{
					yylval.t = new token();
					yylval.t->type = token::UNARY_OPERATOR;
					yylval.t->chars = yytext;
					yylval.t->location[0] = yylineno; yylval.t->location[1] = yylloc.last_column; 
					return UNIOPERATOR0;
				}
"-"|"!"	{
					yylval.t = new token();
					yylval.t->type = token::UNARY_OPERATOR;
					yylval.t->chars = yytext;
					yylval.t->location[0] = yylineno; yylval.t->location[1] = yylloc.last_column; 
					return UNIOPERATOR1;
				}

"("				{
					yylval.t = new token();
					yylval.t->type = token::LPAREN;
					yylval.t->chars = yytext;
					yylval.t->location[0] = yylineno; yylval.t->location[1] = yylloc.last_column; 
					return LPAREN;
				}
"["				{
					yylval.t = new token();
					yylval.t->type = token::LBRACK;
					yylval.t->chars = yytext;
					yylval.t->location[0] = yylineno; yylval.t->location[1] = yylloc.last_column; 
					return LBRACK;
				}
"{"				{
					yylval.t = new token();
					yylval.t->type = token::LBRACE;
					yylval.t->chars = yytext;
					yylval.t->location[0] = yylineno; yylval.t->location[1] = yylloc.last_column; 
					return LBRACE;
				}
")"				{
					yylval.t = new token();
					yylval.t->type = token::RPAREN;
					yylval.t->chars = yytext;
					yylval.t->location[0] = yylineno; yylval.t->location[1] = yylloc.last_column; 
					return RPAREN;
				}
"]"				{
					yylval.t = new token();
					yylval.t->type = token::RBRACK;
					yylval.t->chars = yytext;
					yylval.t->location[0] = yylineno; yylval.t->location[1] = yylloc.last_column; 
					return RBRACK;
				}
"}"				{
					yylval.t = new token();
					yylval.t->type = token::RBRACE;
					yylval.t->chars = yytext;
					yylval.t->location[0] = yylineno; yylval.t->location[1] = yylloc.last_column; 
					return RBRACE;
				}

";"				{
					yylval.t = new token();
					yylval.t->type = token::SEMICOLON;
					yylval.t->chars = yytext;
					yylval.t->location[0] = yylineno; yylval.t->location[1] = yylloc.last_column; 
					return SEMICOLON;
				}

#[^\n\t\r\s]*	{
					yylval.t = new token();
					yylval.t->type = token::TAG;
					yylval.t->chars = yytext;
					yylval.t->location[0] = yylineno; yylval.t->location[1] = yylloc.last_column; 
					return TAG;
				}

<<EOF>>		 	{
					yylval.t = new token();
					yylval.t->type = token::LAST;
					yylval.t->location[0] = yylineno; yylval.t->location[1] = yylloc.last_column; 
					return END;
				}

.	 			{
					yylval.t = new token(); 
					yylval.t->chars = yytext;
					yylval.t->location[0] = yylineno; yylval.t->location[1] = yylloc.last_column;
					return UNKNOWN;
				}

%%