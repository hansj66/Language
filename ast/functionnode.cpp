#include "functionnode.h"
#include "symboltable.h"
#include "errors.h"

extern int lineNumber;

namespace Language
{
    FunctionNode::FunctionNode(int type, QString * name, ParameterListNode * arguments, StatementListNode * body)
            : ASTNode(type),
              _arguments(arguments),
              _body(body)
    {
         SymbolTable::Instance()->DefineFunction(name,this);

         for (auto i=0; i<body->size(); i++)
         {
            ASTNode * pStatement = body->at(i);
             if (auto pReturn = dynamic_cast<ReturnNode *>(pStatement))
             {
                 int typeActual = pReturn->Type();
                 if (pStatement->Type() != _type)
                 {
                     std::cerr << TYPE_CONFLICT << SymbolTable::Instance()->TypeName(typeActual) << " to " << SymbolTable::Instance()->TypeName(_type) << " (line: " << lineNumber << ")" << std::endl;
                     exit(EXIT_FAILURE);
                 }
             }
         }
         SymbolTable::Instance()->ClearVariables();
    }

    QVariant FunctionNode::Execute()
    {
        SymbolTable::Instance()->PushAR();

        int argc = SymbolTable::Instance()->PopArgument().toInt();
        if (argc != _arguments->size())
        {
            std::cerr << STACK_CORRUPTED;
            exit(EXIT_FAILURE);
        }

        for (int i=0; i<argc; i++)
        {
            QVariant arg = SymbolTable::Instance()->PopArgument();
            QString name = _arguments->at(argc-i-1)->Name();
            SymbolTable::Instance()->GetActivationRecord()->AssignVariable(name, arg);
        }

        _body->Execute();

        QVariant retVal = SymbolTable::Instance()->GetActivationRecord()->GetReturnValue();

        SymbolTable::Instance()->PopAR();

        return retVal;
    }

    ParameterListNode * FunctionNode::Arguments() const
    {
        return _arguments;
    }
}
