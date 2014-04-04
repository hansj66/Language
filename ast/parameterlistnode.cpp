#include "parameterlistnode.h"

namespace Language
{
    ParameterListNode::ParameterListNode()
    {
    }

    ParameterListNode::ParameterListNode(ParameterNode * parameter)
    {
          _parameters.push_back(parameter);
    }

    void ParameterListNode::Add(ParameterNode * parameter)
    {
        _parameters.push_back(parameter);
    }

    int ParameterListNode::Count()
    {
        return _parameters.size();
    }

    ParameterNode * ParameterListNode::at(int i)
    {
        return _parameters.at(i);
    }
}

