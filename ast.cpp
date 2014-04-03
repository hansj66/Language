#include <iostream>
#include <limits>
#include "symboltable.h"
#include "ast.h"
#include "errors.h"

using namespace std;
extern int lineNumber;


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
    :_type(token::VoidType)
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
    : ASTNode(token::NumberType),
      _value(value)
{
}

QVariant NumberLiteralNode::Execute()
{
    return QString("%1").arg(_value);
}


StringLiteralNode::StringLiteralNode(QString * value)
    : ASTNode(token::TextType)
{
    _value = value->mid(1, value->length()-2);
}

QVariant StringLiteralNode::Execute()
{
    return _value;
}



IdentifierNode::IdentifierNode(QString * name) : _name(*name)
{
    _type = SymbolTable::Instance()->VariableType(*name);
}

QVariant IdentifierNode::Execute()
{
    return SymbolTable::Instance()->GetActivationRecord()->GetVariableValue(_name);
}


ParameterNode::ParameterNode(int type, QString * name, ASTNode * initializer)
        :   ASTNode(type),
            _name(*name),
        _initializer(initializer)
{
    SymbolTable::Instance()->DefineVariable(name, type);
}



ParameterNode::ParameterNode(int type, QString * name)
        :   ASTNode(type),
            _name(*name)
{
    if (token::NumberType == type)
        _initializer = new NumberLiteralNode(0);
    if (token::TextType == type)
        _initializer = new StringLiteralNode(new QString());

    SymbolTable::Instance()->DefineVariable(name, type);
}


QVariant ParameterNode::Execute()
{
    SymbolTable::Instance()->GetActivationRecord()->DeclareVariable(_name);
    if (nullptr != _initializer)
        SymbolTable::Instance()->GetActivationRecord()->AssignVariable(_name, _initializer->Execute());
    return ASTNode::Execute();
}

QString ParameterNode::Name()
{
    return _name;
}


ParameterListNode::ParameterListNode()
{

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

ExpressionListNode::ExpressionListNode()
{
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


OperatorNode::OperatorNode(token::yytokentype type, ASTNode * op1, ASTNode * op2)
    : _op1(op1),
    _op2(op2),
    _operator(type)
{
    _type = token::NumberType;

    if (nullptr == op2)
        return;
    if ((_op1->Type() == token::TextType) || (_op2->Type() == token::TextType))
    {
       if (_operator == token::ADD)
        {
             _type = token::TextType;
        }
       else if ((_operator != token::EQ) && (_operator != token::NE))
        {
            std::cout << NO_STRINGS_PLEASE << "(line: " << lineNumber << ")" << std::endl;
            exit(EXIT_FAILURE);
        }
    }
}

QVariant OperatorNode::Execute()
{
    switch(_operator)
    {
        case token::UMINUS: return -_op1->Execute().toDouble(); break;
        case token::ADD: if ((_op1->Type() == token::TextType) ||
                                                                   (_op1->Type() == token::TextType))
                                                                    return QString("%1%2").arg(_op1->Execute().toString()).arg(_op2->Execute().toString());
                                                                return _op1->Execute().toDouble() + _op2->Execute().toDouble(); break;
        case token::SUB: return _op1->Execute().toDouble() - _op2->Execute().toDouble(); break;
        case token::MUL: return _op1->Execute().toDouble() * _op2->Execute().toDouble(); break;
        case token::DIV: return _op1->Execute().toDouble() / _op2->Execute().toDouble(); break;
        case token::LT: return _op1->Execute().toDouble() < _op2->Execute().toDouble();break;
        case token::GT: return _op1->Execute().toDouble() > _op2->Execute().toDouble();break;
        case token::GE: return _op1->Execute().toDouble() >= _op2->Execute().toDouble();break;
        case token::LE: return _op1->Execute().toDouble() <= _op2->Execute().toDouble();break;
        case token::NE: return _op1->Execute() != _op2->Execute();break;
        case token::EQ: return _op1->Execute() == _op2->Execute();break;
        default: std::cerr << "Damn ! Looks like we forgot to implement something..." << std::endl;
            exit(EXIT_FAILURE);
    }

    return QVariant();
}


AssignmentNode::AssignmentNode(QString * name, ASTNode * expression)
        :  _name(*name),
         _expression(expression)
{
    int typeActual = expression->Type();
    int typeExpected = SymbolTable::Instance()->VariableType(_name);
    if (typeActual != typeExpected)
    {
        std::cerr << TYPE_CONFLICT << SymbolTable::Instance()->TypeName(typeActual) << " to " << SymbolTable::Instance()->TypeName(typeExpected) << " (line: " << lineNumber << ")" << std::endl;
        exit(EXIT_FAILURE);
    }
}

QVariant AssignmentNode::Execute()
{
    SymbolTable::Instance()->GetActivationRecord()->AssignVariable(_name, _expression->Execute());
    return ASTNode::Execute();
}





FunctionCallNode::FunctionCallNode(QString * name, ExpressionListNode * expressionList)
        :  _name(name),
         _expressionList(expressionList)
{
    auto function = SymbolTable::Instance()->Function(name);
    auto expectedArguments = function->Arguments();

    _type = function->Type();

    if (expectedArguments->Count() != expressionList->Count())
    {
        std::cerr << WRONG_NUMBER_OF_ARGUMENTS << "(" << name->toStdString() << ")\n";
        exit(EXIT_FAILURE);
    }
    for (int i=0; i<expressionList->Count(); i++)
    {
        int typeExpected = expectedArguments->at(i)->Type();
        int typeActual = expressionList->at(i)->Type();
        if (typeExpected != typeActual)
        {
            std::cerr << TYPE_CONFLICT << SymbolTable::Instance()->TypeName(typeActual) << " to " << SymbolTable::Instance()->TypeName(typeExpected) << std::endl;
            std::cerr << "in function: " << name->toStdString() << std::endl;
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

ASTNode * StatementListNode::at(int i)
{
    return _statements.at(i);
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
    _type = _expression->Type();
}


QVariant ReturnNode::Execute()
{
    QVariant returnValue;
    returnValue = _expression->Execute();
    SymbolTable::Instance()->GetActivationRecord()->SetReturnValue(returnValue);
    return ASTNode::Execute();
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


FunctionNode::FunctionNode(int type, QString * name, ParameterListNode * arguments, StatementListNode * body)
        : ASTNode(type),
          _arguments(arguments),
          _body(body)
{
     SymbolTable::Instance()->DefineFunction(name,this);

     for (int i=0; i<body->Count(); i++)
     {
        ASTNode * pStatement = body->at(i);
         if (auto pReturn = dynamic_cast<ReturnNode *>(pStatement))
         {
             int typeActual = pReturn->Type();
             if (pStatement->Type() != _type)
             {
                 std::cerr << TYPE_CONFLICT << SymbolTable::Instance()->TypeName(typeActual) << " to " << SymbolTable::Instance()->TypeName(_type) << " (line: " << lineNumber << ")" << std::endl;
                 exit(EXIT_FAILURE);
             }
         }
     }

     SymbolTable::Instance()->ClearVariables();
}

QVariant FunctionNode::Execute()
{
    SymbolTable::Instance()->PushAR();

    int argc = SymbolTable::Instance()->PopArgument().toInt();
    if (argc != _arguments->Count())
    {
        std::cerr << STACK_CORRUPTED;
        exit(EXIT_FAILURE);
    }

    for (int i=0; i<argc; i++)
    {
        QVariant arg = SymbolTable::Instance()->PopArgument();
        QString name = _arguments->at(argc-i-1)->Name();
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

