#include <iostream>
#include <cstdlib>

#include "translator.hpp"

int
main(const int argc, const char **argv)
{
   if(argc != 2 )
      return ( EXIT_FAILURE );

   Language::Translator translator;
   translator.parse( argv[1] );
   std::cout << "Results\n";
   translator.print(std::cout) << "\n";

   return( EXIT_SUCCESS );
}
