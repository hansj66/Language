%skeleton "lalr1.cc"
%require  "3.0"
%debug
%defines
%define api.namespace {Language}
%define parser_class_name {Parser}
%define parse.error verbose

%code requires{
   namespace Language {
      class Translator;
      class Scanner;
      class ASTNode;
      class ParameterListNode;
      class ParameterNode;
      class StatementListNode;
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
  #include "symboltable.h"

extern int lineNumber;

   /* this is silly, but I can't figure out a way around */
   static int yylex(Language::Parser::semantic_type *yylval,
                    Language::Scanner  &scanner,
                    Language::Translator   &translator);

}

/* token types */
%union {
   std::string *sval;
   double dval;
   ASTNode * pNode;
   ParameterNode * parameterNode;
   ParameterListNode * parameterListNode;
   StatementListNode * statementListNode;
}

%left GE LE EQ NE '>' '<'
%left '-' '+'
%left '*' '/'
%nonassoc UMINUS
%nonassoc IFX
%nonassoc ELSE

%token GE LE EQ NE IF While ADD SUB MUL DIV PRINT LT GT NumberType TextType

%token  END    0     "end of file"
%token <dval> Number
%token <sval> Identifier

%type<pNode>  program expression assignment print statement    function_declaration function_declaration_list expression_list function_call while_loop
%type<parameterListNode> parameter_declaration_list
%type <parameterNode> parameter_declaration
%type <statementListNode> statement_list function_body

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
    Identifier Identifier '(' parameter_declaration_list ')' function_body {$$ = new FunctionNode($1, $2, $4, $6); }
    ;

parameter_declaration_list:
    parameter_declaration { $$ = new ParameterListNode($1); }
    |parameter_declaration_list ',' parameter_declaration {dynamic_cast<ParameterListNode *>($1)->Add($3);}
    | {$$ = nullptr;}
;


parameter_declaration:
    NumberType Identifier {$$ = new ParameterNode(token::NumberType, $2);}
    |  TextType Identifier {$$ = new ParameterNode(token::TextType, $2);}
;

function_body:
    '{' statement_list '}' {$$ = $2;}
;


statement_list:
    statement {$$ = new StatementListNode($1);}
    | statement_list statement {dynamic_cast<StatementListNode*>($1)->Add($2);}
    ;

statement:
    parameter_declaration ';' { $$ = $1;}
    | assignment ';' {$$ = $1;}
    | print ';' { $$ = $1;}
    | function_call {$$ = $1;}
    | while_loop { $$ = $1; }
;

while_loop:
    While '(' expression ')' function_body { $$ = new WhileNode($3, $5); }
    ;

function_call:
    Identifier '(' expression_list ')' ';' {$$ = new FunctionCallNode($1, $3);}
;

print:
    PRINT expression { $$ = new PrintNode($2);}
;

assignment:
    Identifier '=' expression { $$ = new AssignmentNode($1, $3);}
    ;


expression_list:
    expression { $$ = new ExpressionListNode($1); }
    | expression_list ',' expression {dynamic_cast<ExpressionListNode *>($1)->Add($3);}
;

expression:
   Identifier { $$ = new IdentifierNode($1); }
 | Number {$$ = new NumberLiteralNode($1); }
 | expression '+' expression { $$ = new OperatorNode(token::ADD, $1, $3); }
 | expression '-' expression { $$ = new OperatorNode(token::SUB, $1, $3); }
 | expression '*' expression { $$ = new OperatorNode(token::MUL, $1, $3); }
 | expression '/' expression { $$ = new OperatorNode(token::DIV, $1, $3); }
 | expression '<' expression { $$ = new OperatorNode(token::LT, $1, $3); }
 | expression '>' expression { $$ = new OperatorNode(token::GT, $1, $3); }
 | expression GE expression { $$ = new OperatorNode(token::GE, $1, $3); }
 | expression LE expression { $$ = new OperatorNode(token::LE, $1, $3); }
 | expression NE expression { $$ = new OperatorNode(token::NE, $1, $3); }
 | expression EQ expression { $$ = new OperatorNode(token::EQ, $1, $3); }
 ;


/*
if / while / assignment etc er statements, ikke expressions
*/

/*

 | identifier { $$ = id($1); }
 | '-' expression %prec UMINUS { $$ = opr(UMINUS, 1, $2); }
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
