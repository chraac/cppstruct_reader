%option debug 
%option nodefault 
%option yylineno
%option yyclass="cpp_scanner" 
%option noyywrap 
%option c++

%{
    #include "basedefine.h"
    #include "node.h"
    using namespace cpp_complier;
    #include "cpp_parser.hpp"

    
    inline void step_pos(cpp_parser::location_type *yylloc, 
        const int line, const int len_tok)
    {
        if (!yylloc)
        {
            return;
        }

        yylloc->step();
        if (line != yylloc->begin.line)
        {
            yylloc->lines();
        }
        yylloc->columns(len_tok);
    }
    
    #define TOKEN(t)    (yylval->token = t)
    #define SAVE_LINENO step_pos(yylloc, lineno(), yyleng)
    #define SAVE_TOKEN  SAVE_LINENO; yylval->string = new stlstring(yytext, yyleng)
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

"char"               	SAVE_TOKEN; return TRCHAR;
"int"               	SAVE_TOKEN; return TRINT;
"float"               	SAVE_TOKEN; return TRFLOAT;
"double"               	SAVE_TOKEN; return TRDOUBLE;

[ \t\n]					;
[a-zA-Z_][a-zA-Z0-9_]* 	SAVE_TOKEN; return TIDENTIFIER;
[0-9]+\.[0-9]* 			SAVE_TOKEN; return TDOUBLE;
[0-9]+					SAVE_TOKEN; return TINTEGER;

.						printf("Unknown token!\n"); yyterminate();

%%
