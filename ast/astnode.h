#ifndef ASTNODE_H
#define ASTNODE_H

#include <QVariant>

#include "parser.tab.hpp"

typedef Language::Parser::token token;

namespace Language
{
    class ASTNode
    {
    public:
        ASTNode(int type = token::VoidType);
        virtual ~ASTNode();
        virtual QVariant Execute();
        int Type();

    protected:
        int _type;
    };
}

#endif // ASTNODE_H
