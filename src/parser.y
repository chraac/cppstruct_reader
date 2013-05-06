%{
	#include "node.h"
        #include <cstdio>
        #include <cstdlib>
	NBlock *programBlock; /* the top level root node of our final AST */

	extern int yylex();
	void yyerror(const char *s) { std::printf("Error: %s\n", s);std::exit(1); }
%}

/* Represents the many different ways we can access our data */
%union {
	Node *node;
	NBlock *block;
	NExpression *expr;
	NStatement *stmt;
	NIdentifier *ident;
	NVariableDeclaration *var_decl;
	std::vector<NVariableDeclaration*> *varvec;
	std::vector<NExpression*> *exprvec;
	std::string *string;
	int token;
}

/* Define our terminal symbols (tokens). This should
   match our tokens.l lex file. We also define the node type
   they represent.
 */
%token <string> TIDENTIFIER TINTEGER TDOUBLE
%token <token>  TCEQ TCNE TCLT TCLE TCGT TCGE TEQUAL
%token <token>  TLPAREN TRPAREN TLBRACE TRBRACE TCOMMA TDOT TCOLON TSEMICOLON
%token <token>  TPLUS TMINUS TMUL TDIV
%token <token>  TCHAR TINT TFLOAT TDOUBLE TSHORT TLONG TSIGNED TUNSIGNED
%token <token>  TCLASS TSTRUCT TPRIVATE TPROTECTED TPUBLIC TFIELD
%token <token>  TSTATIC TEXTERN TCONST TMUTABLE TVIRTUAL TTYPEDEF

/* Define the type of node our nonterminal symbols represent.
   The types refer to the %union declaration above. Ex: when
   we call an ident (defined by union type ident) we are really
   calling an (NIdentifier*). It makes the compiler happy.
 */
%type <ident>   ident
%type <expr>    numeric expr 
%type <varvec>  func_decl_args
%type <exprvec> call_args
%type <block>   program stmts block
%type <stmt>    stmt var_decl func_impl
%type <token>   comparison

/* Operator precedence for mathematical operators */
%left TPLUS TMINUS
%left TMUL TDIV

%start program

%%

program : global_stmts { programBlock = $1; }
		;

/**  class */
class_decl : TCLASS ident 
           | TSTRUCT ident 
           ;

class_impl : class_decl TLBRACE TRBRACE 
           | class_decl TLBRACE class_memb_list TRBRACE 
           ;

class_memb_list : class_memb_list class_func_decl
                | class_memb_list class_var_decl
                ;
              
class_func_decl : access_right TCOLON class_func_decl
                | class_func_decl func_decl
                | func_decl 
                | /*blank*/  
                ;

class_var_decl : access_right TCOLON class_func_decl
               | class_func_decl var_decl TSEMICOLON
               | var_decl TSEMICOLON
               | /*blank*/  
               ;

access_right : TPRIVATE | TPROTECTED | TPUBLIC;

/**  function */
func_decl : var_type ident TLPAREN func_decl_args TRPAREN  
          ;

func_impl : func_decl block 
			{ $$ = new NFunctionDeclaration(*$1, *$2, *$4, *$6); delete $4; }
		  ;
	
func_decl_args : /*blank*/                      { $$ = new VariableList(); }
		       | var_decl                       { $$ = new VariableList(); $$->push_back($<var_decl>1); }
		       | func_decl_args TCOMMA var_decl { $1->push_back($<var_decl>3); }
		       ;

/**  block */
block : TLBRACE local_stmts TRBRACE { $$ = $2; }
	  | TLBRACE TRBRACE             { $$ = new NBlock(); }
	  ;


/**  statment */
global_stmts : global_stmt              { $$ = new NBlock(); $$->statements.push_back($<stmt>1); }
	         | global_stmts global_stmt { $1->statements.push_back($<stmt>2); }
	         ;

global_stmt : var_decl  TSEMICOLON
            | func_decl TSEMICOLON
	        | func_impl
            | class_decl TSEMICOLON
            | class_impl TSEMICOLON
            ;

local_stmts : local_stmt { $$ = new NExpressionStatement(*$1); }
            | local_stmts local_stmt
            ;

local_stmt : var_decl  TSEMICOLON
           | expr TSEMICOLON
           ;

/**  expression */
expr : ident TEQUAL expr               { $$ = new NAssignment(*$<ident>1, *$3); }
	 | ident TLPAREN call_args TRPAREN { $$ = new NMethodCall(*$1, *$3); delete $3; }
	 | ident                           { $<ident>$ = $1; }
	 | numeric
 	 | expr comparison expr { $$ = new NBinaryOperator(*$1, $2, *$3); }
     | TLPAREN expr TRPAREN { $$ = $2; }
	 ;

call_args : /*blank*/              { $$ = new ExpressionList(); }
		  | expr                   { $$ = new ExpressionList(); $$->push_back($1); }
		  | call_args TCOMMA expr  { $1->push_back($3); }
		  ;

/**  variable */
var_decl : var_type ident             { $$ = new NVariableDeclaration(*$1, *$2); }
		 | var_type ident TEQUAL expr { $$ = new NVariableDeclaration(*$1, *$2, $4); }
		 ;

/**  type */
var_type : type_sign type_len buildin_type
         | ident
         ;

type_decl : TTYPEDEF ident TSEMICOLON
          ; 

buildin_type : TCHAR
             | TINT
             | TFLOAT
             | TDOUBLE
             ;

type_len : TLONG
         | TSHORT
         ;
           
type_sign : TSIGNED
          | TUNSIGNED
          ;

/**  base */
numeric : TINTEGER { $$ = new NInteger(atol($1->c_str())); delete $1; }
		| TDOUBLE  { $$ = new NDouble(atof($1->c_str())); delete $1; }
		;

ident : TIDENTIFIER { $$ = new NIdentifier(*$1); delete $1; }
	  ;

comparison : TCEQ | TCNE | TCLT | TCLE | TCGT | TCGE 
		   | TPLUS | TMINUS | TMUL | TDIV
		   ;

%%
