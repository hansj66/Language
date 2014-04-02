#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H

#include "ast.h"
#include "activationrecord.h"
#include "variablerecord.h"

#include <QString>
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
    map<QString, Language::FunctionNode *> _functions;
    map<QString, VariableRecord> _variables;

public:
    static SymbolTable * Instance();

    Language::FunctionNode * Function(QString * name);
    bool DefineFunction(QString * name, Language::FunctionNode *node);

    int VariableType(QString name);
    bool DefineVariable(QString * name, int type);
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
