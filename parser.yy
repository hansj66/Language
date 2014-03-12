%skeleton "lalr1.cc"
%require  "3.0"
%debug
%defines
%define api.namespace {Language}
%define parser_class_name {Parser}

%code requires{
   namespace Language {
      class Translator;
      class Scanner;
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

   /* include for all translator functions */
   #include "translator.hpp"

   /* this is silly, but I can't figure out a way around */
   static int yylex(Language::Parser::semantic_type *yylval,
                    Language::Scanner  &scanner,
                    Language::Translator   &translator);

}

/* token types */
%union {
   std::string *sval;
}

%token            END    0     "end of file"
%token            UPPER
%token            LOWER
%token   <sval>   WORD
%token            NEWLINE
%token            CHAR


/* destructor rule for <sval> objects */
%destructor { if ($$)  { delete ($$); ($$) = nullptr; } } <sval>


%%

list_option : END | list END;

list
  : item
  | list item
  ;

item
  : UPPER   { translator.add_upper(); }
  | LOWER   { translator.add_lower(); }
  | WORD    { translator.add_word( *$1 ); }
  | NEWLINE { translator.add_newline(); }
  | CHAR    { translator.add_char(); }
  ;

%%


void
Language::Parser::error( const std::string &err_message )
{
   std::cerr << "Error: " << err_message << "\n";
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
