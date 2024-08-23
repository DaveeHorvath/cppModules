#include "Rpn.hpp"
#include <iostream>
int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Usage: ./rpn \"valid reverse polish notation\"\n";
        return 1;
    }
    try {
        Rpn r{std::string(argv[1])};
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << "\n";
    }
}