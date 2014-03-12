#ifndef __SCANNER_HPP__
#define __SCANNER_HPP__

#if ! defined(yyFlexLexerOnce)
#include <FlexLexer.h>
#endif

#undef  YY_DECL
#define YY_DECL int  Language::Scanner::yylex()

#include "parser.tab.hpp"

namespace Language{

class Scanner : public yyFlexLexer{
public:

   Scanner(std::istream *in) : yyFlexLexer(in),
                                  yylval( nullptr ){};

   int yylex(Language::Parser::semantic_type *lval)
   {
      yylval = lval;
      return( yylex() );
   }


private:
   /* hide this one from public view */
   int yylex();
   /* yyval ptr */
   Language::Parser::semantic_type *yylval;
};

}

#endif // __SCANNER_HPP__
