#include "MutantStack.hpp"
#include <iostream>

int main()
{
    std::cout << "> original operations\n"; 
    MutantStack<int> m;
    m.push(42);
    m.push(69);
    std::cout << "top value: " << m.top() << "\n";
    m.pop();
    std::cout << "top value: " << m.top() << "\n";
    std::cout << "size:" << m.size() << "\n";

    MutantStack<int>::iterator it = m.begin();
    ++it;
    --it;
    std::cout << "> iteratebality and required operations\n";
    MutantStack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    MutantStack<int> a(s);
    MutantStack<int> b;
    b = s;

    std::cout << "original mutant stack\n";
    for (MutantStack<int>::iterator i = s.begin(); i != s.end(); i++)
        std::cout << *i << "\n";
    
    std::cout << "copy constructor mutant stack\n";
    for (MutantStack<int>::iterator i = a.begin(); i != a.end(); i++)
        std::cout << *i << "\n";
    
    std::cout << "copy assignment operator mutant stack\n";
    for (MutantStack<int>::iterator i = b.begin(); i != b.end(); i++)
        std::cout << *i << "\n";

    std::cout << "> const iterators\n";
    const MutantStack<int> const_stack(s);

    for (MutantStack<int>::const_iterator i = const_stack.begin(); i != const_stack.end(); i++)
        std::cout << *i << "\n";

}