#include "symboltable.h"
#include "ast.h"


using namespace std;

namespace Language
{

void ASTNode::Execute()
{
    qDebug() << "No implementation..";
}

ASTNode::~ASTNode()
{

}


NumberLiteralNode::NumberLiteralNode(int value) : _value(value)
{
}


IdentifierNode::IdentifierNode(string * name) : _name(name)
{
}


ParameterNode::ParameterNode(Language::Parser::token::yytokentype type, string * name)
        :   _type(type),
            _name(*name)
{
}

void ParameterNode::Execute()
{
    qDebug() << "Declaring: " << QString::fromStdString(_name) << " Type: " << _type;
}


ParameterListNode::ParameterListNode(ParameterNode * parameter)
{
      _parameters.push_back(parameter);
}

void ParameterListNode::Add(ParameterNode * parameter)
{
    _parameters.push_back(parameter);
}

int ParameterListNode::Count()
{
    return _parameters.size();
}

ExpressionListNode::ExpressionListNode(ASTNode * expression)
{
    _expressions.push_back(expression);
}

void ExpressionListNode::Add(ASTNode * expression)
{
    _expressions.push_back(expression);
}


OperatorNode::OperatorNode(Language::Parser::token::yytokentype type, ASTNode * op1)
    : _type(type),
       _op1(op1)
{
    // Unary
}

OperatorNode::OperatorNode(Language::Parser::token::yytokentype type, ASTNode * op1, ASTNode * op2)
        :
          _type(type),
          _op1(op1),
          _op2(op2)
{
    // Binary
}

AssignmentNode::AssignmentNode(string * name, ASTNode * expression)
        :  _name(name),
         _expression(expression)
    {
    }

FunctionCallNode::FunctionCallNode(string * name, ASTNode * expression)
        :  _name(name),
         _expression(expression)
    {
    }


PrintNode::PrintNode(ASTNode * expression)
        :   _expression(expression)
    {
    }

StatementListNode::StatementListNode(ASTNode * parameter)
{
      _statements.push_back(parameter);
}

void StatementListNode::Add(ASTNode * parameter)
{
    _statements.push_back(parameter);
}

int StatementListNode::Count()
{
    return _statements.size();
}


void StatementListNode::Execute()
{
    for (int i=0; i<_statements.size(); i++)
    {
        _statements.at(i)->Execute();
    }
}


WhileNode::WhileNode(ASTNode * expression, ASTNode * body)
        :  _body(body),
         _expression(expression)
{
}


FunctionNode::FunctionNode(string * type, string * name, ParameterListNode * arguments, StatementListNode * body)
        : _type(type),
          _name(name),
          _arguments(arguments),
          _body(body)
{
     SymbolTable::Instance()->DefineFunction(*name,this);
}

void FunctionNode::Execute()
{
    qDebug() << "Executing function" << QString::fromStdString(*_name);
 //   qDebug() << "   type" << QString::fromStdString(*type);
    qDebug() << "   arguments: " << _arguments->Count();
    qDebug() << "   statements: " << _body->Count();

    SymbolTable::Instance()->PushAR();

    // Declare variables in AR
    // Pop arguments from argstack and define them in AR

    _body->Execute();

    SymbolTable::Instance()->PopAR();
}


FunctionDeclarationListNode::FunctionDeclarationListNode(ASTNode * functionDeclaration)
{
      _functions.push_back(functionDeclaration);
}

void FunctionDeclarationListNode::Add(ASTNode * functionDeclaration)
{
    _functions.push_back(functionDeclaration);
}


/*
class UnaryOperatorNode: public ASTNode
{
public:
    UnaryOperatorNode(Language::Parser::token type, );
};

*/
}

