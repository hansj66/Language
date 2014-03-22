#ifndef AST_H
#define AST_H

#include <string>
#include <vector>

#include <QDebug>

#include "scanner.hpp"
#include "parser.tab.hpp"


using namespace std;

namespace Language
{
class ASTNode
{
public:
    virtual void Execute();
    virtual ~ASTNode();
};

class NumberLiteralNode : public ASTNode
{
public:
    NumberLiteralNode(int value);

private:
    int _value;
};

class IdentifierNode : public ASTNode
{
public:
    IdentifierNode(string * name);

private:
    string * _name;
};

class ParameterNode: public ASTNode
{
public:
    ParameterNode(Language::Parser::token::yytokentype type, string * name);
    void Execute() override;

private:
    Language::Parser::token::yytokentype _type;
    string  _name;
};

class ParameterListNode: public ASTNode
{
public:
    ParameterListNode(ParameterNode * parameter);
    void Add(ParameterNode * parameter);
    int Count();

private:
    std::vector<ParameterNode *> _parameters;
};

class ExpressionListNode: public ASTNode
{
public:
    ExpressionListNode(ASTNode * expression);
    void Add(ASTNode * expression);

private:
    std::vector<ASTNode *> _expressions;
};

class OperatorNode: public ASTNode
{
public:
    OperatorNode(Language::Parser::token::yytokentype type, ASTNode * op1);
    OperatorNode(Language::Parser::token::yytokentype type, ASTNode * op1, ASTNode * op2);

private:
    Language::Parser::token::yytokentype _type;
    ASTNode * _op1;
    ASTNode * _op2;
};

class AssignmentNode: public ASTNode
{
public:
    AssignmentNode(string * name, ASTNode * expression);

private:
        string * _name;
        ASTNode * _expression;
};

class FunctionCallNode: public ASTNode
{
public:
    FunctionCallNode(string * name, ASTNode * expression);

private:
        string * _name;
        ASTNode * _expression;
};

class PrintNode: public ASTNode
{
public:
    PrintNode(ASTNode * expression);

private:
        ASTNode * _expression;
};

class StatementListNode: public ASTNode
{
public:
    StatementListNode(ASTNode * parameter);
    void Add(ASTNode * parameter);
    int Count();
    void Execute() override;

private:
    std::vector<ASTNode *> _statements;
};

class WhileNode: public ASTNode
{
public:
    WhileNode(ASTNode * expression, ASTNode * body);

private:
        ASTNode * _body;
        ASTNode * _expression;
};

class FunctionNode: public ASTNode
{
public:
    FunctionNode(string * type, string * name, ParameterListNode * arguments, StatementListNode * body);
    void Execute() override;

private:
    string * _type;
    string * _name;
    ParameterListNode * _arguments;
    StatementListNode * _body;
};

class FunctionDeclarationListNode: public ASTNode
{
public:
    FunctionDeclarationListNode(ASTNode * functionDeclaration);
    void Add(ASTNode * functionDeclaration);

private:
    std::vector<ASTNode *> _functions;
};


/*
class UnaryOperatorNode: public ASTNode
{
public:
    UnaryOperatorNode(Language::Parser::token type, );
};

*/



}

#endif // AST_H

