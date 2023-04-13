#pragma once

#include "ICalculatable.h"
#include "Number.h"
#include "Addition.h"
#include "Subtraction.h"
#include "Multiplication.h"
#include "Square.h"
#include "Ceil.h"
#include "Bracket.h"
#include <vector>
#include <string>
#include <sstream>
#include <iostream>

class ExpressionParser
{
private:
    std::vector<std::string> _tokens;
    size_t _currentTokenIndex;

public:
    ExpressionParser(const std::string& expression);
    ICalculatable* Parse();

private:
    ICalculatable* ParseExpression();
    ICalculatable* ParseTerm();
    ICalculatable* ParseFactor();
};
