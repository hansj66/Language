#ifndef ACTIVATIONRECORD_H
#define ACTIVATIONRECORD_H

#include "ast.h"
#include "variablerecord.h"
#include <QVariant>


class ActivationRecord
{
public:
    ActivationRecord(int returnType);
    bool AssignVariable(string name, QVariant value);
    bool DeclareVariable(string name, int type);
    QVariant GetVariableValue(string name);
    void SetReturnValue(QVariant value);
    QVariant GetReturnValue();
    void SetReturnType(int type);

private:
    int _returnType;
    map<string, VariableRecord> _variables;
    QVariant _returnValue;
};

#endif // ACTIVATIONRECORD_H
