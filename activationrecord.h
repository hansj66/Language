#ifndef ACTIVATIONRECORD_H
#define ACTIVATIONRECORD_H

#include "ast.h"
#include "variablerecord.h"
#include <QVariant>
#include <QString>


class ActivationRecord
{
public:
    ActivationRecord(int returnType);
    bool AssignVariable(QString name, QVariant value);
    bool DeclareVariable(QString name, int type);
    QVariant GetVariableValue(QString name);
    void SetReturnValue(QVariant value);
    QVariant GetReturnValue();
    void SetReturnType(int type);

private:
    int _returnType;
    map<QString, VariableRecord> _variables;
    QVariant _returnValue;
};

#endif // ACTIVATIONRECORD_H
