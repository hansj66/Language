#include "astnode.h"

namespace Language
{
    ASTNode::ASTNode(int type)
        :_type(type)
    {
    }

    QVariant ASTNode::Execute()
    {
        return QVariant();
    }

    ASTNode::~ASTNode()
    {
    }

    int ASTNode::Type()
    {
        return _type;
    }
}
