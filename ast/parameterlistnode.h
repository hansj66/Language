#ifndef PARAMETERLISTNODE_H
#define PARAMETERLISTNODE_H

#include "astnode.h"

namespace Language
{
    class ParameterListNode: public ASTNode,  public std::vector<ParameterNode *>
    {
    public:
        ParameterListNode();
        ParameterListNode(ParameterNode * parameter);
    };
}

#endif // PARAMETERLISTNODE_H
