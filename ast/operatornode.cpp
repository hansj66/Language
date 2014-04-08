#include <iostream>
#include "operatornode.h"
#include "errors.h"

extern int lineNumber;

namespace Language
{
    OperatorNode::OperatorNode(token::yytokentype type, ASTNode * op1, ASTNode * op2)
        : _op1(op1),
        _op2(op2),
        _operator(type)
    {
        _type = token::NumberType;

        if (nullptr == op2)
            return;
        if ((_op1->Type() == token::TextType) || (_op2->Type() == token::TextType))
        {
           if (_operator == token::ADD)
            {
                 _type = token::TextType;
            }
           else if ((_operator != token::EQ) && (_operator != token::NE))
            {
                std::cout << NO_STRINGS_PLEASE << "(line: " << lineNumber << ")" << std::endl;
                exit(EXIT_FAILURE);
            }
        }
    }

    QVariant OperatorNode::Execute()
    {
        switch(_operator)
        {
            case token::UMINUS: return -_op1->Execute().toDouble(); break;
            case token::ADD: if ((_op1->Type() == token::TextType) ||
                                                                       (_op1->Type() == token::TextType))
                                                                        return QString("%1%2").arg(_op1->Execute().toString()).arg(_op2->Execute().toString());
                                                                    return _op1->Execute().toDouble() + _op2->Execute().toDouble(); break;
            case token::SUB: return _op1->Execute().toDouble() - _op2->Execute().toDouble(); break;
            case token::MUL: return _op1->Execute().toDouble() * _op2->Execute().toDouble(); break;
            case token::DIV: return _op1->Execute().toDouble() / _op2->Execute().toDouble(); break;
            case token::LT: return _op1->Execute().toDouble() < _op2->Execute().toDouble();break;
            case token::GT: return _op1->Execute().toDouble() > _op2->Execute().toDouble();break;
            case token::GE: return _op1->Execute().toDouble() >= _op2->Execute().toDouble();break;
            case token::LE: return _op1->Execute().toDouble() <= _op2->Execute().toDouble();break;
            case token::NE: return _op1->Execute() != _op2->Execute();break;
            case token::EQ: return _op1->Execute() == _op2->Execute();break;
            default: std::cerr << "Damn ! Looks like we forgot to implement something..." << std::endl;
                exit(EXIT_FAILURE);
        }

        return QVariant();
    }
}

