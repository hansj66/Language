#include <iostream>
#include <limits>
#include "symboltable.h"
#include "ast.h"
#include "errors.h"

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

ASTNode::ASTNode()
    :_type(Language::Parser::token::VoidType)
{
}


ASTNode::ASTNode(int type)
    :_type(type)
{
}

int ASTNode::Type()
{
    return _type;
}


NumberLiteralNode::NumberLiteralNode(int value)
    : ASTNode(Language::Parser::token::NumberType),
      _value(value)
{
}

QVariant NumberLiteralNode::Execute()
{
    return QString("%1").arg(_value);
}


StringLiteralNode::StringLiteralNode(string * value)
    : ASTNode(Language::Parser::token::TextType),
      _value(*value)
{
}

QVariant StringLiteralNode::Execute()
{
    return QString::fromStdString(_value);
}



IdentifierNode::IdentifierNode(string * name) : _name(*name)
{
    _type = SymbolTable::Instance()->VariableType(*name);
}

QVariant IdentifierNode::Execute()
{
    return SymbolTable::Instance()->GetActivationRecord()->GetVariableValue(_name);
}



ParameterNode::ParameterNode(Language::Parser::token::yytokentype type, string * name)
        :   ASTNode(type),
            _name(*name)
{
    SymbolTable::Instance()->DefineVariable(name, type);
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
    : ASTNode(Language::Parser::token::NumberType),
    _operator(type),
    _op1(op1),
    _op2(op2)
{
}

QVariant OperatorNode::Execute()
{
    switch(_operator)
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
        :  _name(name),
         _expressionList(expressionList)
{
    auto function = SymbolTable::Instance()->Function(name);
    auto expectedArguments = function->Arguments();

    _type = function->Type();

    if (expectedArguments->Count() != expressionList->Count())
    {
        std::cerr << WRONG_NUMBER_OF_ARGUMENTS << "(" << *name << ")\n";
        exit(EXIT_FAILURE);
    }
    for (int i=0; i<expressionList->Count(); i++)
    {
        int typeExpected = expectedArguments->at(i)->Type();
        int typeActual = expressionList->at(i)->Type();
        if (typeExpected != typeActual)
        {
            std::cerr << TYPE_CONFLICT << SymbolTable::Instance()->TypeName(typeActual) << " to " << SymbolTable::Instance()->TypeName(typeExpected) << std::endl;
            std::cerr << "in function: " << *name << std::endl;
            std::cerr << "argument: " << i << std::endl;
            exit(EXIT_FAILURE);
        }
    }

}

QVariant FunctionCallNode::Execute()
{
    // TODO: Maybe wrong order
    for (int i=0; i<_expressionList->Count(); i++)
        SymbolTable::Instance()->PushArgument(_expressionList->at(i)->Execute());
    SymbolTable::Instance()->PushArgument(_expressionList->Count());
    return SymbolTable::Instance()->Function(_name)->Execute();
}



PrintNode::PrintNode(ASTNode * expression)
        :   _expression(expression)
{
}


QVariant PrintNode::Execute()
{
    std::cout << QString("%1").arg(_expression->Execute().toString()).toStdString() << std::endl;
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
        ASTNode * pStatement = _statements.at(i);
        pStatement->Execute();
        if (dynamic_cast<ReturnNode *>(pStatement))
            break;
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


ReturnNode::ReturnNode(ASTNode * expression)
    : _expression(expression)
{
}

ReturnNode::ReturnNode(string * strExpression)
    : _strExpression(strExpression),
      _expression(nullptr)
{
}


QVariant ReturnNode::Execute()
{
    QVariant returnValue;
    if (nullptr != _expression)
        returnValue = _expression->Execute();
    else
        returnValue = QString::fromStdString(*_strExpression);

    SymbolTable::Instance()->GetActivationRecord()->SetReturnValue(returnValue);
}



IfNode::IfNode(ASTNode * expression, ASTNode * bodyTrue, ASTNode * bodyFalse)
    : _bodyTrue(bodyTrue),
      _bodyFalse(bodyFalse),
      _expression(expression)
{
}

QVariant IfNode::Execute()
{
    if (nullptr == _bodyFalse)
    {
        if ( _expression->Execute().toBool())
        {
            _bodyTrue->Execute();
        }
    }
    else
    {
        if (_expression->Execute().toBool())
        {
            _bodyTrue->Execute();
        }
        else
        {
            _bodyFalse->Execute();
        }
    }
    return ASTNode::Execute();
}


FunctionNode::FunctionNode(int type, string * name, ParameterListNode * arguments, StatementListNode * body)
        : ASTNode(type),
          _arguments(arguments),
          _body(body)
{
     SymbolTable::Instance()->DefineFunction(name,this);

     SymbolTable::Instance()->ClearVariables();
}

QVariant FunctionNode::Execute()
{
    SymbolTable::Instance()->PushAR(_type);

    int argc = SymbolTable::Instance()->PopArgument().toInt();
    if (argc != _arguments->Count())
    {
        std::cerr << STACK_CORRUPTED;
        exit(EXIT_FAILURE);
    }

    for (int i=0; i<argc; i++)
    {
        QVariant arg = SymbolTable::Instance()->PopArgument();
        string name = _arguments->at(argc-i-1)->Name();
        SymbolTable::Instance()->GetActivationRecord()->AssignVariable(name, arg);
    }

    _body->Execute();

    QVariant retVal = SymbolTable::Instance()->GetActivationRecord()->GetReturnValue();

    SymbolTable::Instance()->PopAR();

    return retVal;
}

ParameterListNode * FunctionNode::Arguments() const
{
    return _arguments;
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

