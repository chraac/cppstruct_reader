%{
#include <string>
#include "node.h"
#include "parser.hpp"
#define SAVE_TOKEN yylval.string = new std::string(yytext, yyleng)
#define TOKEN(t) (yylval.token = t)
extern "C" int yywrap() {}
%}

%%

[ \t\n]					;
[a-zA-Z_][a-zA-Z0-9_]* 	SAVE_TOKEN; return TIDENTIFIER;
[0-9]+\.[0-9]* 			SAVE_TOKEN; return TDOUBLE;
[0-9]+					SAVE_TOKEN; return TINTEGER;
"="						return TOKEN(TEQUAL);
"=="					return TOKEN(TCEQ);
"!="					return TOKEN(TCNE);
"<"						return TOKEN(TCLT);
"<="					return TOKEN(TCLE);
">"						return TOKEN(TCGT);
">="					return TOKEN(TCGE);
"("						return TOKEN(TLPAREN);
")"						return TOKEN(TRPAREN);
"{"						return TOKEN(TLBRACE);
"}"						return TOKEN(TRBRACE);
"."						return TOKEN(TDOT);
":"                     return TOKEN(TCOLON);
";"                     return TOKEN(TSEMICOLON);
","						return TOKEN(TCOMMA);
"+"						return TOKEN(TPLUS);
"-"						return TOKEN(TMINUS);
"*"						return TOKEN(TMUL);
"/"						return TOKEN(TDIV);

"char"                  return TOKEN(TCHAR);
"int"                   return TOKEN(TINT);
"float"                 return TOKEN(TFLOAT);
"double"                return TOKEN(TDOUBLE);
"short"                 return TOKEN(TSHORT);
"long"                  return TOKEN(TLONG);
"signed"                return TOKEN(TSIGNED);
"unsigned"              return TOKEN(TUNSIGNED);

"class"                 return TOKEN(TCLASS);
"struct"                return TOKEN(TSTRUCT);
"private"               return TOKEN(TPRIVATE);
"protected"             return TOKEN(TPROTECTED);
"public"                return TOKEN(TPUBLIC);
"::"                    return TOKEN(TFIELD);
"static"                return TOKEN(TSTATIC);
"extern"                return TOKEN(TEXTERN);
"const"                 return TOKEN(TCONST);
"mutable"               return TOKEN(TMUTABLE);
"virtual"               return TOKEN(TVIRTUAL);
"typedef"               return TOKEN(TTYPEDEF);

.						printf("Unknown token!\n"); yyterminate();

%%
