#ifndef FUNCTIONNODE_H
#define FUNCTIONNODE_H

#include "astnode.h"

namespace Language
{
    class FunctionNode: public ASTNode
    {
    public:
        FunctionNode(int type, QString * name, ListNode<ParameterNode> * arguments, StatementListNode * body);
        QVariant Execute() override;
        ListNode<ParameterNode> * Arguments() const ;

    private:
        ListNode<ParameterNode> * _arguments;
        StatementListNode * _body;
    };
}

#endif // FUNCTIONNODE_H
