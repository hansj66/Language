#-------------------------------------------------
#
# Project created by QtCreator 2014-03-04T20:37:33
#
#-------------------------------------------------

QT       += core opengl

CONFIG += console
CONFIG -= app_bundle

TARGET = language
TEMPLATE = app

DEFINES += YYERROR_VERBOSE

QMAKE_CXXFLAGS += -std=c++11

SOURCES += main.cpp\
        lexer.yy.cpp \
        parser.tab.cpp \
        translator.cpp \
    symboltable.cpp \
    ast.cpp \
    interpreter.cpp

HEADERS  += \
    parser.tab.hpp \
    stack.hh \
    translator.hpp \
    scanner.hpp \
    symboltable.h \
    ast.h \
    interpreter.h

OTHER_FILES += \
    lexer.l \
    parser.yy \
    Links.txt \
    parser.yy
