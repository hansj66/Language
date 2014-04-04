#ifndef IDENTIFIERNODE_H
#define IDENTIFIERNODE_H

#include "astnode.h"

namespace Language
{
    class IdentifierNode : public ASTNode
    {
    public:
        IdentifierNode(QString * name);
        QVariant Execute() override;

    private:
        QString _name;
    };
}

#endif // IDENTIFIERNODE_H
