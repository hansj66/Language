#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H

#include "ast.h"
#include "activationrecord.h"
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

public:
    static SymbolTable * Instance();

    bool DefineFunction(string name, Language::FunctionNode *node);
    Language::FunctionNode * EntryPoint();
    ActivationRecord * GetActivationRecord();
    void PushAR();
    void PopAR();
    QVariant PopArgument();
    void PushArgument(QVariant argument);
    void PushCommandLineArguments(const int argc, const char **argv);
 };

#endif // SYMBOLTABLE_H
