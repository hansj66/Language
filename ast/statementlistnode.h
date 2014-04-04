#ifndef STATEMENTLISTNODE_H
#define STATEMENTLISTNODE_H

#include "astnode.h"

namespace Language
{
class StatementListNode: public ASTNode
{
    public:
        StatementListNode(ASTNode * parameter);
        void Add(ASTNode * parameter);
        int Count();
        QVariant Execute() override;
        ASTNode * at(int i);

    private:
        std::vector<ASTNode *> _statements;
    };
}

#endif // STATEMENTLISTNODE_H
