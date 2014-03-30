#include <iostream>
#include <cstdlib>

#include "translator.hpp"


int main(const int argc, const char **argv)
{
   if(argc < 2)
      return ( EXIT_FAILURE );

   Language::Translator translator;

   return(translator.parse( argc, argv ));
}
