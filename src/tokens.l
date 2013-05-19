%{
#include <string>
#include "node.h"
#include "parser.hpp"
#define SAVE_TOKEN yylval.string = new std::string(yytext, yyleng)
#define TOKEN(t) (yylval.token = t)
extern "C" int yywrap() {}
%}

%%

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

"char"                  return TOKEN(TRCHAR);
"int"                   return TOKEN(TRINT);
"float"                 return TOKEN(TRFLOAT);
"double"                return TOKEN(TRDOUBLE);
"short"                 return TOKEN(TRSHORT);
"long"                  return TOKEN(TRLONG);
"signed"                return TOKEN(TRSIGNED);
"unsigned"              return TOKEN(TRUNSIGNED);

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

[ \t\n]					;
[a-zA-Z_][a-zA-Z0-9_]* 	SAVE_TOKEN; return TIDENTIFIER;
[0-9]+\.[0-9]* 			SAVE_TOKEN; return TDOUBLE;
[0-9]+					SAVE_TOKEN; return TINTEGER;

.						printf("Unknown token!\n"); yyterminate();

%%
