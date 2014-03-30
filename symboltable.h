#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H

#include "ast.h"
#include "activationrecord.h"
#include "variablerecord.h"

#include <string>
#include <map>
#include <stack>

using namespace std;

class SymbolTable
{
private:
    SymbolTable();
    static SymbolTable * _instance;

    Language::FunctionNode * _entrypoint;
    stack<ActivationRecord *> _activationRecordStack;
    stack<QVariant> _argumentStack;
    map<string, Language::FunctionNode *> _functions;
    map<string, VariableRecord> _variables;

public:
    static SymbolTable * Instance();

    Language::FunctionNode * Function(string * name);
    bool DefineFunction(string * name, Language::FunctionNode *node);

    int VariableType(string name);
    bool DefineVariable(string * name, int type);
    void ClearVariables();

    Language::FunctionNode * EntryPoint();
    ActivationRecord * GetActivationRecord();
    void PushAR(int _returnType);
    void PopAR();
    QVariant PopArgument();
    void PushArgument(QVariant argument);
    void PushCommandLineArguments(const int argc, const char **argv);

    string TypeName(int type) const;
 };

#endif // SYMBOLTABLE_H
