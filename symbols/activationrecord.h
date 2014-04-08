#ifndef ACTIVATIONRECORD_H
#define ACTIVATIONRECORD_H

#include "ast.h"
#include "variablerecord.h"
#include <QVariant>
#include <QString>
#include <map>

class ActivationRecord
{
public:
    ActivationRecord();
    void AssignVariable(QString name, QVariant value);
    void DeclareVariable(QString name);
    QVariant GetVariableValue(QString name);
    void SetReturnValue(QVariant value);
    QVariant GetReturnValue();

private:
    std::map<QString, QVariant> _variables;
    QVariant _returnValue;
};

#endif // ACTIVATIONRECORD_H
