#include "activationrecord.h"

ActivationRecord::ActivationRecord()
{
}


bool ActivationRecord::AssignVariable(string name, QVariant value)
{
    // TODO: Check for existence
    _variables[name].value = value;
    return true;
}


bool ActivationRecord::DeclareVariable(string name, Language::Parser::token::yytokentype type)
{
    VariableRecord r;
    r.type = type;
    r.value = QVariant();
    // TODO: Check for existence
    _variables[name] = r;
    return true;
}


QVariant ActivationRecord::GetVariableValue(string name)
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





