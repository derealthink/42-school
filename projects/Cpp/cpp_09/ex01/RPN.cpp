#include "RPN.hpp"

Notation::Notation() {}

Notation::Notation(const Notation &other) : n(other.n) {}

Notation &Notation::operator=(const Notation &other)
{
    if (this != &other)
        n = other.n;
    return *this;
}

Notation::~Notation() {}

void Notation::calculate(const std::string &expression)
{
    std::stringstream ss(expression);
    std::string token;

    while (ss >> token)
    {
        // --- NUMBER ---
        if (token.size() == 1 && std::isdigit(token[0]))
        {
            n.push(token[0] - '0');
            continue;
        }

        // --- OPERATOR ---
        if (token == "+" || token == "-" || token == "*" || token == "/")
        {
            if (n.size() < 2)
            {
                std::cerr << "Error: not enough operands" << std::endl;
                return;
            }

            int b = n.top(); n.pop();
            int a = n.top(); n.pop();
            int result;

            if (token == "+") result = a + b;
            else if (token == "-") result = a - b;
            else if (token == "*") result = a * b;
            else
            {
                if (b == 0)
                {
                    std::cerr << "Error: division by zero" << std::endl;
                    return;
                }
                result = a / b;
            }
            n.push(result);
            continue;
        }

        // --- UNKNOWN TOKEN ---
        std::cerr << "Error: invalid token => " << token << std::endl;
        return;
    }

    // --- FINAL CHECK ---
    if (n.size() != 1)
    {
        std::cerr << "Error: invalid expression" << std::endl;
        return;
    }

    std::cout << n.top() << std::endl;
}