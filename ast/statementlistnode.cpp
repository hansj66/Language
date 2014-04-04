#include "statementlistnode.h"
#include "returnnode.h"

namespace Language
{
    StatementListNode::StatementListNode(ASTNode * parameter)
    {
          _statements.push_back(parameter);
    }

    void StatementListNode::Add(ASTNode * parameter)
    {
        _statements.push_back(parameter);
    }

    int StatementListNode::Count()
    {
        return _statements.size();
    }

    ASTNode * StatementListNode::at(int i)
    {
        return _statements.at(i);
    }

    QVariant StatementListNode::Execute()
    {
        for (size_t i=0; i<_statements.size(); i++)
        {
            ASTNode * pStatement = _statements.at(i);
            pStatement->Execute();
            if (dynamic_cast<ReturnNode *>(pStatement))
                break;
        }

        return ASTNode::Execute();
    }
}
