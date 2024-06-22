#include "Array.hpp"
#include <iostream>

int main()
{
    std::cout << "<==== basic size and assignment test ====>\n";
    Array<int> a;
    std::cout << "empty constructor size: " << a.size() << "\n";
    Array<int> b{5};
    std::cout << "non empty constructor size: " << b.size() << "\n";
    for (int i = 0; i < 5; i++)
        b[i] = i;
    for (int i = 0; i < 5; i++)
        std::cout << "b[" << i << "]:" << b[i] << " ";
    std::cout << "\n";
    std::cout << "<==== out of bounds exception tests with b[-1] and b[b.size()] ====>\n";
    try {
        b[-1];
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << "\n";
    }

    try {
        b[b.size()];
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << "\n";
    }
    std::cout << "<==== copy testing c copy assignment d being copy constructor ====>\n";
    Array<int> c;
    c = b;
    Array<int> d(b);
    for (int i = 0; i < 5; i++)
        std::cout << "b: " << b[i] << " c: " << c[i] << " d: " << d[i] << "\n";

    std::cout << "<==== const copy constructor and const operator[] test ====>\n";
    const Array<int> e(b);
    for (int i = 0; i < 5; i++)
        std::cout << "b: " << b[i] << " e: " << e[i] << "\n";
    return (0);
}