#include "expressionlistnode.h"

namespace Language
{
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
}
