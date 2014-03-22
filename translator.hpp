#ifndef __TRANSLATOR_HPP__
#define __TRANSLATOR_HPP__

#include <string>
#include "scanner.hpp"
#include "parser.tab.hpp"

namespace Language{

class Translator{
public:
   Translator() : /*chars(0),
                 words(0),
                 lines(0),
                 uppercase(0),
                 lowercase(0), */
                 parser( nullptr ),
                 scanner( nullptr ){};

   virtual ~Translator();

   int parse(const int argc, const char **argv);

   std::ostream& print(std::ostream &stream);

private:

   Language::Parser *parser;
   Language::Scanner *scanner;
};

}
#endif // __TRANSLATOR_HPP__
