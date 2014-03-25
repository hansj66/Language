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

Language::FunctionNode * SymbolTable::Function(string name)
{
    // TOD: Check for existence

    return _functions[name];
}


 bool SymbolTable::DefineFunction(string name, Language::FunctionNode *node)
 {
        // TODO: Check for duplicates. Return false if duplicate

     if ("main" == name)
         _entrypoint = node;

     _functions[name] = node;

     return true;
 }

Language::FunctionNode * SymbolTable::EntryPoint()
{
    if (nullptr == _entrypoint)
    {
        // Error: Woops no entrypoint.
        std::cerr << "Dang ! No entrypoint. Bailing out..." << std::endl;
        exit(1);
    }
    return _entrypoint;
}


ActivationRecord * SymbolTable::GetActivationRecord()
{
    return _activationRecordStack.top();
}

void SymbolTable::PushAR(int returnType)
{
    _activationRecordStack.push(new ActivationRecord(returnType));
}

void SymbolTable::PopAR()
{
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
    _argumentStack.push(argc);
}



