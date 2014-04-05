#include <cctype>
#include <fstream>
#include <cassert>

#include "translator.hpp"
#include "ast.h"
#include "symboltable.h"
#include "errors.h"

int lineNumber = 1;

namespace Language
{

Translator::Translator()
{
}

void Translator::PrepareCommandLineArguments(const int argc, const char **argv)
{
    int expectedArgumentCount = SymbolTable::Instance()->EntryPoint()->Arguments()->size();

    if (expectedArgumentCount != argc-2)
    {
        std::cerr << WRONG_NUMBER_OF_ARGUMENTS << "script entry point\n";
        exit(EXIT_FAILURE);
    }

    SymbolTable::Instance()->PushCommandLineArguments(argc-2, &argv[2]);
}


int Translator::parse(const int argc, const char **argv)
{
    const char * filename = argv[1];

   assert( filename != nullptr );
   std::ifstream in_file( filename );
   if( ! in_file.good() )
       exit( EXIT_FAILURE );

   Lexer lexer(&in_file);
   Parser parser(lexer);

   if( parser.parse() != 0 )
   {
      std::cerr << "Parse failed!!\n";
   }

   PrepareCommandLineArguments(argc, argv);

   return SymbolTable::Instance()->EntryPoint()->Execute().toInt();
}
}
