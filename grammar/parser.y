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
      class Lexer;
      class ASTNode;
      class ParameterNode;
      class FunctionNode;
      class OperatorNode;
      class StatementListNode;
      template <class T> class ListNode;
   }
   class QString;
}

%lex-param   { Lexer  &lexer  }
%parse-param { Lexer  &lexer  }

%code{
    #include "translator.hpp"
    #include "ast.h"
    extern int lineNumber;
    static int yylex(Language::Parser::semantic_type *yylval, Language::Lexer  &lexer);
}

/* token types */
%union {
   QString *sval;
   double dval;
   int ival;
   ASTNode * pNode;
   ParameterNode * parameterNode;
   FunctionNode * functionNode;
   ListNode<ASTNode> * listNode;
   ListNode<ParameterNode> * parameterListNode;
   StatementListNode * statementListNode;
}

%left GE LE EQ NE '>' '<'
%left '-' '+'
%left '*' '/'
%nonassoc UMINUS
%nonassoc IFX
%nonassoc ELSE

%token GE LE EQ NE IF While ADD SUB MUL DIV PRINT LT GT RETURN NumberType TextType VoidType

%token  END    0     "end of file"
%token <dval> Number
%token <sval> Identifier
%token <sval> String

%type<pNode>  program expression assignment print statement function_call while_loop if return
%type <parameterNode> parameter_declaration
%type <ival> type NumberType TextType VoidType
%type <functionNode> function_declaration
%type <listNode> expression_list function_declaration_list
%type <parameterListNode> parameter_declaration_list
%type <statementListNode>statement_list function_body


%%

program:
    function_declaration_list { $1->Execute(); }
    ;

function_declaration_list:
    function_declaration { $$ = new ListNode<ASTNode>($1);}
    | function_declaration_list function_declaration {$1->push_back($2);}
    ;

function_declaration:
    type Identifier '(' parameter_declaration_list ')' function_body {$$ = new FunctionNode($1, $2, $4, $6); }
    ;

type:
    NumberType {$$ = token::NumberType;}
    | TextType {$$ = token::TextType;}
    | VoidType {$$ = token::VoidType;}
    ;

parameter_declaration_list:
    parameter_declaration { $$ = new ListNode<ParameterNode>($1); }
    |parameter_declaration_list ',' parameter_declaration {$1->push_back($3);}
    | {$$ = new ListNode<ParameterNode>();}
;

parameter_declaration:
    type Identifier {$$ = new ParameterNode($1, $2);}
    | type Identifier '=' expression {$$ = new ParameterNode($1, $2, $4);}
;

function_body:
    '{' statement_list '}' {$$ = $2;}
;

statement_list:
    statement {$$ = new StatementListNode($1);}
    | statement_list statement {$1->push_back($2);}
    ;

statement:
    parameter_declaration ';' { $$ = $1;}
    | assignment ';' {$$ = $1;}
    | print ';' { $$ = $1;}
    | function_call ';' {$$ = $1;}
    | while_loop { $$ = $1; }
    | if { $$ = $1; }
    | return ';' { $$ = $1;}
;


return:
    RETURN expression {$$ = new ReturnNode($2); }
;

while_loop:
    While '(' expression ')' function_body { $$ = new WhileNode($3, $5); }
    ;

function_call:
    Identifier '(' expression_list ')' {$$ = new FunctionCallNode($1, $3);}
;

if:
    IF '(' expression ')' function_body %prec IFX  { $$ = new IfNode($3, $5); }
    | IF '(' expression ')' function_body ELSE function_body   { $$ = new IfNode($3, $5, $7); }
;

print:
    PRINT expression { $$ = new PrintNode($2);}
    ;

assignment:
    Identifier '=' expression { $$ = new AssignmentNode($1, $3);}
    ;

expression_list:
    expression { $$ = new ListNode<ASTNode>($1); }
    | expression_list ',' expression {$1->push_back($3);}
    | {$$ = new ListNode<ASTNode>(); }
;

expression:
 Identifier { $$ = new IdentifierNode($1); }
 | String { $$ = new StringLiteralNode($1);}
 | Number {$$ = new NumberLiteralNode($1); }
 | function_call { $$ = $1;}
 | '-' expression %prec UMINUS { $$ = new OperatorNode(token::UMINUS, $2); }
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
 | '(' expression ')' { $$ = $2; }
 ;



%%

#include "lexer.hpp"

void Language::Parser::error( const std::string &err_message )
{
   std::cerr << "Error: Line:" << lineNumber << "' - " << err_message << "\n";
}

static int yylex( Language::Parser::semantic_type *yylval, Language::Lexer  &lexer)
{
   return( lexer.yylex(yylval) );
}

