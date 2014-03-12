#include <cctype>
#include <fstream>
#include <cassert>

#include "translator.hpp"

Language::Translator::~Translator(){
   delete(scanner);
   scanner = nullptr;
   delete(parser);
   parser = nullptr;
}

void
Language::Translator::parse( const char *filename )
{
   assert( filename != nullptr );
   std::ifstream in_file( filename );
   if( ! in_file.good() ) exit( EXIT_FAILURE );

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
}

void
Language::Translator::add_upper()
{
   uppercase++;
   chars++;
   words++;
}

void
Language::Translator::add_lower()
{
   lowercase++;
   chars++;
   words++;
}

void
Language::Translator::add_word( const std::string &word )
{
   words++;
   chars += word.length();
   for(const char &c : word ){
      if( islower( c ) )
      {
         lowercase++;
      }
      else if ( isupper( c ) )
      {
         uppercase++;
      }
   }
}

void
Language::Translator::add_newline()
{
   lines++;
   chars++;
}

void
Language::Translator::add_char()
{
   chars++;
}


std::ostream&
Language::Translator::print( std::ostream &stream )
{
   stream << "Uppercase: " << uppercase << "\n";
   stream << "Lowercase: " << lowercase << "\n";
   stream << "Lines: " << lines << "\n";
   stream << "Words: " << words << "\n";
   stream << "Characters: " << chars << "\n";
   return(stream);
}
