#ifndef __LEXER_HPP__
#define __LEXER_HPP__

#if ! defined(yyFlexLexerOnce)
#include <FlexLexer.h>
#endif

#undef  YY_DECL
#define YY_DECL int  Language::Lexer::yylex()

#include "parser.tab.hpp"

namespace Language
{

class Lexer : public yyFlexLexer{
public:

   Lexer(std::istream *in) : yyFlexLexer(in),
                                  yylval( nullptr ){};

   int yylex(Parser::semantic_type *lval)
   {
      yylval = lval;
      return( yylex() );
   }

private:
   int yylex();
   Parser::semantic_type *yylval;
};

}

#endif // __LEXER_HPP__
