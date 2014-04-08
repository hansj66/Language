#include "returnnode.h"
#include "symboltable.h"

namespace Language
{
    ReturnNode::ReturnNode(ASTNode * expression)
        : _expression(expression)
    {
        _type = _expression->Type();
    }

    QVariant ReturnNode::Execute()
    {
        QVariant returnValue;
        returnValue = _expression->Execute();
        SymbolTable::Instance().GetActivationRecord()->SetReturnValue(returnValue);
        return ASTNode::Execute();
    }
}
