#ifndef NUMBERLITERALNODE_H
#define NUMBERLITERALNODE_H

#include "astnode.h"

namespace Language
{
    class NumberLiteralNode : public ASTNode
    {
    public:
        NumberLiteralNode(int value);
        QVariant Execute() override;

    private:
        int _value;
    };
}

#endif // NUMBERLITERALNODE_H
