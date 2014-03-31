// A Bison parser, made by GNU Bison 3.0.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2013 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.


// First part of user declarations.

#line 37 "parser.tab.cpp" // lalr1.cc:398

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

#include "parser.tab.hpp"

// User implementation prologue.

#line 51 "parser.tab.cpp" // lalr1.cc:406
// Unqualified %code blocks.
#line 29 "parser.yy" // lalr1.cc:407


    #include <iostream>
    #include <cstdlib>
    #include <fstream>

    #include "ast.h"
    #include "translator.hpp"
    #include "symboltable.h"

    extern int lineNumber;

   /* this is silly, but I can't figure out a way around */
   static int yylex(Language::Parser::semantic_type *yylval,
                    Language::Scanner  &scanner,
                    Language::Translator   &translator);


#line 72 "parser.tab.cpp" // lalr1.cc:407


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif



// Suppress unused-variable warnings by "using" E.
#define YYUSE(E) ((void) (E))

// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << std::endl;                  \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE(Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void>(0)
# define YY_STACK_PRINT()                static_cast<void>(0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyempty = true)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

#line 5 "parser.yy" // lalr1.cc:473
namespace Language {
#line 139 "parser.tab.cpp" // lalr1.cc:473

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  Parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr = "";
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              // Fall through.
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }


  /// Build a parser object.
  Parser::Parser (Scanner  &scanner_yyarg, Translator  &translator_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      scanner (scanner_yyarg),
      translator (translator_yyarg)
  {}

  Parser::~Parser ()
  {}


  /*---------------.
  | Symbol types.  |
  `---------------*/

  inline
  Parser::syntax_error::syntax_error (const std::string& m)
    : std::runtime_error (m)
  {}

  // basic_symbol.
  template <typename Base>
  inline
  Parser::basic_symbol<Base>::basic_symbol ()
    : value ()
  {}

  template <typename Base>
  inline
  Parser::basic_symbol<Base>::basic_symbol (const basic_symbol& other)
    : Base (other)
    , value ()
  {
    value = other.value;
  }


  template <typename Base>
  inline
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const semantic_type& v)
    : Base (t)
    , value (v)
  {}


  /// Constructor for valueless symbols.
  template <typename Base>
  inline
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t)
    : Base (t)
    , value ()
  {}

  template <typename Base>
  inline
  Parser::basic_symbol<Base>::~basic_symbol ()
  {
  }

  template <typename Base>
  inline
  void
  Parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move(s);
    value = s.value;
  }

  // by_type.
  inline
  Parser::by_type::by_type ()
     : type (empty)
  {}

  inline
  Parser::by_type::by_type (const by_type& other)
    : type (other.type)
  {}

  inline
  Parser::by_type::by_type (token_type t)
    : type (yytranslate_ (t))
  {}

  inline
  void
  Parser::by_type::move (by_type& that)
  {
    type = that.type;
    that.type = empty;
  }

  inline
  int
  Parser::by_type::type_get () const
  {
    return type;
  }


  // by_state.
  inline
  Parser::by_state::by_state ()
    : state (empty)
  {}

  inline
  Parser::by_state::by_state (const by_state& other)
    : state (other.state)
  {}

  inline
  void
  Parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.state = empty;
  }

  inline
  Parser::by_state::by_state (state_type s)
    : state (s)
  {}

  inline
  Parser::symbol_number_type
  Parser::by_state::type_get () const
  {
    return state == empty ? 0 : yystos_[state];
  }

  inline
  Parser::stack_symbol_type::stack_symbol_type ()
  {}


  inline
  Parser::stack_symbol_type::stack_symbol_type (state_type s, symbol_type& that)
    : super_type (s)
  {
    value = that.value;
    // that is emptied.
    that.type = empty;
  }

  inline
  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    value = that.value;
    return *this;
  }


  template <typename Base>
  inline
  void
  Parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);

    // User destructor.
    switch (yysym.type_get ())
    {
            case 30: // Identifier

#line 85 "parser.yy" // lalr1.cc:601
        { if ((yysym.value.sval))  { delete ((yysym.value.sval)); ((yysym.value.sval)) = nullptr; } }
#line 353 "parser.tab.cpp" // lalr1.cc:601
        break;

      case 31: // String

#line 85 "parser.yy" // lalr1.cc:601
        { if ((yysym.value.sval))  { delete ((yysym.value.sval)); ((yysym.value.sval)) = nullptr; } }
#line 360 "parser.tab.cpp" // lalr1.cc:601
        break;


      default:
        break;
    }
  }

#if YYDEBUG
  template <typename Base>
  void
  Parser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " (";
    YYUSE (yytype);
    yyo << ')';
  }
#endif

  inline
  void
  Parser::yypush_ (const char* m, state_type s, symbol_type& sym)
  {
    stack_symbol_type t (s, sym);
    yypush_ (m, t);
  }

  inline
  void
  Parser::yypush_ (const char* m, stack_symbol_type& s)
  {
    if (m)
      YY_SYMBOL_PRINT (m, s);
    yystack_.push (s);
  }

  inline
  void
  Parser::yypop_ (unsigned int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  Parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  Parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  Parser::debug_level_type
  Parser::debug_level () const
  {
    return yydebug_;
  }

  void
  Parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  inline Parser::state_type
  Parser::yy_lr_goto_state_ (state_type yystate, int yylhs)
  {
    int yyr = yypgoto_[yylhs - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yylhs - yyntokens_];
  }

  inline bool
  Parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  inline bool
  Parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  Parser::parse ()
  {
    /// Whether yyla contains a lookahead.
    bool yyempty = true;

    // State.
    int yyn;
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// $$ and @$.
    stack_symbol_type yylhs;

    /// The return value of parse ().
    int yyresult;

    // FIXME: This shoud be completely indented.  It is not yet to
    // avoid gratuitous conflicts when merging into the master branch.
    try
      {
    YYCDEBUG << "Starting parse" << std::endl;


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULL, 0, yyla);

    // A new symbol was pushed on the stack.
  yynewstate:
    YYCDEBUG << "Entering state " << yystack_[0].state << std::endl;

    // Accept?
    if (yystack_[0].state == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    // Backup.
  yybackup:

    // Try to take a decision without lookahead.
    yyn = yypact_[yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyempty)
      {
        YYCDEBUG << "Reading a token: ";
        try
          {
            yyla.type = yytranslate_ (yylex (&yyla.value, scanner, translator));
          }
        catch (const syntax_error& yyexc)
          {
            error (yyexc);
            goto yyerrlab1;
          }
        yyempty = false;
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      goto yydefault;

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Discard the token being shifted.
    yyempty = true;

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", yyn, yyla);
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    yylhs.state = yy_lr_goto_state_(yystack_[yylen].state, yyr1_[yyn]);
    /* If YYLEN is nonzero, implement the default value of the action:
       '$$ = $1'.  Otherwise, use the top of the stack.

       Otherwise, the following line sets YYLHS.VALUE to garbage.
       This behavior is undocumented and Bison
       users should not rely upon it.  */
    if (yylen)
      yylhs.value = yystack_[yylen - 1].value;
    else
      yylhs.value = yystack_[0].value;


    // Perform the reduction.
    YY_REDUCE_PRINT (yyn);
    try
      {
        switch (yyn)
          {
  case 2:
#line 90 "parser.yy" // lalr1.cc:846
    { (yystack_[0].value.functionDeclarationListNode)->Execute(); }
#line 593 "parser.tab.cpp" // lalr1.cc:846
    break;

  case 3:
#line 94 "parser.yy" // lalr1.cc:846
    { (yylhs.value.functionDeclarationListNode) = new FunctionDeclarationListNode((yystack_[0].value.functionNode));}
#line 599 "parser.tab.cpp" // lalr1.cc:846
    break;

  case 4:
#line 95 "parser.yy" // lalr1.cc:846
    {(yystack_[1].value.functionDeclarationListNode)->Add((yystack_[0].value.functionNode));}
#line 605 "parser.tab.cpp" // lalr1.cc:846
    break;

  case 5:
#line 99 "parser.yy" // lalr1.cc:846
    {(yylhs.value.functionNode) = new FunctionNode((yystack_[5].value.ival), (yystack_[4].value.sval), (yystack_[2].value.parameterListNode), (yystack_[0].value.statementListNode)); }
#line 611 "parser.tab.cpp" // lalr1.cc:846
    break;

  case 6:
#line 103 "parser.yy" // lalr1.cc:846
    {(yylhs.value.ival) = (yystack_[0].value.ival);}
#line 617 "parser.tab.cpp" // lalr1.cc:846
    break;

  case 7:
#line 104 "parser.yy" // lalr1.cc:846
    {(yylhs.value.ival) = (yystack_[0].value.ival);}
#line 623 "parser.tab.cpp" // lalr1.cc:846
    break;

  case 8:
#line 105 "parser.yy" // lalr1.cc:846
    {(yylhs.value.ival) = (yystack_[0].value.ival);}
#line 629 "parser.tab.cpp" // lalr1.cc:846
    break;

  case 9:
#line 109 "parser.yy" // lalr1.cc:846
    { (yylhs.value.parameterListNode) = new ParameterListNode((yystack_[0].value.parameterNode)); }
#line 635 "parser.tab.cpp" // lalr1.cc:846
    break;

  case 10:
#line 110 "parser.yy" // lalr1.cc:846
    {(yystack_[2].value.parameterListNode)->Add((yystack_[0].value.parameterNode));}
#line 641 "parser.tab.cpp" // lalr1.cc:846
    break;

  case 11:
#line 111 "parser.yy" // lalr1.cc:846
    {(yylhs.value.parameterListNode) = nullptr;}
#line 647 "parser.tab.cpp" // lalr1.cc:846
    break;

  case 12:
#line 115 "parser.yy" // lalr1.cc:846
    {(yylhs.value.parameterNode) = new ParameterNode(token::NumberType, (yystack_[0].value.sval));}
#line 653 "parser.tab.cpp" // lalr1.cc:846
    break;

  case 13:
#line 116 "parser.yy" // lalr1.cc:846
    {(yylhs.value.parameterNode) = new ParameterNode(token::TextType, (yystack_[0].value.sval));}
#line 659 "parser.tab.cpp" // lalr1.cc:846
    break;

  case 14:
#line 120 "parser.yy" // lalr1.cc:846
    {(yylhs.value.statementListNode) = (yystack_[1].value.statementListNode);}
#line 665 "parser.tab.cpp" // lalr1.cc:846
    break;

  case 15:
#line 124 "parser.yy" // lalr1.cc:846
    {(yylhs.value.statementListNode) = new StatementListNode((yystack_[0].value.pNode));}
#line 671 "parser.tab.cpp" // lalr1.cc:846
    break;

  case 16:
#line 125 "parser.yy" // lalr1.cc:846
    {(yystack_[1].value.statementListNode)->Add((yystack_[0].value.pNode));}
#line 677 "parser.tab.cpp" // lalr1.cc:846
    break;

  case 17:
#line 129 "parser.yy" // lalr1.cc:846
    { (yylhs.value.pNode) = (yystack_[1].value.parameterNode);}
#line 683 "parser.tab.cpp" // lalr1.cc:846
    break;

  case 18:
#line 130 "parser.yy" // lalr1.cc:846
    {(yylhs.value.pNode) = (yystack_[1].value.pNode);}
#line 689 "parser.tab.cpp" // lalr1.cc:846
    break;

  case 19:
#line 131 "parser.yy" // lalr1.cc:846
    { (yylhs.value.pNode) = (yystack_[1].value.pNode);}
#line 695 "parser.tab.cpp" // lalr1.cc:846
    break;

  case 20:
#line 132 "parser.yy" // lalr1.cc:846
    {(yylhs.value.pNode) = (yystack_[1].value.pNode);}
#line 701 "parser.tab.cpp" // lalr1.cc:846
    break;

  case 21:
#line 133 "parser.yy" // lalr1.cc:846
    { (yylhs.value.pNode) = (yystack_[0].value.pNode); }
#line 707 "parser.tab.cpp" // lalr1.cc:846
    break;

  case 22:
#line 134 "parser.yy" // lalr1.cc:846
    { (yylhs.value.pNode) = (yystack_[0].value.pNode); }
#line 713 "parser.tab.cpp" // lalr1.cc:846
    break;

  case 23:
#line 135 "parser.yy" // lalr1.cc:846
    { (yylhs.value.pNode) = (yystack_[1].value.pNode);}
#line 719 "parser.tab.cpp" // lalr1.cc:846
    break;

  case 24:
#line 140 "parser.yy" // lalr1.cc:846
    {(yylhs.value.pNode) = new ReturnNode((yystack_[0].value.pNode)); }
#line 725 "parser.tab.cpp" // lalr1.cc:846
    break;

  case 25:
#line 141 "parser.yy" // lalr1.cc:846
    { (yylhs.value.pNode) = new ReturnNode((yystack_[0].value.sval)); }
#line 731 "parser.tab.cpp" // lalr1.cc:846
    break;

  case 26:
#line 145 "parser.yy" // lalr1.cc:846
    { (yylhs.value.pNode) = new WhileNode((yystack_[2].value.pNode), (yystack_[0].value.statementListNode)); }
#line 737 "parser.tab.cpp" // lalr1.cc:846
    break;

  case 27:
#line 149 "parser.yy" // lalr1.cc:846
    {(yylhs.value.pNode) = new FunctionCallNode((yystack_[3].value.sval), (yystack_[1].value.expressionListNode));}
#line 743 "parser.tab.cpp" // lalr1.cc:846
    break;

  case 28:
#line 153 "parser.yy" // lalr1.cc:846
    { (yylhs.value.pNode) = new IfNode((yystack_[2].value.pNode), (yystack_[0].value.statementListNode)); }
#line 749 "parser.tab.cpp" // lalr1.cc:846
    break;

  case 29:
#line 154 "parser.yy" // lalr1.cc:846
    { (yylhs.value.pNode) = new IfNode((yystack_[4].value.pNode), (yystack_[2].value.statementListNode), (yystack_[0].value.statementListNode)); }
#line 755 "parser.tab.cpp" // lalr1.cc:846
    break;

  case 30:
#line 158 "parser.yy" // lalr1.cc:846
    { (yylhs.value.pNode) = new PrintNode((yystack_[0].value.pNode));}
#line 761 "parser.tab.cpp" // lalr1.cc:846
    break;

  case 31:
#line 159 "parser.yy" // lalr1.cc:846
    { (yylhs.value.pNode) = new PrintNode((yystack_[0].value.pNode)); }
#line 767 "parser.tab.cpp" // lalr1.cc:846
    break;

  case 32:
#line 163 "parser.yy" // lalr1.cc:846
    { (yylhs.value.pNode) = new AssignmentNode((yystack_[2].value.sval), (yystack_[0].value.pNode));}
#line 773 "parser.tab.cpp" // lalr1.cc:846
    break;

  case 33:
#line 164 "parser.yy" // lalr1.cc:846
    { (yylhs.value.pNode) = new AssignmentNode((yystack_[2].value.sval), (yystack_[0].value.pNode));}
#line 779 "parser.tab.cpp" // lalr1.cc:846
    break;

  case 34:
#line 168 "parser.yy" // lalr1.cc:846
    { (yylhs.value.pNode) = new StringLiteralNode((yystack_[0].value.sval));}
#line 785 "parser.tab.cpp" // lalr1.cc:846
    break;

  case 35:
#line 172 "parser.yy" // lalr1.cc:846
    { (yylhs.value.expressionListNode) = new ExpressionListNode((yystack_[0].value.pNode)); }
#line 791 "parser.tab.cpp" // lalr1.cc:846
    break;

  case 36:
#line 173 "parser.yy" // lalr1.cc:846
    {(yystack_[2].value.expressionListNode)->Add((yystack_[0].value.pNode));}
#line 797 "parser.tab.cpp" // lalr1.cc:846
    break;

  case 37:
#line 177 "parser.yy" // lalr1.cc:846
    { (yylhs.value.pNode) = new IdentifierNode((yystack_[0].value.sval)); }
#line 803 "parser.tab.cpp" // lalr1.cc:846
    break;

  case 38:
#line 178 "parser.yy" // lalr1.cc:846
    {(yylhs.value.pNode) = new NumberLiteralNode((yystack_[0].value.dval)); }
#line 809 "parser.tab.cpp" // lalr1.cc:846
    break;

  case 39:
#line 179 "parser.yy" // lalr1.cc:846
    { (yylhs.value.pNode) = (yystack_[0].value.pNode);}
#line 815 "parser.tab.cpp" // lalr1.cc:846
    break;

  case 40:
#line 180 "parser.yy" // lalr1.cc:846
    { (yylhs.value.pNode) = new OperatorNode(token::UMINUS, (yystack_[0].value.pNode)); }
#line 821 "parser.tab.cpp" // lalr1.cc:846
    break;

  case 41:
#line 181 "parser.yy" // lalr1.cc:846
    { (yylhs.value.pNode) = new OperatorNode(token::ADD, (yystack_[2].value.pNode), (yystack_[0].value.pNode)); }
#line 827 "parser.tab.cpp" // lalr1.cc:846
    break;

  case 42:
#line 182 "parser.yy" // lalr1.cc:846
    { (yylhs.value.pNode) = new OperatorNode(token::SUB, (yystack_[2].value.pNode), (yystack_[0].value.pNode)); }
#line 833 "parser.tab.cpp" // lalr1.cc:846
    break;

  case 43:
#line 183 "parser.yy" // lalr1.cc:846
    { (yylhs.value.pNode) = new OperatorNode(token::MUL, (yystack_[2].value.pNode), (yystack_[0].value.pNode)); }
#line 839 "parser.tab.cpp" // lalr1.cc:846
    break;

  case 44:
#line 184 "parser.yy" // lalr1.cc:846
    { (yylhs.value.pNode) = new OperatorNode(token::DIV, (yystack_[2].value.pNode), (yystack_[0].value.pNode)); }
#line 845 "parser.tab.cpp" // lalr1.cc:846
    break;

  case 45:
#line 185 "parser.yy" // lalr1.cc:846
    { (yylhs.value.pNode) = new OperatorNode(token::LT, (yystack_[2].value.pNode), (yystack_[0].value.pNode)); }
#line 851 "parser.tab.cpp" // lalr1.cc:846
    break;

  case 46:
#line 186 "parser.yy" // lalr1.cc:846
    { (yylhs.value.pNode) = new OperatorNode(token::GT, (yystack_[2].value.pNode), (yystack_[0].value.pNode)); }
#line 857 "parser.tab.cpp" // lalr1.cc:846
    break;

  case 47:
#line 187 "parser.yy" // lalr1.cc:846
    { (yylhs.value.pNode) = new OperatorNode(token::GE, (yystack_[2].value.pNode), (yystack_[0].value.pNode)); }
#line 863 "parser.tab.cpp" // lalr1.cc:846
    break;

  case 48:
#line 188 "parser.yy" // lalr1.cc:846
    { (yylhs.value.pNode) = new OperatorNode(token::LE, (yystack_[2].value.pNode), (yystack_[0].value.pNode)); }
#line 869 "parser.tab.cpp" // lalr1.cc:846
    break;

  case 49:
#line 189 "parser.yy" // lalr1.cc:846
    { (yylhs.value.pNode) = new OperatorNode(token::NE, (yystack_[2].value.pNode), (yystack_[0].value.pNode)); }
#line 875 "parser.tab.cpp" // lalr1.cc:846
    break;

  case 50:
#line 190 "parser.yy" // lalr1.cc:846
    { (yylhs.value.pNode) = new OperatorNode(token::EQ, (yystack_[2].value.pNode), (yystack_[0].value.pNode)); }
#line 881 "parser.tab.cpp" // lalr1.cc:846
    break;

  case 51:
#line 191 "parser.yy" // lalr1.cc:846
    { (yylhs.value.pNode) = (yystack_[1].value.pNode); }
#line 887 "parser.tab.cpp" // lalr1.cc:846
    break;


#line 891 "parser.tab.cpp" // lalr1.cc:846
          default:
            break;
          }
      }
    catch (const syntax_error& yyexc)
      {
        error (yyexc);
        YYERROR;
      }
    YY_SYMBOL_PRINT ("-> $$ =", yylhs);
    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();

    // Shift the result of the reduction.
    yypush_ (YY_NULL, yylhs);
    goto yynewstate;

  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yysyntax_error_ (yystack_[0].state,
                                           yyempty ? yyempty_ : yyla.type_get ()));
      }


    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyempty)
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyempty = true;
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:

    /* Pacify compilers like GCC when the user code never invokes
       YYERROR and the label yyerrorlab therefore never appears in user
       code.  */
    if (false)
      goto yyerrorlab;
    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yyterror_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }


      // Shift the error token.
      error_token.state = yyn;
      yypush_ ("Shifting", error_token);
    }
    goto yynewstate;

    // Accept.
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    // Abort.
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (!yyempty)
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack"
                 << std::endl;
        // Do not try to display the values of the reclaimed symbols,
        // as their printer might throw an exception.
        if (!yyempty)
          yy_destroy_ (YY_NULL, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULL, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
  }

  void
  Parser::error (const syntax_error& yyexc)
  {
    error (yyexc.what());
  }

  // Generate an error message.
  std::string
  Parser::yysyntax_error_ (state_type yystate, symbol_number_type yytoken) const
  {
    std::string yyres;
    // Number of reported tokens (one for the "unexpected", one per
    // "expected").
    size_t yycount = 0;
    // Its maximum.
    enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
    // Arguments of yyformat.
    char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];

    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yytoken) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state
         merging (from LALR or IELR) and default reductions corrupt the
         expected token list.  However, the list is correct for
         canonical LR with one exception: it will still contain any
         token that will not be accepted due to an error action in a
         later state.
    */
    if (yytoken != yyempty_)
      {
        yyarg[yycount++] = yytname_[yytoken];
        int yyn = yypact_[yystate];
        if (!yy_pact_value_is_default_ (yyn))
          {
            /* Start YYX at -YYN if negative to avoid negative indexes in
               YYCHECK.  In other words, skip the first -YYN actions for
               this state because they are default actions.  */
            int yyxbegin = yyn < 0 ? -yyn : 0;
            // Stay within bounds of both yycheck and yytname.
            int yychecklim = yylast_ - yyn + 1;
            int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
            for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
              if (yycheck_[yyx + yyn] == yyx && yyx != yyterror_
                  && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
                {
                  if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                    {
                      yycount = 1;
                      break;
                    }
                  else
                    yyarg[yycount++] = yytname_[yyx];
                }
          }
      }

    char const* yyformat = YY_NULL;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
        YYCASE_(0, YY_("syntax error"));
        YYCASE_(1, YY_("syntax error, unexpected %s"));
        YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    // Argument number.
    size_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += yytnamerr_ (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char Parser::yypact_ninf_ = -63;

  const signed char Parser::yytable_ninf_ = -1;

  const signed char
  Parser::yypact_[] =
  {
      32,   -63,   -63,   -63,    18,    32,   -63,    -9,   -63,   -63,
      -5,    36,     4,    26,    66,   -63,   -63,   -63,    40,    36,
       3,   -63,   -63,    72,    89,    48,    52,   -16,    85,    71,
     -63,    86,   -63,    87,   -63,    88,    90,    76,    76,    76,
     -63,    94,   -63,    76,   -63,   -63,   106,   -63,   106,    76,
      48,   -63,   -63,   -63,   -63,   -63,   -63,   -63,    -2,    43,
     -63,    62,    76,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    69,   106,   -63,   106,    40,    40,   -63,    80,
      80,    80,    80,    80,    80,   108,   108,   -63,   -63,   -63,
      76,   113,   -63,   106,    40,   -63
  };

  const unsigned char
  Parser::yydefact_[] =
  {
       0,     6,     7,     8,     0,     2,     3,     0,     1,     4,
       0,    11,     0,     0,     0,     9,    12,    13,     0,     0,
       0,     5,    10,     0,     0,     0,     0,     0,     0,     0,
      15,     0,    21,     0,    22,     0,     0,     0,     0,     0,
      38,    37,    34,     0,    39,    31,    30,    25,    24,     0,
       0,    17,    14,    16,    23,    20,    19,    18,     0,     0,
      40,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    35,    33,    32,     0,     0,    51,    47,
      48,    50,    49,    46,    45,    42,    41,    43,    44,    27,
       0,    28,    26,    36,     0,    29
  };

  const signed char
  Parser::yypgoto_[] =
  {
     -63,   -63,   -63,   124,   -63,   -63,    75,   -62,   -63,   101,
     -63,   -63,     6,   -63,   -63,   -63,    81,   -63,   -26
  };

  const signed char
  Parser::yydefgoto_[] =
  {
      -1,     4,     5,     6,     7,    14,    28,    21,    29,    30,
      31,    32,    44,    34,    35,    36,    45,    72,    46
  };

  const unsigned char
  Parser::yytable_[] =
  {
      48,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    58,    59,    60,    91,    92,    49,    61,     8,    23,
      24,    10,    50,    73,    75,    25,    33,    11,    26,    12,
      13,    76,    95,    27,    16,    33,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    17,    39,     1,     2,
       3,    39,    12,    13,    93,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    20,    77,    40,    41,    42,
      43,    40,    41,    47,    43,    39,    15,    23,    24,    68,
      69,    70,    71,    25,    22,    78,    26,    12,    13,    18,
      19,    27,    89,    90,    37,    40,    41,    52,    43,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    70,
      71,    38,    51,    54,    55,    56,    49,    57,    94,     9,
      53,    74
  };

  const unsigned char
  Parser::yycheck_[] =
  {
      26,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    37,    38,    39,    76,    77,    32,    43,     0,    16,
      17,    30,    38,    49,    50,    22,    20,    32,    25,    26,
      27,    33,    94,    30,    30,    29,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    30,     9,    26,    27,
      28,     9,    26,    27,    90,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    35,    33,    29,    30,    31,
      32,    29,    30,    31,    32,     9,    11,    16,    17,     9,
      10,    11,    12,    22,    19,    33,    25,    26,    27,    33,
      34,    30,    33,    34,    32,    29,    30,    36,    32,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    11,
      12,    32,    37,    37,    37,    37,    32,    37,    15,     5,
      29,    50
  };

  const unsigned char
  Parser::yystos_[] =
  {
       0,    26,    27,    28,    40,    41,    42,    43,     0,    42,
      30,    32,    26,    27,    44,    45,    30,    30,    33,    34,
      35,    46,    45,    16,    17,    22,    25,    30,    45,    47,
      48,    49,    50,    51,    52,    53,    54,    32,    32,     9,
      29,    30,    31,    32,    51,    55,    57,    31,    57,    32,
      38,    37,    36,    48,    37,    37,    37,    37,    57,    57,
      57,    57,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    56,    57,    55,    57,    33,    33,    33,    57,
      57,    57,    57,    57,    57,    57,    57,    57,    57,    33,
      34,    46,    46,    57,    15,    46
  };

  const unsigned char
  Parser::yyr1_[] =
  {
       0,    39,    40,    41,    41,    42,    43,    43,    43,    44,
      44,    44,    45,    45,    46,    47,    47,    48,    48,    48,
      48,    48,    48,    48,    49,    49,    50,    51,    52,    52,
      53,    53,    54,    54,    55,    56,    56,    57,    57,    57,
      57,    57,    57,    57,    57,    57,    57,    57,    57,    57,
      57,    57
  };

  const unsigned char
  Parser::yyr2_[] =
  {
       0,     2,     1,     1,     2,     6,     1,     1,     1,     1,
       3,     0,     2,     2,     3,     1,     2,     2,     2,     2,
       2,     1,     1,     2,     2,     2,     5,     4,     5,     7,
       2,     2,     3,     3,     1,     1,     3,     1,     1,     1,
       2,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const Parser::yytname_[] =
  {
  "\"end of file\"", "error", "$undefined", "GE", "LE", "EQ", "NE", "'>'",
  "'<'", "'-'", "'+'", "'*'", "'/'", "UMINUS", "IFX", "ELSE", "IF",
  "While", "ADD", "SUB", "MUL", "DIV", "PRINT", "LT", "GT", "RETURN",
  "NumberType", "TextType", "VoidType", "Number", "Identifier", "String",
  "'('", "')'", "','", "'{'", "'}'", "';'", "'='", "$accept", "program",
  "function_declaration_list", "function_declaration", "type",
  "parameter_declaration_list", "parameter_declaration", "function_body",
  "statement_list", "statement", "return", "while_loop", "function_call",
  "if", "print", "assignment", "string_expression", "expression_list",
  "numerical_expression", YY_NULL
  };

#if YYDEBUG
  const unsigned char
  Parser::yyrline_[] =
  {
       0,    90,    90,    94,    95,    99,   103,   104,   105,   109,
     110,   111,   115,   116,   120,   124,   125,   129,   130,   131,
     132,   133,   134,   135,   140,   141,   145,   149,   153,   154,
     158,   159,   163,   164,   168,   172,   173,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191
  };

  // Print the state stack on the debug stream.
  void
  Parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << i->state;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  Parser::yy_reduce_print_ (int yyrule)
  {
    unsigned int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):" << std::endl;
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG

  // Symbol number corresponding to token number t.
  inline
  Parser::token_number_type
  Parser::yytranslate_ (int t)
  {
    static
    const token_number_type
    translate_table[] =
    {
     0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      32,    33,    11,    10,    34,     9,     2,    12,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    37,
       8,    38,     7,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    35,     2,    36,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31
    };
    const unsigned int user_token_number_max_ = 280;
    const token_number_type undef_token_ = 2;

    if (static_cast<int>(t) <= yyeof_)
      return yyeof_;
    else if (static_cast<unsigned int> (t) <= user_token_number_max_)
      return translate_table[t];
    else
      return undef_token_;
  }

#line 5 "parser.yy" // lalr1.cc:1156
} // Language
#line 1375 "parser.tab.cpp" // lalr1.cc:1156
#line 196 "parser.yy" // lalr1.cc:1157




void
Language::Parser::error( const std::string &err_message )
{
   std::cerr << "Error: Line:" << lineNumber << "' - " << err_message << "\n";
}


/* include for access to scanner.yylex */
#include "scanner.hpp"
static int
yylex( Language::Parser::semantic_type *yylval,
       Language::Scanner  &scanner,
       Language::Translator   &translator )
{
   return( scanner.yylex(yylval) );
}
