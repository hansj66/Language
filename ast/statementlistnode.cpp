#include "statementlistnode.h"
#include "returnnode.h"

namespace Language
{
    StatementListNode::StatementListNode(ASTNode * parameter)
    {
          push_back(parameter);
    }

    QVariant StatementListNode::Execute()
    {
        for (auto statement: *this)
        {
            statement->Execute();
            if (dynamic_cast<ReturnNode *>(statement))
                break;
        }

        return ASTNode::Execute();
    }
}
