#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"
#include <iostream>

int main()
{
    Base base; 
    Base *ptr;
    for (int i = 0; i < 10; i++)
    {
        std::cout << "#" << i << std::endl;
        ptr = base.generate();
        std::cout << "by ptr ";
        base.identify(ptr);
        std::cout << "by ref ";
        base.identify(*ptr);
    }
}