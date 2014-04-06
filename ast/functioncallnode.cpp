#include "functioncallnode.h"

#include "symboltable.h"
#include "errors.h"

namespace Language
{
    FunctionCallNode::FunctionCallNode(QString * name, ListNode<ASTNode> * expressionList)
            :  _name(name),
             _expressionList(expressionList)
    {
        auto function = SymbolTable::Instance()->Function(name);
        auto expectedArguments = function->Arguments();

        _type = function->Type();

        if (expectedArguments->size() != expressionList->size())
        {
            std::cerr << WRONG_NUMBER_OF_ARGUMENTS << "(" << name->toStdString() << ")\n";
            exit(EXIT_FAILURE);
        }

        for (int i=0; i<expectedArguments->size(); i++)
        {
            int typeExpected = expectedArguments->at(i)->Type();
            int typeActual = expressionList->at(i)->Type();
            if (typeExpected != typeActual)
            {
                std::cerr << TYPE_CONFLICT << SymbolTable::Instance()->TypeName(typeActual) << " to " << SymbolTable::Instance()->TypeName(typeExpected) << std::endl;
                std::cerr << "in function: " << name->toStdString() << std::endl;
                std::cerr << "argument: " << i << std::endl;
                exit(EXIT_FAILURE);
            }
        }


    }

    QVariant FunctionCallNode::Execute()
    {
        // TODO: Maybe wrong order
        for (auto expression: *_expressionList)
            SymbolTable::Instance()->PushArgument(expression->Execute());
        SymbolTable::Instance()->PushArgument((int)_expressionList->size());
        return SymbolTable::Instance()->Function(_name)->Execute();
    }
}
