#include "Rpn.hpp"
#include <sstream>
#include <iostream>
Rpn::Rpn(std::string s)
{
    stck = std::stack<char>();
    std::stringstream cont{s};
    for (std::string l; std::getline(cont, l, ' ');)
    {
        if (l.length() > 1)
            throw std::runtime_error("invalid input format");
        stck.push(l[0]);
    }
    int res = get();
    if (!stck.empty())
        throw std::runtime_error("invalid input, cant resolve all operations");
    else
        std::cout << res;
}

int Rpn::get()
{
    if (stck.empty())
        throw std::runtime_error("invalid input, cant resolve operations");
    char tp = stck.top();
    stck.pop();
    int t;
    switch (tp)
    {
    case '+':
        return (get() + get());
        break;
    case '*':
        return (get() * get());
        break;
    case '-':
        t = get();
        return (get() - t);
        break;
    case '/':
    {
        t = get();
        if (t == 0)
            throw std::runtime_error("div 0 error");
        return (get() / t);
        break;
    }
    default:
    {
        if (isdigit(tp))
            return (tp - '0');
        else 
            throw std::runtime_error("invalid char");
        break;
    }
    }
}