#include "whilenode.h"

namespace Language
{
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
}
