#include "functiondeclarationlistnode.h"

namespace Language
{
    FunctionDeclarationListNode::FunctionDeclarationListNode(FunctionNode * functionDeclaration)
    {
          push_back(functionDeclaration);
    }
}
