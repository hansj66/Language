#ifndef FUNCTIONDECLARATIONLISTNODE_H
#define FUNCTIONDECLARATIONLISTNODE_H

#include "astnode.h"

namespace Language
{
    class FunctionDeclarationListNode: public ASTNode
    {
    public:
        FunctionDeclarationListNode(FunctionNode * functionDeclaration);
        void Add(FunctionNode * functionDeclaration);

    private:
        std::vector<FunctionNode *> _functions;
    };
}

#endif // FUNCTIONDECLARATIONLISTNODE_H
