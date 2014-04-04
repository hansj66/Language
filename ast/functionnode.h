#ifndef FUNCTIONNODE_H
#define FUNCTIONNODE_H

#include "astnode.h"

namespace Language
{
    class FunctionNode: public ASTNode
    {
    public:
        FunctionNode(int type, QString * name, ParameterListNode * arguments, StatementListNode * body);
        QVariant Execute() override;
        ParameterListNode * Arguments() const ;

    private:
        ParameterListNode * _arguments;
        StatementListNode * _body;
    };
}

#endif // FUNCTIONNODE_H
