#include "activationrecord.h"

ActivationRecord::ActivationRecord(int returnType)
    :_returnType(returnType)
{
}


bool ActivationRecord::AssignVariable(QString name, QVariant value)
{
    // TODO: Check for existence
    _variables[name].value = value;
    return true;
}


bool ActivationRecord::DeclareVariable(QString name, int type)
{
    VariableRecord r;
    r.type = type;
    r.value = QVariant();
    // TODO: Check for existence
    _variables[name] = r;
    return true;
}


QVariant ActivationRecord::GetVariableValue(QString name)
{
    return _variables[name].value;
}

void ActivationRecord::SetReturnValue(QVariant value)
{
    _returnValue = value;
}

QVariant ActivationRecord::GetReturnValue()
{
    return _returnValue;
}

void ActivationRecord::SetReturnType(int type)
{
    _returnType = type;
}





