#ifndef EXPRESSIONLISTNODE_H
#define EXPRESSIONLISTNODE_H
#include "astnode.h"

namespace Language
{
    class ExpressionListNode: public ASTNode
    {
    public:
        ExpressionListNode();
        ExpressionListNode(ASTNode * expression);
        void Add(ASTNode * expression);
        int Count();
        ASTNode * at(int i);

    private:
        std::vector<ASTNode *> _expressions;
    };
}

#endif // EXPRESSIONLISTNODE_H
