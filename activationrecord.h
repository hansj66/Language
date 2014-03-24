#ifndef ACTIVATIONRECORD_H
#define ACTIVATIONRECORD_H

#include "ast.h"
#include <QVariant>

typedef struct
{
    QVariant value;
    Language::Parser::token::yytokentype type;
} VariableRecord;


class ActivationRecord
{
public:
    ActivationRecord();
    bool AssignVariable(string name, QVariant value);
    bool DeclareVariable(string name, Language::Parser::token::yytokentype type);
    QVariant GetVariableValue(string name);
    void SetReturnValue(QVariant value);
    QVariant GetReturnValue();

private:
    Language::Parser::token::yytokentype returnType;
    map<string, VariableRecord> _variables;
    QVariant _returnValue;
};

#endif // ACTIVATIONRECORD_H
