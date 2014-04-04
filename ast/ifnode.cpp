#include "ifnode.h"

namespace Language
{
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
}
