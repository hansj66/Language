#include "printnode.h"

using namespace std;

namespace Language
{
    PrintNode::PrintNode(ASTNode * expression)
            :   _expression(expression)
    {
    }

    QVariant PrintNode::Execute()
    {
        cout << QString("%1").arg(_expression->Execute().toString()).toStdString() << endl;
        return ASTNode::Execute();
    }
}
