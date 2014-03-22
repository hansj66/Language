#include "activationrecord.h"

ActivationRecord::ActivationRecord()
{
}


bool ActivationRecord::DefineVariable(string name, QVariant value)
{
    VariableRecord r;
    r.type = Language::Parser::token::TextType;
    r.value = value;
    // TODO: Check for existence
    _variables[name] = r;
    return true;
}




