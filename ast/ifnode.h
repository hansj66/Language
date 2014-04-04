#ifndef IFNODE_H
#define IFNODE_H

#include "astnode.h"

namespace Language
{
    class IfNode: public ASTNode
    {
    public:
        IfNode(ASTNode * expression, ASTNode * bodyTrue, ASTNode * bodyFalse = nullptr);
        QVariant Execute() override;

    private:
            ASTNode * _bodyTrue;
            ASTNode * _bodyFalse;
            ASTNode * _expression;
    };
}

#endif // IFNODE_H
