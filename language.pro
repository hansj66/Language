#-------------------------------------------------
#
# Project created by QtCreator 2014-03-04T20:37:33
#
#-------------------------------------------------

QT       += core

CONFIG += console

TARGET = language
TEMPLATE = app

macx {
    CONFIG -= app_bundle
    QMAKE_CXXFLAGS += -std=c++11
    QMAKE_CXXFLAGS += -stdlib=libc++
    QMAKE_CXXFLAGS += -Wno-deprecated-register
    LIBS += -stdlib=libc++
    QMAKE_CXXFLAGS += -mmacosx-version-min=10.8
    QMAKE_LFLAGS += -mmacosx-version-min=10.8
}

win32 {
        QMAKE_CXXFLAGS += /MP
}

INCLUDEPATH += ./ast ./grammar ./symbols $$(BOOSTPATH)

DEFINES += YYDEBUG\
                    YYERROR_VERBOSE

SOURCES += main.cpp\
        translator.cpp \
    ast/astnode.cpp \
    ast/numberliteralnode.cpp \
    ast/stringliteralnode.cpp \
    ast/identifiernode.cpp \
    ast/parameternode.cpp \
    ast/operatornode.cpp \
    ast/assignmentnode.cpp \
    ast/functioncallnode.cpp \
    ast/printnode.cpp \
    ast/whilenode.cpp \
    ast/returnnode.cpp \
    ast/ifnode.cpp \
    ast/functionnode.cpp \
    grammar/parser.tab.cpp \
    grammar/lexer.y.cpp \
    Symbols/activationrecord.cpp \
    Symbols/symboltable.cpp \
    ast/statementlistnode.cpp

HEADERS  += \
    translator.hpp \
    errors.h \
    ast/astnode.h \
    ast/numberliteralnode.h \
    ast/stringliteralnode.h \
    ast/identifiernode.h \
    ast/parameternode.h \
    ast/operatornode.h \
    ast/assignmentnode.h \
    ast/functioncallnode.h \
    ast/printnode.h \
    ast/whilenode.h \
    ast/returnnode.h \
    ast/ifnode.h \
    ast/functionnode.h \
    ast/ast.h \
    grammar/parser.tab.hpp \
    grammar/stack.hh \
    grammar/lexer.hpp \
    Symbols/activationrecord.h \
    Symbols/symboltable.h \
    Symbols/variablerecord.h \
    ast/listnode.h \
    ast/statementlistnode.h

OTHER_FILES += \
    Links.txt \
    Todo.txt \
    grammar/lexer.l \
    grammar/parser.y \
    examples/syntaxtests.scripture \
    examples/test.scripture \
    examples/test2.scripture \
    examples/loop.scripture

