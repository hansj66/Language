#ifndef EXPRESSIONLISTNODE_H
#define EXPRESSIONLISTNODE_H
#include "astnode.h"

namespace Language
{
    class ExpressionListNode: public ASTNode, public std::vector<ASTNode *>
    {
    public:
        ExpressionListNode();
        ExpressionListNode(ASTNode * expression);
    };
}

#endif // EXPRESSIONLISTNODE_H
