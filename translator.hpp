#ifndef __TRANSLATOR_HPP__
#define __TRANSLATOR_HPP__

#include <string>
#include "scanner.hpp"
#include "parser.tab.hpp"

namespace Language{

class Translator{
public:
   Translator() : chars(0),
                 words(0),
                 lines(0),
                 uppercase(0),
                 lowercase(0),
                 parser( nullptr ),
                 scanner( nullptr ){};

   virtual ~Translator();

   void parse( const char *filename );


   void add_upper();
   void add_lower();
   void add_word( const std::string &word );
   void add_newline();
   void add_char();

   std::ostream& print(std::ostream &stream);
private:
   int chars;
   int words;
   int lines;
   int uppercase;
   int lowercase;
   Language::Parser *parser;
   Language::Scanner *scanner;
};

}
#endif // __TRANSLATOR_HPP__
