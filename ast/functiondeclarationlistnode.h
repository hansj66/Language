#ifndef FUNCTIONDECLARATIONLISTNODE_H
#define FUNCTIONDECLARATIONLISTNODE_H

#include "astnode.h"

namespace Language
{
    class FunctionDeclarationListNode: public ASTNode, public std::vector<FunctionNode *>
    {
    public:
        FunctionDeclarationListNode(FunctionNode * functionDeclaration);
    };
}

#endif // FUNCTIONDECLARATIONLISTNODE_H
