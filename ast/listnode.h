#ifndef LISTNODE_H
#define LISTNODE_H

#include "astnode.h"

using namespace std;

namespace Language
{
    template <class T >
    class ListNode: public ASTNode, public vector<T *>
    {
    public:
        ListNode() {}
        ListNode(T * node) { this->push_back(node); }
    };
}

#endif // LISTNODE_H
