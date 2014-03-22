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

DEFINES += YYDEBUG\
                    YYERROR_VERBOSE

SOURCES += main.cpp\
        lexer.yy.cpp \
        parser.tab.cpp \
        translator.cpp \
       symboltable.cpp \
       ast.cpp \
       interpreter.cpp \
    activationrecord.cpp

HEADERS  += \
    parser.tab.hpp \
    stack.hh \
    translator.hpp \
    scanner.hpp \
    symboltable.h \
    ast.h \
    interpreter.h \
    activationrecord.h

OTHER_FILES += \
    lexer.l \
    parser.yy \
    Links.txt \
    test.scripture \
    Todo.txt

