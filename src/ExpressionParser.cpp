#include "ExpressionParser.h"

ExpressionParser::ExpressionParser(const std::string& expression)
{
    // –азбиваем выражение на токены
    std::istringstream iss(expression);
    std::string token;
    while (iss >> token)
    {
        _tokens.push_back(token);
    }

    _currentTokenIndex = 0;
}

ICalculatable* ExpressionParser::Parse()
{
    // –екурсивно строим древовидную структуру из наследников ICalculatable
    return ParseExpression();
}

ICalculatable* ExpressionParser::ParseExpression()
{
    ICalculatable* leftOperand = ParseTerm();

    while (_currentTokenIndex < _tokens.size())
    {
        std::string& op = _tokens[_currentTokenIndex];

        if (op == "+")
        {
            _currentTokenIndex++;
            ICalculatable* rightOperand = ParseTerm();
            leftOperand = new Addition(leftOperand, rightOperand);
        }
        else if (op == "-")
        {
            _currentTokenIndex++;
            ICalculatable* rightOperand = ParseTerm();
            leftOperand = new Subtraction(leftOperand, rightOperand);
        }
        else
        {
            break;
        }
    }

    return leftOperand;
}

ICalculatable* ExpressionParser::ParseTerm()
{
    ICalculatable* leftOperand = ParseFactor();

    while (_currentTokenIndex < _tokens.size())
    {
        std::string& op = _tokens[_currentTokenIndex];

        if (op == "*")
        {
            _currentTokenIndex++;
            ICalculatable* rightOperand = ParseFactor();
            leftOperand = new Multiplication(leftOperand, rightOperand);
        }
        else if (op == "sqrt")
        {
        	_currentTokenIndex++;
            ICalculatable* operand = ParseFactor();
            leftOperand = new Square(operand);
        }
        else if (op == "ceil")
        {
            ICalculatable* operand = ParseFactor();
            leftOperand = new Ceil(operand);
        }
        else
        {
            break;
        }
    }

    return leftOperand;
}

ICalculatable* ExpressionParser::ParseFactor()
{
    std::string& token = _tokens[_currentTokenIndex];

    if (token == "(")
    {
        _currentTokenIndex++;
        ICalculatable* expr = ParseExpression();
        if (_tokens[_currentTokenIndex] != ")")
        {
            throw std::runtime_error("Invalid expression: expected ')' but found " + _tokens[_currentTokenIndex]);
        }
        _currentTokenIndex++;
        return new Bracket(expr);
    }
    else if (token == "sqrt")
    {
        _currentTokenIndex++;
        ICalculatable* operand = ParseFactor();
        return new Square(operand);
    }
    else if (token == "ceil")
    {
        _currentTokenIndex++;
        ICalculatable* operand = ParseFactor();
        return new Ceil(operand);
    }
    else
    {
        double value = std::stod(_tokens[_currentTokenIndex]);
        _currentTokenIndex++;
        return new Number(value);
    }
}
