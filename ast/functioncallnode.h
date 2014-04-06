#ifndef FUNCTIONCALLNODE_H
#define FUNCTIONCALLNODE_H

#include "astnode.h"

namespace Language
{
    class FunctionCallNode: public ASTNode
    {
    public:
        FunctionCallNode(QString * name, ListNode<ASTNode> * expressionList);
        QVariant Execute() override;

    private:
            QString * _name;
            ListNode<ASTNode> * _expressionList;
    };
}

#endif // FUNCTIONCALLNODE_H
