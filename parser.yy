%skeleton "lalr1.cc"
%require  "3.0"
%debug
%defines
%define api.namespace {Language}
%define parser_class_name {Parser}
%define parse.error verbose
// define YYERROR_VERBOSE

%code requires{
   namespace Language {
      class Translator;
      class Scanner;
      class ASTNode;
   }
}

%lex-param   { Scanner  &scanner  }
%parse-param { Scanner  &scanner  }

%lex-param   { Translator  &translator  }
%parse-param { Translator  &translator  }
%code{

   #include <iostream>
   #include <cstdlib>
   #include <fstream>

  #include "ast.h"
  #include "translator.hpp"
  #include "interpreter.h"

extern int lineNumber;

   /* this is silly, but I can't figure out a way around */
   static int yylex(Language::Parser::semantic_type *yylval,
                    Language::Scanner  &scanner,
                    Language::Translator   &translator);

}

/* token types */
%union {
   std::string *sval;
   int ival;
   ASTNode * pNode;
}

%left GE LE EQ NE '>' '<'
%left '-' '+'
%left '*' '/'
%nonassoc UMINUS
%nonassoc IFX
%nonassoc ELSE

%token GE LE EQ NE IF WHILE ADD PRINT

%token  END    0     "end of file"
%token <ival> Integer
%token <sval> Identifier

%type<pNode> parameter_declaration_list program expression assignment print statement statement_list function_body parameter_declaration function_declaration function_declaration_list

/* destructor rule for <sval> objects */
%destructor { if ($$)  { delete ($$); ($$) = nullptr; } } <sval>

%%

program:
    function_declaration_list { $1->Execute(); }
    ;

function_declaration_list:
    function_declaration { $$ = new FunctionDeclarationListNode($1);}
    | function_declaration_list function_declaration {dynamic_cast<FunctionDeclarationListNode *>($1)->Add($2);}
    ;

function_declaration:
    Identifier Identifier '(' parameter_declaration_list ')' function_body { $$ = new FunctionDeclarationNode($1, $2, $4, $6);}
    ;

parameter_declaration_list:
    parameter_declaration { $$ = new ParameterListNode($1); }
    |parameter_declaration_list ',' parameter_declaration {dynamic_cast<ParameterListNode *>($1)->Add($3);}
;


parameter_declaration:
    Identifier Identifier '=' Integer {$$ = new ParameterNode($1, $2, $4);}
    | Identifier Identifier {$$ = new ParameterNode($1, $2);}
;


function_body:
    '{' statement_list '}' {$$ = $2;}
;


statement_list:
    statement {$$ = new StatementListNode($1);}
    | statement_list statement {dynamic_cast<StatementListNode*>($1)->Add($2);}
    ;

statement:
    assignment {$$ = $1;}
    | expression { $$ = $1;}
    | print { $$ = $1;}
;

print:
    PRINT expression { $$ = new PrintNode($2);}
;

assignment:
    Identifier '=' expression { $$ = new AssignmentNode($1, $3);}
    ;

expression:
   Identifier { $$ = new IdentifierNode($1); }
 | Integer {$$ = new IntegerLiteralNode($1); }
 | expression '+' expression { $$ = new OperatorNode(token::ADD, $1, $3); }
 ;


/*
if / while / assignment etc er statements, ikke expressions
*/

/*

 | identifier { $$ = id($1); }
 | '-' expression %prec UMINUS { $$ = opr(UMINUS, 1, $2); }
 | expression '+' expression { $$ = opr('+', 2, $1, $3); }
 | expression '-' expression { $$ = opr('-', 2, $1, $3); }
 | expression '*' expression { $$ = opr('*', 2, $1, $3); }
 | expression '/' expression { $$ = opr('/', 2, $1, $3); }
 | expression '<' expression { $$ = opr('<', 2, $1, $3); }
 | expression '>' expression { $$ = opr('>', 2, $1, $3); }
 | expression GE expression { $$ = opr(GE, 2, $1, $3); }
 | expression LE expression { $$ = opr(LE, 2, $1, $3); }
 | expression NE expression { $$ = opr(NE, 2, $1, $3); }
 | expression EQ expression { $$ = opr(EQ, 2, $1, $3); }
 | '(' expression ')' { $$ = $2; }
 ;

*/

%%



void
Language::Parser::error( const std::string &err_message )
{
   std::cerr << "Error: Line:" << lineNumber << "' - " << err_message << "\n";
}


/* include for access to scanner.yylex */
#include "scanner.hpp"
static int
yylex( Language::Parser::semantic_type *yylval,
       Language::Scanner  &scanner,
       Language::Translator   &translator )
{
   return( scanner.yylex(yylval) );
}
