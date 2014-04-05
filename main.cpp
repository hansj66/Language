#include <iostream>
#include <cstdlib>

#include "translator.hpp"


int main(const int argc, const char **argv)
{
   if(argc < 2)
   {
       std::cerr << "Usage: " << "scripture " << "<script>" << " [script arguments]" << std::endl;
       exit(EXIT_FAILURE);
   }

   Language::Translator translator;

   return(translator.parse( argc, argv ));
}


