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
    virtual void Execute()
    {
        qDebug() << "No implementation..";
    }

  virtual ~ASTNode() {}
};

class IntegerLiteralNode : public ASTNode
{
public:
    IntegerLiteralNode(int value) : _value(value) {}

private:
    int _value;
};

class IdentifierNode : public ASTNode
{
public:
    IdentifierNode(string * name) : _name(name) {}

private:
    string * _name;
};

class ParameterNode: public ASTNode
{
public:
    ParameterNode(string * typeName, string * name, int initializer = 0)
        :   _typeName(typeName),
            _name(name),
            _initializer(initializer)
    {}

private:
    string *_typeName;
    string * _name;
    int _initializer;
};


class ParameterListNode: public ASTNode
{
public:
    ParameterListNode(ASTNode * parameter)
    {
          _parameters.push_back(parameter);
    }

    void Add(ASTNode * parameter)
    {
        _parameters.push_back(parameter);
    }

private:
    std::vector<ASTNode *> _parameters;
};

class OperatorNode: public ASTNode
{
public:
    OperatorNode(Language::Parser::token::yytokentype type, ASTNode * op1):
        _type(type),
        _op1(op1)
    {
        // Unary
    }

    OperatorNode(Language::Parser::token::yytokentype type, ASTNode * op1, ASTNode * op2)
        :
          _type(type),
          _op1(op1),
          _op2(op2)
    {
        // Binary
    }

private:
    Language::Parser::token::yytokentype _type;
    ASTNode * _op1;
    ASTNode * _op2;
};

class AssignmentNode: public ASTNode
{
public:
    AssignmentNode(string * name, ASTNode * expression)
        :  _name(name),
         _expression(expression)
    {
    }

private:
        string * _name;
        ASTNode * _expression;
};

class PrintNode: public ASTNode
{
public:
    PrintNode(ASTNode * expression)
        :   _expression(expression)
    {
    }

private:
        ASTNode * _expression;
};


class StatementListNode: public ASTNode
{
public:
    StatementListNode(ASTNode * parameter)
    {
          _statements.push_back(parameter);
    }

    void Add(ASTNode * parameter)
    {
        _statements.push_back(parameter);
    }

private:
    std::vector<ASTNode *> _statements;
};


class FunctionDeclarationNode: public ASTNode
{
public:
    FunctionDeclarationNode(string * type, string * name, ASTNode * arguments, ASTNode * body)
        : _type(type),
          _name(name),
          _arguments(arguments),
          _body(body)
    {
    }

private:
    string * _type;
    string * _name;
    ASTNode * _arguments;
    ASTNode * _body;
};


class FunctionDeclarationListNode: public ASTNode
{
public:
    FunctionDeclarationListNode(ASTNode * functionDeclaration)
    {
          _functions.push_back(functionDeclaration);
    }

    void Add(ASTNode * functionDeclaration)
    {
        _functions.push_back(functionDeclaration);
    }

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
