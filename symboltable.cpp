#include "symboltable.h"



SymbolTable * SymbolTable::_instance = nullptr;

SymbolTable::SymbolTable()
{
}

SymbolTable * SymbolTable::Instance()
{
    if (!_instance)
        _instance = new SymbolTable();
    return _instance;
}


void SymbolTable::StartAR()
{
}

void SymbolTable::EndAR()
{
}

