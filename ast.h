#ifndef AST_H
#define AST_H

#include <string>
#include <vector>

#include <QVariant>

#include "scanner.hpp"
#include "parser.tab.hpp"


using namespace std;

namespace Language
{
class ASTNode
{
public:
    virtual QVariant Execute();
    virtual ~ASTNode();
};

class NumberLiteralNode : public ASTNode
{
public:
    NumberLiteralNode(int value);
    QVariant Execute() override;

private:
    int _value;
};

class IdentifierNode : public ASTNode
{
public:
    IdentifierNode(string * name);
    QVariant Execute() override;

private:
    string _name;
};

class ParameterNode: public ASTNode
{
public:
    ParameterNode(Language::Parser::token::yytokentype type, string * name);
    QVariant Execute() override;
    string Name();

private:
    int _type;
    string  _name;
};

class ParameterListNode: public ASTNode
{
public:
    ParameterListNode(ParameterNode * parameter);
    void Add(ParameterNode * parameter);
    int Count();
    ParameterNode * at(int i);

private:
    std::vector<ParameterNode *> _parameters;
};

class ExpressionListNode: public ASTNode
{
public:
    ExpressionListNode(ASTNode * expression);
    void Add(ASTNode * expression);
    int Count();
    ASTNode * at(int i);

private:
    std::vector<ASTNode *> _expressions;
};

class OperatorNode: public ASTNode
{
public:
    OperatorNode(Language::Parser::token::yytokentype type, ASTNode * op1, ASTNode * op2 = nullptr);
    QVariant Execute() override;

private:
    Language::Parser::token::yytokentype _type;
    ASTNode * _op1;
    ASTNode * _op2;
};

class AssignmentNode: public ASTNode
{
public:
    AssignmentNode(string * name, ASTNode * expression);
    QVariant Execute() override;

private:
        string _name;
        ASTNode * _expression;
};

class FunctionCallNode: public ASTNode
{
public:
    FunctionCallNode(string * name, ExpressionListNode * expressionList);
    QVariant Execute() override;

private:
        string _name;
        ExpressionListNode * _expressionList;
};

class PrintNode: public ASTNode
{
public:
    PrintNode(ASTNode * expression);
    PrintNode(string * strExpression);
    QVariant Execute() override;

private:
        ASTNode * _expression;
        string _strExpression;
};

class StatementListNode: public ASTNode
{
public:
    StatementListNode(ASTNode * parameter);
    void Add(ASTNode * parameter);
    int Count();
    QVariant Execute() override;

private:
    std::vector<ASTNode *> _statements;
};

class WhileNode: public ASTNode
{
public:
    WhileNode(ASTNode * expression, ASTNode * body);
    QVariant Execute() override;


private:
        ASTNode * _body;
        ASTNode * _expression;
};


class IfNode: public ASTNode
{
public:
    IfNode(ASTNode * expression, ASTNode * bodyTrue, ASTNode * bodyFalse = nullptr);
    QVariant Execute() override;

private:
        ASTNode * _bodyTrue;
        ASTNode * _bodyFalse;
        ASTNode * _expression;
};

class FunctionNode: public ASTNode
{
public:
    FunctionNode(int type, string * name, ParameterListNode * arguments, StatementListNode * body);
    QVariant Execute() override;
    int ReturnType();

private:
    int _returnType;
    ParameterListNode * _arguments;
    StatementListNode * _body;
};

class FunctionDeclarationListNode: public ASTNode
{
public:
    FunctionDeclarationListNode(FunctionNode * functionDeclaration);
    void Add(FunctionNode * functionDeclaration);

private:
    std::vector<FunctionNode *> _functions;
};





}

#endif // AST_H

