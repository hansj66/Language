#include "identifiernode.h"
#include "symboltable.h"

namespace Language
{
    IdentifierNode::IdentifierNode(QString * name) : _name(*name)
    {
        _type = SymbolTable::Instance()->VariableType(*name);
    }

    QVariant IdentifierNode::Execute()
    {
        return SymbolTable::Instance()->GetActivationRecord()->GetVariableValue(_name);
    }
}
