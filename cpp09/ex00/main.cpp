#include "BitcoinChange.hpp"
#include <iostream>
int main(int argc, char **argv)
{
    try {
        BitcoinChange b{};
        if (argc == 2)
            b.lookupDates(std::string(argv[1]));
        else
            std::cerr << "Usage ./btc infile\n";
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << "\n";
    }
}