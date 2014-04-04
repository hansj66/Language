#-------------------------------------------------
#
# Project created by QtCreator 2014-03-04T20:37:33
#
#-------------------------------------------------

QT       += core

CONFIG += console
CONFIG -= app_bundle

TARGET = language
TEMPLATE = app

QMAKE_CXXFLAGS += -std=c++11

INCLUDEPATH += ./ast ./grammar ./symbols

DEFINES += YYDEBUG\
                    YYERROR_VERBOSE

SOURCES += main.cpp\
        translator.cpp \
    ast/astnode.cpp \
    ast/numberliteralnode.cpp \
    ast/stringliteralnode.cpp \
    ast/identifiernode.cpp \
    ast/parameternode.cpp \
    ast/parameterlistnode.cpp \
    ast/expressionlistnode.cpp \
    ast/operatornode.cpp \
    ast/assignmentnode.cpp \
    ast/functioncallnode.cpp \
    ast/printnode.cpp \
    ast/statementlistnode.cpp \
    ast/whilenode.cpp \
    ast/returnnode.cpp \
    ast/ifnode.cpp \
    ast/functionnode.cpp \
    ast/functiondeclarationlistnode.cpp \
    grammar/parser.tab.cpp \
    grammar/lexer.y.cpp \
    Symbols/activationrecord.cpp \
    Symbols/symboltable.cpp

HEADERS  += \
    translator.hpp \
    errors.h \
    ast/astnode.h \
    ast/numberliteralnode.h \
    ast/stringliteralnode.h \
    ast/identifiernode.h \
    ast/parameternode.h \
    ast/parameterlistnode.h \
    ast/expressionlistnode.h \
    ast/operatornode.h \
    ast/assignmentnode.h \
    ast/functioncallnode.h \
    ast/printnode.h \
    ast/statementlistnode.h \
    ast/whilenode.h \
    ast/returnnode.h \
    ast/ifnode.h \
    ast/functionnode.h \
    ast/functiondeclarationlistnode.h \
    ast/ast.h \
    grammar/parser.tab.hpp \
    grammar/stack.hh \
    grammar/lexer.hpp \
    Symbols/activationrecord.h \
    Symbols/symboltable.h \
    Symbols/variablerecord.h

OTHER_FILES += \
    Links.txt \
    Todo.txt \
    grammar/lexer.l \
    grammar/parser.y \
    examples/syntaxtests.scripture \
    examples/test.scripture \
    examples/test2.scripture

