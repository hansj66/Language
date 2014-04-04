#include "activationrecord.h"

ActivationRecord::ActivationRecord()
{
}


void ActivationRecord::AssignVariable(QString name, QVariant value)
{
    _variables[name] = value;
}


void ActivationRecord::DeclareVariable(QString name)
{
    _variables[name] = QVariant();
}


QVariant ActivationRecord::GetVariableValue(QString name)
{
    return _variables[name];
}

void ActivationRecord::SetReturnValue(QVariant value)
{
    _returnValue = value;
}

QVariant ActivationRecord::GetReturnValue()
{
    return _returnValue;
}






