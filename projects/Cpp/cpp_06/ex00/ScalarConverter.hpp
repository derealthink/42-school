#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <cctype>
#include <string>
#include <iostream>
#include <cmath>
#include <limits>
#include <cstdlib>
#include <iomanip>


class ScalarConverter
{
    private: 
    
        ScalarConverter();
        ScalarConverter(const ScalarConverter &copy);
        ScalarConverter &operator=(const ScalarConverter &copy);
        ~ScalarConverter();

        static bool isInteger(const std::string &rep);
        static bool isChar(const std::string &rep);
        static bool isFloat(const std::string &rep);
        static bool isDouble(const std::string &rep);
        static bool isInfinite(const std::string &rep);

        static void convertToNumber(long double number);
        static void convertFromChar(const std::string &rep);
        static void convertToChar(const char &c);
        static void convertFromInfinite(const std::string &rep);
    public:
        static void convert(const std::string &rep);
};





#endif 