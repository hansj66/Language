#ifndef __TRANSLATOR_HPP__
#define __TRANSLATOR_HPP__

#include <string>
#include "lexer.hpp"
#include "parser.tab.hpp"

namespace Language
{

class Translator
{
public:
   Translator();
   int parse(const int argc, const char **argv);
};

}
#endif // __TRANSLATOR_HPP__
