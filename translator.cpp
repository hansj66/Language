#include <cctype>
#include <fstream>
#include <cassert>

#include "translator.hpp"
#include "ast.h"
#include "symboltable.h"

int lineNumber = 1;

Language::Translator::~Translator()
{
   delete(scanner);
   scanner = nullptr;
   delete(parser);
   parser = nullptr;
}


// Create ParameterList from the rest of the Arguments
// Push argumentene på argstacken
// Gjør sjekk inni metoden / evt kanskje før kallet. Sjekk antall, samt type
// Unngå dynamic casts i .yy


int Language::Translator::parse(const int argc, const char **argv)
{
    if (argc > 2)
        SymbolTable::Instance()->PushCommandLineArguments(argc-2, &argv[2]);

    const char * filename = argv[1];

   assert( filename != nullptr );
   std::ifstream in_file( filename );
   if( ! in_file.good() )
       exit( EXIT_FAILURE );

   delete(scanner);
   try
   {
      scanner = new Language::Scanner( &in_file );
   }
   catch( std::bad_alloc &ba )
   {
      std::cerr << "Failed to allocate scanner: (" <<
         ba.what() << "), exiting!!\n";
      exit( EXIT_FAILURE );
   }

   delete(parser);
   try
   {
      parser = new Language::Parser( (*scanner) /* scanner */,
                                  (*this) /* translator */ );
   }
   catch( std::bad_alloc &ba )
   {
      std::cerr << "Failed to allocate parser: (" <<
         ba.what() << "), exiting!!\n";
      exit( EXIT_FAILURE );
   }
   const int accept( 0 );
   if( parser->parse() != accept )
   {
      std::cerr << "Parse failed!!\n";
   }

   SymbolTable::Instance()->EntryPoint()->Execute();

   return accept;
}


std::ostream& Language::Translator::print( std::ostream &stream )
{
    /*
   stream << "Uppercase: " << uppercase << "\n";
   stream << "Lowercase: " << lowercase << "\n";
   stream << "Lines: " << lines << "\n";
   stream << "Words: " << words << "\n";
   stream << "Characters: " << chars << "\n";
   */
   return(stream);
}
