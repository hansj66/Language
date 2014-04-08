#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H

#include <QString>
#include <map>
#include <stack>
#include <memory>

#include "ast.h"
#include "activationrecord.h"
#include "variablerecord.h"

class SymbolTable
{
private:
    SymbolTable();
    static std::unique_ptr<SymbolTable> _instance;
    static std::once_flag _onceFlag;

    Language::FunctionNode * _entrypoint;
    std::stack<ActivationRecord *> _activationRecordStack;
    std::stack<QVariant> _argumentStack;
    std::map<QString, Language::FunctionNode *> _functions;
    std::map<QString, VariableRecord> _variables;

public:
    static SymbolTable & Instance();

    Language::FunctionNode * Function(QString * name);
    bool DefineFunction(QString * name, Language::FunctionNode *node);

    int VariableType(QString name);
    bool DefineVariable(QString * name, int type);
    void ClearVariables();

    Language::FunctionNode * EntryPoint();
    ActivationRecord * GetActivationRecord();
    void PushAR();
    void PopAR();
    QVariant PopArgument();
    void PushArgument(QVariant argument);
    void PushCommandLineArguments(const int argc, const char **argv);

    QString TypeName(int type) const;
 };

#endif // SYMBOLTABLE_H
