#include "expressionlistnode.h"

namespace Language
{
    ExpressionListNode::ExpressionListNode()
    {
    }

    ExpressionListNode::ExpressionListNode(ASTNode * expression)
    {
        push_back(expression);
    }
}
