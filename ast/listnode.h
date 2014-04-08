#ifndef LISTNODE_H
#define LISTNODE_H

#include "astnode.h"

namespace Language
{
    template <class T >
    class ListNode: public ASTNode, public std::vector<T *>
    {
    public:
        ListNode() {}
        ListNode(T * node) { this->push_back(node); }
    };
}

#endif // LISTNODE_H
