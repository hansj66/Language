#include <iostream>
#include <cstdlib>

#include "translator.hpp"

using namespace std;

int main(const int argc, const char **argv)
{
   if(argc < 2)
   {
       cerr << "Usage: " << "scripture " << "<script>" << " [script arguments]" << endl;
       exit(EXIT_FAILURE);
   }

   Language::Translator translator;

   return(translator.parse( argc, argv ));
}



