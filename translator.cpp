#include <cctype>
#include <fstream>
#include <cassert>

#include "translator.hpp"
#include "ast.h"
#include "symboltable.h"

int lineNumber = 1;

namespace Language
{

Translator::Translator()
{
}

int Translator::parse(const int argc, const char **argv)
{
//    if (argc > 2)
        SymbolTable::Instance()->PushCommandLineArguments(argc-2, &argv[2]);

    const char * filename = argv[1];

   assert( filename != nullptr );
   std::ifstream in_file( filename );
   if( ! in_file.good() )
       exit( EXIT_FAILURE );

   Scanner scanner(&in_file);
   Parser parser(scanner);

   if( parser.parse() != 0 )
   {
      std::cerr << "Parse failed!!\n";
   }

   return SymbolTable::Instance()->EntryPoint()->Execute().toInt();
}
}
