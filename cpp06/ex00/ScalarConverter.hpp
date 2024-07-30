#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter
{
    public:
        static void convert(std::string str);
        ScalarConverter() = delete;
        ScalarConverter(ScalarConverter const& ref) = delete;
        ScalarConverter& operator=(ScalarConverter const& ref) = delete;
        ~ScalarConverter() = delete;
};

#endif