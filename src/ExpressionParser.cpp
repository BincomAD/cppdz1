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

std::unique_ptr<ICalculatable> ExpressionParser::Parse()
{
    // –екурсивно строим древовидную структуру из наследников ICalculatable
    return ParseExpression();
}

std::unique_ptr<ICalculatable> ExpressionParser::ParseExpression()
{
    std::unique_ptr<ICalculatable> leftOperand = ParseTerm();

    while (_currentTokenIndex < _tokens.size())
    {
        std::string& op = _tokens[_currentTokenIndex];

        if (op == "+")
        {
            _currentTokenIndex++;
            std::unique_ptr<ICalculatable> rightOperand = ParseTerm();
            leftOperand = std::make_unique<Addition>(std::move(leftOperand), std::move(rightOperand));
        }
        else if (op == "-")
        {
            _currentTokenIndex++;
            std::unique_ptr<ICalculatable> rightOperand = ParseTerm();
            leftOperand = std::make_unique<Subtraction>(std::move(leftOperand), std::move(rightOperand));
        }
        else
        {
            break;
        }
    }

    return leftOperand;
}

std::unique_ptr<ICalculatable> ExpressionParser::ParseTerm()
{
    std::unique_ptr<ICalculatable> leftOperand = ParseFactor();

    while (_currentTokenIndex < _tokens.size())
    {
        std::string& op = _tokens[_currentTokenIndex];

        if (op == "*")
        {
            _currentTokenIndex++;
            std::unique_ptr<ICalculatable> rightOperand = ParseFactor();
            leftOperand = std::make_unique<Multiplication>(std::move(leftOperand), std::move(rightOperand));
        }
        else if (op == "sqrt")
        {
       	    _currentTokenIndex++;
            std::unique_ptr<ICalculatable> operand = ParseFactor();
            leftOperand = std::make_unique<Square>(std::move(operand));
        }
        else if (op == "ceil")
        {
            std::unique_ptr<ICalculatable> operand = ParseFactor();
            leftOperand = std::make_unique<Ceil>(std::move(operand));
        }
        else
        {
            break;
        }
    }

    return leftOperand;
}

std::unique_ptr<ICalculatable> ExpressionParser::ParseFactor()
{
    std::string& token = _tokens[_currentTokenIndex];

    if (token == "(")
    {
        _currentTokenIndex++;
        std::unique_ptr<ICalculatable> expr = ParseExpression();
        if (_tokens[_currentTokenIndex] != ")")
        {
            throw std::runtime_error("Invalid expression: expected ')' but found " + _tokens[_currentTokenIndex]);
        }
        _currentTokenIndex++;
        return std::make_unique<Bracket>(std::move(expr));
    }
    else if (token == "sqrt")
    {
        _currentTokenIndex++;
        std::unique_ptr<ICalculatable> operand = ParseFactor();
        return std::make_unique<Square>(std::move(operand));
    }
    else if (token == "ceil")
    {
        _currentTokenIndex++;
        std::unique_ptr<ICalculatable> operand = ParseFactor();
        return std::make_unique<Ceil>(std::move(operand));
    }
    else
    {
        double value = std::stod(_tokens[_currentTokenIndex]);
        _currentTokenIndex++;
        return std::make_unique<Number>(std::move(value));
    }
}
