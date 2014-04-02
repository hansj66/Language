#ifndef AST_H
#define AST_H

#include <string>
#include <vector>

#include <QVariant>

#include "scanner.hpp"
#include "parser.tab.hpp"

typedef Language::Parser::token token;


using namespace std;

namespace Language
{
class ASTNode
{
public:
    ASTNode();
    ASTNode(int type);
    virtual QVariant Execute();
    virtual ~ASTNode();
    int Type();

protected:
    int _type;
};

class NumberLiteralNode : public ASTNode
{
public:
    NumberLiteralNode(int value);
    QVariant Execute() override;

private:
    int _value;
};


class StringLiteralNode : public ASTNode
{
public:
    StringLiteralNode(QString * value);
    QVariant Execute() override;

private:
    QString _value;
};



class IdentifierNode : public ASTNode
{
public:
    IdentifierNode(QString * name);
    QVariant Execute() override;

private:
    QString _name;
};

class ParameterNode: public ASTNode
{
public:
    ParameterNode(token::yytokentype type, QString * name);
    QVariant Execute() override;
    QString Name();

private:
    QString  _name;
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
    OperatorNode(token::yytokentype type, ASTNode * op1, ASTNode * op2 = nullptr);
    QVariant Execute() override;

private:
    ASTNode * _op1;
    ASTNode * _op2;
    int _operator;
};

class AssignmentNode: public ASTNode
{
public:
    AssignmentNode(QString * name, ASTNode * expression);
    QVariant Execute() override;

private:
        QString _name;
        ASTNode * _expression;
};

class FunctionCallNode: public ASTNode
{
public:
    FunctionCallNode(QString * name, ExpressionListNode * expressionList);
    QVariant Execute() override;

private:
        QString * _name;
        ExpressionListNode * _expressionList;
};

class PrintNode: public ASTNode
{
public:
    PrintNode(ASTNode * expression);
    QVariant Execute() override;

private:
        ASTNode * _expression;
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

class ReturnNode: public ASTNode
{
public:
    ReturnNode(ASTNode * expression);
    QVariant Execute() override;

private:
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
    FunctionNode(int type, QString * name, ParameterListNode * arguments, StatementListNode * body);
    QVariant Execute() override;
    ParameterListNode * Arguments() const ;

private:
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

