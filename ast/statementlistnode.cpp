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
        for (auto i=0; i<size(); i++)
        {
            ASTNode * pStatement = at(i);
            pStatement->Execute();
            if (dynamic_cast<ReturnNode *>(pStatement))
                break;
        }

        return ASTNode::Execute();
    }
}
