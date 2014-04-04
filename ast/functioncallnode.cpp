#include "functioncallnode.h"

#include "symboltable.h"
#include "errors.h"

namespace Language
{
    FunctionCallNode::FunctionCallNode(QString * name, ExpressionListNode * expressionList)
            :  _name(name),
             _expressionList(expressionList)
    {
        auto function = SymbolTable::Instance()->Function(name);
        auto expectedArguments = function->Arguments();

        _type = function->Type();

        if (expectedArguments->Count() != expressionList->Count())
        {
            std::cerr << WRONG_NUMBER_OF_ARGUMENTS << "(" << name->toStdString() << ")\n";
            exit(EXIT_FAILURE);
        }
        for (int i=0; i<expressionList->Count(); i++)
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
        for (int i=0; i<_expressionList->Count(); i++)
            SymbolTable::Instance()->PushArgument(_expressionList->at(i)->Execute());
        SymbolTable::Instance()->PushArgument(_expressionList->Count());
        return SymbolTable::Instance()->Function(_name)->Execute();
    }
}
