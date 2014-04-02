#include "symboltable.h"
#include <map>
#include "ast.h"
#include "errors.h"

extern int lineNumber;

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

Language::FunctionNode * SymbolTable::Function(QString * name)
{
    auto fp = _functions[*name];
    if (nullptr == fp)
    {
        std::cerr << UNDEFINED_FUNCTION << "(" << name->toStdString() << ")\n";
        exit(EXIT_FAILURE);
    }
    return fp;
}


 bool SymbolTable::DefineFunction(QString * name, Language::FunctionNode *node)
 {
        // TODO: Check for duplicates. Return false if duplicate

     if ("main" == *name)
         _entrypoint = node;

     _functions[*name] = node;

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

string SymbolTable::TypeName(int type) const
{
    switch(type)
    {
        case token::NumberType: return "Number";
        case token::TextType: return "Text";
        case token::VoidType: return "Void";
        default: std::cerr << "Woops, forgot to map type name...\n";
                              exit(EXIT_FAILURE);
    }
}

int SymbolTable::VariableType(QString name)
{
    if (_variables.count(name) == 0)
    {
        std::cerr << UNDEFINED_VARIABLE << "(" << name.toStdString() << " line: " << lineNumber << ")\n";
        exit(EXIT_FAILURE);
    }
    return _variables[name].type;
}

bool SymbolTable::DefineVariable(QString * name, int type)
{
    if (_variables.count(*name) != 0)
    {
        std::cerr << VARIABLE_REDECLARATION << "(" << name->toStdString() << ", line: " << lineNumber << ")\n";
        exit(EXIT_FAILURE);
    }

    std::cout << "Defining variable: " << name->toStdString() << std::endl;
    VariableRecord r;
    r.type = type;
    _variables[*name] = r;

    return true;
}

void SymbolTable::ClearVariables()
{
    _variables.clear();
}




