#ifndef STATEMENTLISTNODE_H
#define STATEMENTLISTNODE_H

#include "astnode.h"
#include "listnode.h"

namespace Language
{
class StatementListNode: public ListNode<ASTNode>
{
    public:
        StatementListNode(ASTNode * parameter);
        QVariant Execute() override;
    };
}

#endif // STATEMENTLISTNODE_H
