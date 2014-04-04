#include "functiondeclarationlistnode.h"

namespace Language
{
    FunctionDeclarationListNode::FunctionDeclarationListNode(FunctionNode * functionDeclaration)
    {
          _functions.push_back(functionDeclaration);
    }

    void FunctionDeclarationListNode::Add(FunctionNode * functionDeclaration)
    {
        _functions.push_back(functionDeclaration);
    }
}
