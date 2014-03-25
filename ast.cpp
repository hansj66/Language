#include <iostream>
#include <limits>
#include "symboltable.h"
#include "ast.h"

using namespace std;

namespace Language
{

QVariant ASTNode::Execute()
{
    return QVariant();
}

ASTNode::~ASTNode()
{
}

NumberLiteralNode::NumberLiteralNode(int value) : _value(value)
{
}

QVariant NumberLiteralNode::Execute()
{
    return _value;
}


IdentifierNode::IdentifierNode(string * name) : _name(*name)
{
}

QVariant IdentifierNode::Execute()
{
    return SymbolTable::Instance()->GetActivationRecord()->GetVariableValue(_name);
}



ParameterNode::ParameterNode(Language::Parser::token::yytokentype type, string * name)
        :   _type(type),
            _name(*name)
{
}

QVariant ParameterNode::Execute()
{
    SymbolTable::Instance()->GetActivationRecord()->DeclareVariable(_name, _type);
    return ASTNode::Execute();
}

string ParameterNode::Name()
{
    return _name;
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

ParameterNode * ParameterListNode::at(int i)
{
    return _parameters.at(i);
}

ExpressionListNode::ExpressionListNode(ASTNode * expression)
{
    _expressions.push_back(expression);
}

void ExpressionListNode::Add(ASTNode * expression)
{
    _expressions.push_back(expression);
}

int ExpressionListNode::Count()
{
    return _expressions.size();
}

ASTNode * ExpressionListNode::at(int i)
{
    return _expressions.at(i);
}


OperatorNode::OperatorNode(Language::Parser::token::yytokentype type, ASTNode * op1, ASTNode * op2)
        :
          _type(type),
          _op1(op1),
          _op2(op2)
{
    // Binary
}

QVariant OperatorNode::Execute()
{
    switch(_type)
    {
        case Language::Parser::token::UMINUS: break; // Only one op.
        case Language::Parser::token::ADD: return _op1->Execute().toDouble() + _op2->Execute().toDouble(); break;
        case Language::Parser::token::SUB: return _op1->Execute().toDouble() - _op2->Execute().toDouble(); break;
        case Language::Parser::token::MUL: return _op1->Execute().toDouble() * _op2->Execute().toDouble(); break;
        case Language::Parser::token::DIV: return _op1->Execute().toDouble() / _op2->Execute().toDouble(); break;
        case Language::Parser::token::LT: return _op1->Execute().toDouble() < _op2->Execute().toDouble();break;
        case Language::Parser::token::GT: return _op1->Execute().toDouble() > _op2->Execute().toDouble();break;
        case Language::Parser::token::GE: return _op1->Execute().toDouble() >= _op2->Execute().toDouble();break;
        case Language::Parser::token::LE: return _op1->Execute().toDouble() <= _op2->Execute().toDouble();break;
        case Language::Parser::token::NE: return _op1->Execute().toDouble() != _op2->Execute().toDouble();break;
        case Language::Parser::token::EQ: return _op1->Execute().toDouble() == _op2->Execute().toDouble();break;
        default: std::cerr << "Damn ! Looks like we forgot to implement something..." << std::endl;
            exit(EXIT_FAILURE);
    }

    return QVariant();
}


AssignmentNode::AssignmentNode(string * name, ASTNode * expression)
        :  _name(*name),
         _expression(expression)
    {
    }

QVariant AssignmentNode::Execute()
{
    SymbolTable::Instance()->GetActivationRecord()->AssignVariable(_name, _expression->Execute());
    return ASTNode::Execute();
}





FunctionCallNode::FunctionCallNode(string * name, ExpressionListNode * expressionList)
        :  _name(*name),
         _expressionList(expressionList)
{
}


QVariant FunctionCallNode::Execute()
{
    // TODO: Maybe wrong order
    for (int i=0; i<_expressionList->Count(); i++)
        SymbolTable::Instance()->PushArgument(_expressionList->at(i)->Execute());
    SymbolTable::Instance()->PushArgument(_expressionList->Count());
    SymbolTable::Instance()->Function(_name)->Execute();
    return ASTNode::Execute();
}



PrintNode::PrintNode(ASTNode * expression)
        :   _expression(expression)
{
}

PrintNode::PrintNode(string * strExpression)
        :   _expression(nullptr)
{
    _strExpression = QString::fromStdString(*strExpression).mid(1, strExpression->size()-2).toStdString();
}



QVariant PrintNode::Execute()
{
    if (nullptr != _expression)
        std::cout << QString("%1").arg(_expression->Execute().toDouble()).toStdString() << std::endl;
    else
        std::cout << _strExpression << std::endl;

    return ASTNode::Execute();
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


QVariant StatementListNode::Execute()
{
    for (size_t i=0; i<_statements.size(); i++)
    {
        _statements.at(i)->Execute();
    }

    return ASTNode::Execute();
}


WhileNode::WhileNode(ASTNode * expression, ASTNode * body)
        :  _body(body),
         _expression(expression)
{
}

QVariant WhileNode::Execute()
{
    while (_expression->Execute().toBool())
        _body->Execute();
    return ASTNode::Execute();
}



FunctionNode::FunctionNode(int type, string * name, ParameterListNode * arguments, StatementListNode * body)
        : _returnType(type),
          _arguments(arguments),
          _body(body)
{
     SymbolTable::Instance()->DefineFunction(*name,this);
}

QVariant FunctionNode::Execute()
{
    SymbolTable::Instance()->PushAR(_returnType);

    int argc = SymbolTable::Instance()->PopArgument().toInt();
    if (argc != _arguments->Count())
    {
        std::cerr << "OMG ! Someone has corrupted the stack. Bailing out...";
        exit(EXIT_FAILURE);
    }

    for (int i=0; i<argc; i++)
    {
        QVariant arg = SymbolTable::Instance()->PopArgument();
        string name = _arguments->at(argc-i-1)->Name();
        SymbolTable::Instance()->GetActivationRecord()->AssignVariable(name, arg);
    }

    _body->Execute();

    // TODO: Return values are not really implemented yet..

    QVariant retVal = SymbolTable::Instance()->GetActivationRecord()->GetReturnValue();

    SymbolTable::Instance()->PopAR();

    return retVal;
}

int FunctionNode::ReturnType()
{
    return _returnType;
}



FunctionDeclarationListNode::FunctionDeclarationListNode(FunctionNode * functionDeclaration)
{
      _functions.push_back(functionDeclaration);
}

void FunctionDeclarationListNode::Add(FunctionNode * functionDeclaration)
{
    _functions.push_back(functionDeclaration);
}

}

