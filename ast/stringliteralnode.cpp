#include "stringliteralnode.h"

namespace Language
{
    StringLiteralNode::StringLiteralNode(QString * value)
        : ASTNode(token::TextType)
    {
        _value = value->mid(1, value->length()-2);
    }

    QVariant StringLiteralNode::Execute()
    {
        return _value;
    }
}

