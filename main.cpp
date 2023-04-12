#include "ExpressionParser.h"
#include <iostream>
#include <string>

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        std::cerr << "Usage: calculator <expression>" << std::endl;
        return 1;
    }

    std::string expression = argv[1];

    try
    {
        ExpressionParser parser(expression);
        ICalculatable* root = parser.Parse();
        double result = root->Calculate();
        std::cout << result << std::endl;
        delete root;
    }
    catch (std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
