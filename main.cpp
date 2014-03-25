#include <iostream>
#include <cstdlib>

#include "translator.hpp"


int main(const int argc, const char **argv)
{
   if(argc < 2)
      return ( EXIT_FAILURE );

   Language::Translator translator;
   translator.parse( argc, argv );

   return( EXIT_SUCCESS );
}
