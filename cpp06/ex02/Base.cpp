#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>

#include <cstdlib>
#include <ctime>

Base::~Base(){}

Base* Base::generate()
{
    static bool _; 

    if (!_)
    {
        std::srand(std::time(nullptr));
        _ = true;
    }
    int randval = std::rand();
    if (randval % 3 == 0)
        return new A();
    else if (randval % 3 == 1)
        return new B();
    else
        return new C();
}

void Base::identify(Base *p)
{
    A* a = dynamic_cast<A *>(p);
    if (a)
        std::cout << "A" << std::endl;
    B* b = dynamic_cast<B *>(p);
    if (b)
        std::cout << "B" << std::endl;
    C* c = dynamic_cast<C *>(p);
    if (c)
        std::cout << "C" << std::endl;
}

void Base::identify(Base &p)
{
    try{
        [[maybe_unused]]
        A& a = dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
    }
    catch (...)
    {}
    try{
        [[maybe_unused]]
        B& b = dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
    }
    catch (...)
    {}
    try{
        [[maybe_unused]]
        C& c = dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
    }
    catch (...)
    {}
}