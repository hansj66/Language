#ifndef WHILENODE_H
#define WHILENODE_H

#include "astnode.h"

namespace Language
{
    class WhileNode: public ASTNode
    {
    public:
        WhileNode(ASTNode * expression, ASTNode * body);
        QVariant Execute() override;

    private:
            ASTNode * _body;
            ASTNode * _expression;
    };
}

#endif // WHILENODE_H
