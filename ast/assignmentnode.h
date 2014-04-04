#ifndef ASSIGNMENTNODE_H
#define ASSIGNMENTNODE_H

#include "astnode.h"

namespace Language
{
    class AssignmentNode: public ASTNode
    {
    public:
        AssignmentNode(QString * name, ASTNode * expression);
        QVariant Execute() override;

    private:
            QString _name;
            ASTNode * _expression;
    };
}

#endif // ASSIGNMENTNODE_H
