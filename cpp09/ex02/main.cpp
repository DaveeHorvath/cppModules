#include "Pmerge.hpp"
#include <list>
#include <vector>
#include <iostream>
int main()
{
    std::string s = "1 5 2 3 4";
    std::cout << "List: ";
    Pmerge<std::list> l{s};
    std::cout << "Vector: ";
    Pmerge<std::vector> v{s};
}