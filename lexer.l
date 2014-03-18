%{
/* C++ string header, for string ops below */
#include <string>
/* Implementation of yyFlexScanner */
#include "scanner.hpp"

extern int lineNumber;

/* typedef to make the returns for the tokens shorter */
typedef Language::Parser::token token;

/* define to keep from re-typing the same code over and over */
#define STOKEN( x ) ( new std::string( x ) )

/* define yyterminate as this instead of NULL */
#define yyterminate() return( token::END )

/* msvc2010 requires that we exclude this header file. */
#define YY_NO_UNISTD_H

%}

%option debug
%option yyclass="Scanner"
%option noyywrap
%option c++

%%

[ \t]+ ; /* Ignore white space */
[\n] {lineNumber++;}

([0-9]+|([0-9]*\.[0-9]+)([eE][-+]?[0-9]+)?) {
            yylval->dval = atoi(yytext);
            return token::Number;
            }

"number" { return token::NumberType; }
"text" { return token::TextType; }

"if"    { return token::IF;}
"while" { return token::While;}
"print" {return token::PRINT;}
"==" {return token::EQ;}
"!=" {return token::NE;}
">=" {return token::GE;}
"<=" {return token::LE;}


[a-z|A-Z]([a-z|A-Z|0-9]+)?   {
               yylval->sval = STOKEN( yytext );
               return( token::Identifier );
            }

. { return yytext[0];}

%%
