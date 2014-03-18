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

class NumberLiteralNode : public ASTNode
{
public:
    NumberLiteralNode(int value) : _value(value) {}

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
    ParameterNode(Language::Parser::token::yytokentype type, string * name)
        :   _type(type),
            _name(name)
    {}

private:
    Language::Parser::token::yytokentype _type;
    string * _name;
};


class ParameterListNode: public ASTNode
{
public:
    ParameterListNode(ParameterNode * parameter)
    {
          _parameters.push_back(parameter);
    }

    void Add(ParameterNode * parameter)
    {
        _parameters.push_back(parameter);
    }

    int Count()
    {
        return _parameters.size();
    }

private:
    std::vector<ParameterNode *> _parameters;
};



class ExpressionListNode: public ASTNode
{
public:
    ExpressionListNode(ASTNode * expression)
    {
          _expressions.push_back(expression);
    }

    void Add(ASTNode * expression)
    {
        _expressions.push_back(expression);
    }

private:
    std::vector<ASTNode *> _expressions;
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



class FunctionCallNode: public ASTNode
{
public:
    FunctionCallNode(string * name, ASTNode * expression)
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
    int Count()
    {
        return _statements.size();
    }

private:
    std::vector<ASTNode *> _statements;
};


class WhileNode: public ASTNode
{
public:
    WhileNode(ASTNode * expression, ASTNode * body)
        :  _body(body),
         _expression(expression)
    {
    }

private:
        ASTNode * _body;
        ASTNode * _expression;
};


class FunctionDeclarationNode: public ASTNode
{
public:
    FunctionDeclarationNode(string * type, string * name, ParameterListNode * arguments, StatementListNode * body)
        : _type(type),
          _name(name),
          _arguments(arguments),
          _body(body)
    {
         qDebug() << "Declaring function" << QString::fromStdString(*name);
         qDebug() << "   type" << QString::fromStdString(*type);
         qDebug() << "   arguments: " << arguments->Count();
         qDebug() << "   statements: " << body->Count();
    }

private:
    string * _type;
    string * _name;
    ParameterListNode * _arguments;
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
