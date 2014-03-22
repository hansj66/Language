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
    bool DefineVariable(string name, QVariant value);

private:
    Language::Parser::token::yytokentype returnType;
    map<string, VariableRecord> _variables;
};

#endif // ACTIVATIONRECORD_H
