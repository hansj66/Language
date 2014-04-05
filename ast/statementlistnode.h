#ifndef STATEMENTLISTNODE_H
#define STATEMENTLISTNODE_H

#include "astnode.h"

namespace Language
{
class StatementListNode: public ASTNode, public std::vector<ASTNode *>
{
    public:
        StatementListNode(ASTNode * parameter);
        QVariant Execute() override;
    };
}

#endif // STATEMENTLISTNODE_H
