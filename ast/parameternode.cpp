#include "parameternode.h"

#include "symboltable.h"

namespace Language
{
    ParameterNode::ParameterNode(int type, QString * name, ASTNode * initializer)
            :   ASTNode(type),
                _name(*name),
            _initializer(initializer)
    {
        if (nullptr == initializer)
        {
            if (token::NumberType == type)
                _initializer = new NumberLiteralNode(0);
            if (token::TextType == type)
                _initializer = new StringLiteralNode(new QString());
        }
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
}

