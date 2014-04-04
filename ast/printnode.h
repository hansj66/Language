#ifndef PRINTNODE_H
#define PRINTNODE_H

#include "astnode.h"

namespace Language
{
    class PrintNode: public ASTNode
    {
    public:
        PrintNode(ASTNode * expression);
        QVariant Execute() override;

    private:
            ASTNode * _expression;
    };
}

#endif // PRINTNODE_H
