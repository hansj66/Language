#include "symboltable.h"
#include <map>
#include "ast.h"
#include "errors.h"
#include <memory>

extern int lineNumber;

std::unique_ptr<SymbolTable> SymbolTable::_instance = nullptr;
std::once_flag SymbolTable::_onceFlag;


SymbolTable::SymbolTable()
    : _entrypoint(nullptr)
{
}

SymbolTable & SymbolTable::Instance()
{
    std::call_once(_onceFlag,
            [] {
                _instance.reset(new SymbolTable);
        });
        return *_instance.get();
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
     if (_functions.count(*name) != 0)
     {
         std::cerr << FUNCTION_REDECLARATION << "(" << name->toStdString() << ", line: " << lineNumber << ")\n";
         exit(EXIT_FAILURE);
     }

     if ("main" == *name)
         _entrypoint = node;

     _functions[*name] = node;

     return true;
 }

Language::FunctionNode * SymbolTable::EntryPoint()
{
    if (nullptr == _entrypoint)
    {
        std::cerr << "Dang ! No entrypoint. Bailing out..." << std::endl;
        exit(1);
    }
    return _entrypoint;
}

ActivationRecord * SymbolTable::GetActivationRecord()
{
    return _activationRecordStack.top();
}

void SymbolTable::PushAR()
{
    _activationRecordStack.push(new ActivationRecord());
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

QString SymbolTable::TypeName(int type) const
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

    VariableRecord r;
    r.type = type;
    _variables[*name] = r;

    return true;
}

void SymbolTable::ClearVariables()
{
    _variables.clear();
}




