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
#line 28 "parser.y" // lalr1.cc:407


    #include <iostream>
    #include <cstdlib>
    #include <fstream>
    #include <QString>

    #include "ast.h"
    #include "translator.hpp"
    #include "symboltable.h"

    extern int lineNumber;

    static int yylex(Language::Parser::semantic_type *yylval, Language::Lexer  &lexer);

#line 69 "parser.tab.cpp" // lalr1.cc:407


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

#line 5 "parser.y" // lalr1.cc:473
namespace Language {
#line 136 "parser.tab.cpp" // lalr1.cc:473

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
  Parser::Parser (Lexer  &lexer_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      lexer (lexer_yyarg)
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
    YYUSE (yysym.type_get ());
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
            yyla.type = yytranslate_ (yylex (&yyla.value, lexer));
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
#line 84 "parser.y" // lalr1.cc:846
    { (yystack_[0].value.functionDeclarationListNode)->Execute(); }
#line 570 "parser.tab.cpp" // lalr1.cc:846
    break;

  case 3:
#line 88 "parser.y" // lalr1.cc:846
    { (yylhs.value.functionDeclarationListNode) = new FunctionDeclarationListNode((yystack_[0].value.functionNode));}
#line 576 "parser.tab.cpp" // lalr1.cc:846
    break;

  case 4:
#line 89 "parser.y" // lalr1.cc:846
    {(yystack_[1].value.functionDeclarationListNode)->Add((yystack_[0].value.functionNode));}
#line 582 "parser.tab.cpp" // lalr1.cc:846
    break;

  case 5:
#line 93 "parser.y" // lalr1.cc:846
    {(yylhs.value.functionNode) = new FunctionNode((yystack_[5].value.ival), (yystack_[4].value.sval), (yystack_[2].value.parameterListNode), (yystack_[0].value.statementListNode)); }
#line 588 "parser.tab.cpp" // lalr1.cc:846
    break;

  case 6:
#line 97 "parser.y" // lalr1.cc:846
    {(yylhs.value.ival) = token::NumberType;}
#line 594 "parser.tab.cpp" // lalr1.cc:846
    break;

  case 7:
#line 98 "parser.y" // lalr1.cc:846
    {(yylhs.value.ival) = token::TextType;}
#line 600 "parser.tab.cpp" // lalr1.cc:846
    break;

  case 8:
#line 99 "parser.y" // lalr1.cc:846
    {(yylhs.value.ival) = token::VoidType;}
#line 606 "parser.tab.cpp" // lalr1.cc:846
    break;

  case 9:
#line 103 "parser.y" // lalr1.cc:846
    { (yylhs.value.parameterListNode) = new ParameterListNode((yystack_[0].value.parameterNode)); }
#line 612 "parser.tab.cpp" // lalr1.cc:846
    break;

  case 10:
#line 104 "parser.y" // lalr1.cc:846
    {(yystack_[2].value.parameterListNode)->Add((yystack_[0].value.parameterNode));}
#line 618 "parser.tab.cpp" // lalr1.cc:846
    break;

  case 11:
#line 105 "parser.y" // lalr1.cc:846
    {(yylhs.value.parameterListNode) = new ParameterListNode();}
#line 624 "parser.tab.cpp" // lalr1.cc:846
    break;

  case 12:
#line 109 "parser.y" // lalr1.cc:846
    {(yylhs.value.parameterNode) = new ParameterNode((yystack_[1].value.ival), (yystack_[0].value.sval));}
#line 630 "parser.tab.cpp" // lalr1.cc:846
    break;

  case 13:
#line 110 "parser.y" // lalr1.cc:846
    {(yylhs.value.parameterNode) = new ParameterNode((yystack_[3].value.ival), (yystack_[2].value.sval), (yystack_[0].value.pNode));}
#line 636 "parser.tab.cpp" // lalr1.cc:846
    break;

  case 14:
#line 114 "parser.y" // lalr1.cc:846
    {(yylhs.value.statementListNode) = (yystack_[1].value.statementListNode);}
#line 642 "parser.tab.cpp" // lalr1.cc:846
    break;

  case 15:
#line 118 "parser.y" // lalr1.cc:846
    {(yylhs.value.statementListNode) = new StatementListNode((yystack_[0].value.pNode));}
#line 648 "parser.tab.cpp" // lalr1.cc:846
    break;

  case 16:
#line 119 "parser.y" // lalr1.cc:846
    {(yystack_[1].value.statementListNode)->Add((yystack_[0].value.pNode));}
#line 654 "parser.tab.cpp" // lalr1.cc:846
    break;

  case 17:
#line 123 "parser.y" // lalr1.cc:846
    { (yylhs.value.pNode) = (yystack_[1].value.parameterNode);}
#line 660 "parser.tab.cpp" // lalr1.cc:846
    break;

  case 18:
#line 124 "parser.y" // lalr1.cc:846
    {(yylhs.value.pNode) = (yystack_[1].value.pNode);}
#line 666 "parser.tab.cpp" // lalr1.cc:846
    break;

  case 19:
#line 125 "parser.y" // lalr1.cc:846
    { (yylhs.value.pNode) = (yystack_[1].value.pNode);}
#line 672 "parser.tab.cpp" // lalr1.cc:846
    break;

  case 20:
#line 126 "parser.y" // lalr1.cc:846
    {(yylhs.value.pNode) = (yystack_[1].value.pNode);}
#line 678 "parser.tab.cpp" // lalr1.cc:846
    break;

  case 21:
#line 127 "parser.y" // lalr1.cc:846
    { (yylhs.value.pNode) = (yystack_[0].value.pNode); }
#line 684 "parser.tab.cpp" // lalr1.cc:846
    break;

  case 22:
#line 128 "parser.y" // lalr1.cc:846
    { (yylhs.value.pNode) = (yystack_[0].value.pNode); }
#line 690 "parser.tab.cpp" // lalr1.cc:846
    break;

  case 23:
#line 129 "parser.y" // lalr1.cc:846
    { (yylhs.value.pNode) = (yystack_[1].value.pNode);}
#line 696 "parser.tab.cpp" // lalr1.cc:846
    break;

  case 24:
#line 134 "parser.y" // lalr1.cc:846
    {(yylhs.value.pNode) = new ReturnNode((yystack_[0].value.pNode)); }
#line 702 "parser.tab.cpp" // lalr1.cc:846
    break;

  case 25:
#line 138 "parser.y" // lalr1.cc:846
    { (yylhs.value.pNode) = new WhileNode((yystack_[2].value.pNode), (yystack_[0].value.statementListNode)); }
#line 708 "parser.tab.cpp" // lalr1.cc:846
    break;

  case 26:
#line 142 "parser.y" // lalr1.cc:846
    {(yylhs.value.pNode) = new FunctionCallNode((yystack_[3].value.sval), (yystack_[1].value.expressionListNode));}
#line 714 "parser.tab.cpp" // lalr1.cc:846
    break;

  case 27:
#line 146 "parser.y" // lalr1.cc:846
    { (yylhs.value.pNode) = new IfNode((yystack_[2].value.pNode), (yystack_[0].value.statementListNode)); }
#line 720 "parser.tab.cpp" // lalr1.cc:846
    break;

  case 28:
#line 147 "parser.y" // lalr1.cc:846
    { (yylhs.value.pNode) = new IfNode((yystack_[4].value.pNode), (yystack_[2].value.statementListNode), (yystack_[0].value.statementListNode)); }
#line 726 "parser.tab.cpp" // lalr1.cc:846
    break;

  case 29:
#line 151 "parser.y" // lalr1.cc:846
    { (yylhs.value.pNode) = new PrintNode((yystack_[0].value.pNode));}
#line 732 "parser.tab.cpp" // lalr1.cc:846
    break;

  case 30:
#line 155 "parser.y" // lalr1.cc:846
    { (yylhs.value.pNode) = new AssignmentNode((yystack_[2].value.sval), (yystack_[0].value.pNode));}
#line 738 "parser.tab.cpp" // lalr1.cc:846
    break;

  case 31:
#line 159 "parser.y" // lalr1.cc:846
    { (yylhs.value.expressionListNode) = new ExpressionListNode((yystack_[0].value.pNode)); }
#line 744 "parser.tab.cpp" // lalr1.cc:846
    break;

  case 32:
#line 160 "parser.y" // lalr1.cc:846
    {(yystack_[2].value.expressionListNode)->Add((yystack_[0].value.pNode));}
#line 750 "parser.tab.cpp" // lalr1.cc:846
    break;

  case 33:
#line 161 "parser.y" // lalr1.cc:846
    {(yylhs.value.expressionListNode) = new ExpressionListNode(); }
#line 756 "parser.tab.cpp" // lalr1.cc:846
    break;

  case 34:
#line 165 "parser.y" // lalr1.cc:846
    { (yylhs.value.pNode) = new IdentifierNode((yystack_[0].value.sval)); }
#line 762 "parser.tab.cpp" // lalr1.cc:846
    break;

  case 35:
#line 166 "parser.y" // lalr1.cc:846
    { (yylhs.value.pNode) = new StringLiteralNode((yystack_[0].value.sval));}
#line 768 "parser.tab.cpp" // lalr1.cc:846
    break;

  case 36:
#line 167 "parser.y" // lalr1.cc:846
    {(yylhs.value.pNode) = new NumberLiteralNode((yystack_[0].value.dval)); }
#line 774 "parser.tab.cpp" // lalr1.cc:846
    break;

  case 37:
#line 168 "parser.y" // lalr1.cc:846
    { (yylhs.value.pNode) = (yystack_[0].value.pNode);}
#line 780 "parser.tab.cpp" // lalr1.cc:846
    break;

  case 38:
#line 169 "parser.y" // lalr1.cc:846
    { (yylhs.value.pNode) = new OperatorNode(token::UMINUS, (yystack_[0].value.pNode)); }
#line 786 "parser.tab.cpp" // lalr1.cc:846
    break;

  case 39:
#line 170 "parser.y" // lalr1.cc:846
    { (yylhs.value.pNode) = new OperatorNode(token::ADD, (yystack_[2].value.pNode), (yystack_[0].value.pNode)); }
#line 792 "parser.tab.cpp" // lalr1.cc:846
    break;

  case 40:
#line 171 "parser.y" // lalr1.cc:846
    { (yylhs.value.pNode) = new OperatorNode(token::SUB, (yystack_[2].value.pNode), (yystack_[0].value.pNode)); }
#line 798 "parser.tab.cpp" // lalr1.cc:846
    break;

  case 41:
#line 172 "parser.y" // lalr1.cc:846
    { (yylhs.value.pNode) = new OperatorNode(token::MUL, (yystack_[2].value.pNode), (yystack_[0].value.pNode)); }
#line 804 "parser.tab.cpp" // lalr1.cc:846
    break;

  case 42:
#line 173 "parser.y" // lalr1.cc:846
    { (yylhs.value.pNode) = new OperatorNode(token::DIV, (yystack_[2].value.pNode), (yystack_[0].value.pNode)); }
#line 810 "parser.tab.cpp" // lalr1.cc:846
    break;

  case 43:
#line 174 "parser.y" // lalr1.cc:846
    { (yylhs.value.pNode) = new OperatorNode(token::LT, (yystack_[2].value.pNode), (yystack_[0].value.pNode)); }
#line 816 "parser.tab.cpp" // lalr1.cc:846
    break;

  case 44:
#line 175 "parser.y" // lalr1.cc:846
    { (yylhs.value.pNode) = new OperatorNode(token::GT, (yystack_[2].value.pNode), (yystack_[0].value.pNode)); }
#line 822 "parser.tab.cpp" // lalr1.cc:846
    break;

  case 45:
#line 176 "parser.y" // lalr1.cc:846
    { (yylhs.value.pNode) = new OperatorNode(token::GE, (yystack_[2].value.pNode), (yystack_[0].value.pNode)); }
#line 828 "parser.tab.cpp" // lalr1.cc:846
    break;

  case 46:
#line 177 "parser.y" // lalr1.cc:846
    { (yylhs.value.pNode) = new OperatorNode(token::LE, (yystack_[2].value.pNode), (yystack_[0].value.pNode)); }
#line 834 "parser.tab.cpp" // lalr1.cc:846
    break;

  case 47:
#line 178 "parser.y" // lalr1.cc:846
    { (yylhs.value.pNode) = new OperatorNode(token::NE, (yystack_[2].value.pNode), (yystack_[0].value.pNode)); }
#line 840 "parser.tab.cpp" // lalr1.cc:846
    break;

  case 48:
#line 179 "parser.y" // lalr1.cc:846
    { (yylhs.value.pNode) = new OperatorNode(token::EQ, (yystack_[2].value.pNode), (yystack_[0].value.pNode)); }
#line 846 "parser.tab.cpp" // lalr1.cc:846
    break;

  case 49:
#line 180 "parser.y" // lalr1.cc:846
    { (yylhs.value.pNode) = (yystack_[1].value.pNode); }
#line 852 "parser.tab.cpp" // lalr1.cc:846
    break;


#line 856 "parser.tab.cpp" // lalr1.cc:846
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


  const signed char Parser::yypact_ninf_ = -25;

  const signed char Parser::yytable_ninf_ = -1;

  const signed char
  Parser::yypact_[] =
  {
      88,   -25,   -25,   -25,     2,    88,   -25,   -24,   -25,   -25,
      -9,    88,     7,    41,   -25,     5,    26,    88,    55,    73,
     -25,   -25,    55,   -25,    37,   -25,    55,   -25,   101,    48,
      70,    55,    55,     4,    33,    51,   -25,    45,   -25,    81,
     -25,    83,    84,   -25,    55,     8,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,   101,   101,
      55,   -25,   -25,   -25,   -25,   -25,   -25,   -25,    63,   101,
     -25,    82,    82,    82,    82,    82,    82,   106,   106,   -25,
     -25,    39,    49,   101,   -25,    55,    26,    26,   101,   105,
     -25,    26,   -25
  };

  const unsigned char
  Parser::yydefact_[] =
  {
       0,     6,     7,     8,     0,     2,     3,     0,     1,     4,
       0,    11,     0,     0,     9,    12,     0,     0,     0,     0,
       5,    10,     0,    36,    34,    35,     0,    37,    13,     0,
       0,     0,     0,     0,     0,     0,    15,     0,    21,     0,
      22,     0,     0,    38,    33,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    29,    24,
       0,    17,    14,    16,    23,    20,    19,    18,     0,    31,
      49,    45,    46,    48,    47,    44,    43,    40,    39,    41,
      42,     0,     0,    30,    26,     0,     0,     0,    32,    27,
      25,     0,    28
  };

  const signed char
  Parser::yypgoto_[] =
  {
     -25,   -25,   -25,   118,     3,   -25,   -10,   -21,   -25,    89,
     -25,   -25,   -14,   -25,   -25,   -25,   -25,   -22
  };

  const signed char
  Parser::yydefgoto_[] =
  {
      -1,     4,     5,     6,    12,    13,    34,    20,    35,    36,
      37,    38,    27,    40,    41,    42,    68,    28
  };

  const unsigned char
  Parser::yytable_[] =
  {
      43,    14,     8,     7,    45,    39,    10,    21,     7,    58,
      59,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    39,    69,    11,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    44,    15,    83,    60,
      18,    70,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    19,    88,    22,    89,    90,    29,    30,    44,
      92,    61,    86,    31,    16,    17,    32,     1,     2,     3,
      56,    33,    87,    64,    23,    24,    25,    26,    62,    29,
      30,    52,    53,    54,    55,    31,    84,    85,    32,     1,
       2,     3,    57,    33,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,     1,     2,     3,    54,    55,    65,
      91,    66,    67,     9,    63
  };

  const unsigned char
  Parser::yycheck_[] =
  {
      22,    11,     0,     0,    26,    19,    30,    17,     5,    31,
      32,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    35,    44,    32,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    32,    30,    60,    35,
      35,    33,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    36,    85,     9,    86,    87,    16,    17,    32,
      91,    38,    33,    22,    33,    34,    25,    26,    27,    28,
      32,    30,    33,    38,    29,    30,    31,    32,    37,    16,
      17,     9,    10,    11,    12,    22,    33,    34,    25,    26,
      27,    28,    32,    30,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    26,    27,    28,    11,    12,    38,
      15,    38,    38,     5,    35
  };

  const unsigned char
  Parser::yystos_[] =
  {
       0,    26,    27,    28,    40,    41,    42,    43,     0,    42,
      30,    32,    43,    44,    45,    30,    33,    34,    35,    36,
      46,    45,     9,    29,    30,    31,    32,    51,    56,    16,
      17,    22,    25,    30,    45,    47,    48,    49,    50,    51,
      52,    53,    54,    56,    32,    56,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    32,    32,    56,    56,
      35,    38,    37,    48,    38,    38,    38,    38,    55,    56,
      33,    56,    56,    56,    56,    56,    56,    56,    56,    56,
      56,    56,    56,    56,    33,    34,    33,    33,    56,    46,
      46,    15,    46
  };

  const unsigned char
  Parser::yyr1_[] =
  {
       0,    39,    40,    41,    41,    42,    43,    43,    43,    44,
      44,    44,    45,    45,    46,    47,    47,    48,    48,    48,
      48,    48,    48,    48,    49,    50,    51,    52,    52,    53,
      54,    55,    55,    55,    56,    56,    56,    56,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    56,    56
  };

  const unsigned char
  Parser::yyr2_[] =
  {
       0,     2,     1,     1,     2,     6,     1,     1,     1,     1,
       3,     0,     2,     4,     3,     1,     2,     2,     2,     2,
       2,     1,     1,     2,     2,     5,     4,     5,     7,     2,
       3,     1,     3,     0,     1,     1,     1,     1,     2,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3
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
  "'('", "')'", "','", "'='", "'{'", "'}'", "';'", "$accept", "program",
  "function_declaration_list", "function_declaration", "type",
  "parameter_declaration_list", "parameter_declaration", "function_body",
  "statement_list", "statement", "return", "while_loop", "function_call",
  "if", "print", "assignment", "expression_list", "expression", YY_NULL
  };

#if YYDEBUG
  const unsigned char
  Parser::yyrline_[] =
  {
       0,    84,    84,    88,    89,    93,    97,    98,    99,   103,
     104,   105,   109,   110,   114,   118,   119,   123,   124,   125,
     126,   127,   128,   129,   134,   138,   142,   146,   147,   151,
     155,   159,   160,   161,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180
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
       2,     2,     2,     2,     2,     2,     2,     2,     2,    38,
       8,    35,     7,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    36,     2,    37,     2,     2,     2,     2,
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

#line 5 "parser.y" // lalr1.cc:1156
} // Language
#line 1334 "parser.tab.cpp" // lalr1.cc:1156
#line 185 "parser.y" // lalr1.cc:1157




void
Language::Parser::error( const std::string &err_message )
{
   std::cerr << "Error: Line:" << lineNumber << "' - " << err_message << "\n";
}


#include "lexer.hpp"
static int yylex( Language::Parser::semantic_type *yylval, Language::Lexer  &lexer)
{
   return( lexer.yylex(yylval) );
}

