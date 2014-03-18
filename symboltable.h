#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H

#include "ast.h"
#include <string>
#include <map>

using namespace std;
using namespace Language;

typedef struct
{
    int iVal;
    int dVal;
    string sVal;
    string type;
} VariableRecord;

typedef struct
{
    ASTNode * function;
    string returnType;
} FunctionRecord;

class SymbolTable
{
private:
    SymbolTable();
    static SymbolTable * _instance;
    map<string, VariableRecord> _variables;
    map<string, FunctionRecord> _functions;
    ASTNode * _entrypoint;

public:
    static SymbolTable * Instance();

    bool DefineVariable(string name);
    void StartAR();
    void EndAR();
   /*
    bool SetValue(string name, string value);
    bool SetValue(string name, double value);
    bool SetValue(string name, int value);
   */
};

#endif // SYMBOLTABLE_H
