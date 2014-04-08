#include "assignmentnode.h"
#include "symboltable.h"
#include "errors.h"

extern int lineNumber;

namespace Language
{
    AssignmentNode::AssignmentNode(QString * name, ASTNode * expression)
            :  _name(*name),
             _expression(expression)
    {
        int typeActual = expression->Type();
        int typeExpected = SymbolTable::Instance().VariableType(_name);
        if (typeActual != typeExpected)
        {
            std::cerr << TYPE_CONFLICT << SymbolTable::Instance().TypeName(typeActual).toStdString() << " to " << SymbolTable::Instance().TypeName(typeExpected).toStdString() << " (line: " << lineNumber << ")" << std::endl;
            exit(EXIT_FAILURE);
        }
    }

    QVariant AssignmentNode::Execute()
    {
        SymbolTable::Instance().GetActivationRecord()->AssignVariable(_name, _expression->Execute());
        return ASTNode::Execute();
    }
}
