#ifndef FUNCTIONCALLNODE_H
#define FUNCTIONCALLNODE_H

#include "astnode.h"

namespace Language
{
    class FunctionCallNode: public ASTNode
    {
    public:
        FunctionCallNode(QString * name, ExpressionListNode * expressionList);
        QVariant Execute() override;

    private:
            QString * _name;
            ExpressionListNode * _expressionList;
    };
}

#endif // FUNCTIONCALLNODE_H
