%{

#include <QString>
#include "lexer.hpp"

extern int lineNumber;

typedef Language::Parser::token token;

#define yyterminate() return( token::END )
#define YY_NO_UNISTD_H // For msvc

%}

%option debug
%option yyclass="Lexer"
%option noyywrap
%option c++

%%

[ \t]+          				; /* Ignore white space */
[\n]            				{ lineNumber++; }

\/\/(.)* ;

\"(\\.|[^"])*\" 				{
                                                        yylval->sval = new QString( yytext );
                                                        return token::String;
                                                }

([0-9]+|([0-9]*\.[0-9]+)([eE][-+]?[0-9]+)?)	{
                                                        yylval->dval = atoi(yytext);
                                                        return token::Number;
                                                }

"number"					{ return token::NumberType; }
"text"	 					{ return token::TextType; }
"void" 						{ return token::VoidType; }
"if"						{ return token::IF; }
"else" 						{ return token::ELSE; }
"while" 					{ return token::While; }
"print" 					{ return token::PRINT; }
"return"  					{ return token::RETURN; }
"==" 						{ return token::EQ; }
"!=" 						{ return token::NE; }
">=" 						{ return token::GE; }
"<=" 						{ return token::LE; }

[a-z|A-Z]([a-z|A-Z|0-9]+)?   			{
                                                        yylval->sval = new QString( yytext );
                                                        return( token::Identifier );
                                                }

. { return yytext[0];}

%%
