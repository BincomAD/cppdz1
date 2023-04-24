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
#include <memory>

class ExpressionParser
{
private:
    std::vector<std::string> _tokens;
    size_t _currentTokenIndex;

public:
    ExpressionParser(const std::string& expression);
    std::unique_ptr<ICalculatable> Parse();

private:
    std::unique_ptr<ICalculatable> ParseExpression();
    std::unique_ptr<ICalculatable> ParseTerm();
    std::unique_ptr<ICalculatable> ParseFactor();
};
