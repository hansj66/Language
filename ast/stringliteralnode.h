#ifndef STRINGLITERALNODE_H
#define STRINGLITERALNODE_H

#include "astnode.h"

namespace Language
{
    class StringLiteralNode : public ASTNode
    {
    public:
        StringLiteralNode(QString * value);
        QVariant Execute() override;

    private:
        QString _value;
    };
}


#endif // STRINGLITERALNODE_H
