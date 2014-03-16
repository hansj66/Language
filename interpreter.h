#ifndef INTERPRETER_H
#define INTERPRETER_H

#include "ast.h"

class Interpreter
{
public:
    Interpreter();

    static int Execute(Language::ASTNode * node);
};

#endif // INTERPRETER_H
