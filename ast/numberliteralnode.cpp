#include "numberliteralnode.h"

namespace Language
{
    NumberLiteralNode::NumberLiteralNode(int value)
        : ASTNode(token::NumberType),
          _value(value)
    {
    }

    QVariant NumberLiteralNode::Execute()
    {
        return QString("%1").arg(_value);
    }
}

