#include "Pmerge.hpp"
#include <list>
#include <iostream>
#include <deque>
int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Usage: ./Pmerge \"list of numbers\"\n";
        return 1;
    }
    std::string s{argv[1]};
    try{
        std::cout << "List: \n";
        Pmerge<std::list> l{s};
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << "\n";
    }

    try{
        std::cout << "Deque: \n";
        Pmerge<std::deque> v{s};
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << "\n";
    }
}