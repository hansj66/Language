#ifndef RETURNNODE_H
#define RETURNNODE_H

#include "astnode.h"

namespace Language
{
    class ReturnNode: public ASTNode
    {
    public:
        ReturnNode(ASTNode * expression);
        QVariant Execute() override;

    private:
            ASTNode * _expression;
    };
}

#endif // RETURNNODE_H
