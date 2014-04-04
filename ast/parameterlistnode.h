#ifndef PARAMETERLISTNODE_H
#define PARAMETERLISTNODE_H

#include "astnode.h"

namespace Language
{
    class ParameterListNode: public ASTNode
    {
    public:
        ParameterListNode();
        ParameterListNode(ParameterNode * parameter);
        void Add(ParameterNode * parameter);
        int Count();
        ParameterNode * at(int i);

    private:
        std::vector<ParameterNode *> _parameters;
    };
}

#endif // PARAMETERLISTNODE_H
