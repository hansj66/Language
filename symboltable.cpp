#include "symboltable.h"
#include <map>
#include "ast.h"


SymbolTable * SymbolTable::_instance = nullptr;

SymbolTable::SymbolTable()
    : _entrypoint(nullptr)
{
}

SymbolTable * SymbolTable::Instance()
{
    if (!_instance)
        _instance = new SymbolTable();
    return _instance;
}


 bool SymbolTable::DefineFunction(string name, Language::FunctionNode *node)
 {
        // TODO: Check for duplicates. Return false if duplicate

     if (name == "main")
         _entrypoint = node;

     return true;
 }

Language::FunctionNode * SymbolTable::EntryPoint()
{
    if (nullptr == _entrypoint)
    {
        // Error: Woops no entrypoint.
    }
    return _entrypoint;
}


ActivationRecord * SymbolTable::GetActivationRecord()
{
    return _activationRecordStack.top();
}

void SymbolTable::PushAR()
{
    qDebug() << "Pushing new activation Record on stack";
    _activationRecordStack.push(new ActivationRecord());
}

void SymbolTable::PopAR()
{
    qDebug() << "Popping current activation Record from stack";

    _activationRecordStack.pop();
}

QVariant SymbolTable::PopArgument()
{
    QVariant retVal = _argumentStack.top();
    _argumentStack.pop();
    return retVal;
}

void SymbolTable::PushArgument(QVariant argument)
{
    _argumentStack.push(argument);
}

void SymbolTable::PushCommandLineArguments(const int argc, const char **argv)
{
    for (int i=0; i<argc; i++)
    {
        _argumentStack.push(QVariant(argv[i]));
    }
}



