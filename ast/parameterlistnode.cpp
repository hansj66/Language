#include "parameterlistnode.h"

namespace Language
{
    ParameterListNode::ParameterListNode()
    {
    }

    ParameterListNode::ParameterListNode(ParameterNode * parameter)
    {
        push_back(parameter);
    }
}

