#include "Span.hpp"
#include <cstdlib>
#include <ctime>
int main(){
    {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }

    unsigned int maxSize = 5;
    Span s{maxSize};
    try 
    {
        for (unsigned int i = 0; i <= maxSize; i++)
            s.addNumber(i);
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << "\n";
    }
    Span b{s};
    Span c{0};
    c = s;

    Span d{10};
    try
    {
        std::cout << d.shortestSpan() << "\n";
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        std::cout << d.longestSpan() << "\n";
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    d.addNumber(1);
    try
    {
        std::cout << d.shortestSpan() << "\n";
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        std::cout << d.longestSpan() << "\n";
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "longest: " << s.longestSpan() << "\n";
    std::cout << "shortest: " << s.shortestSpan() << "\n";

    Span span(10000);
    std::srand(std::time(NULL));
    std::list<int> input(10001);
    std::for_each(input.begin(), input.end(), [](int &n) {n = std::rand();});
    try
    {
        span.addRange(input.begin(), input.end());
    }
    catch (const std::exception& e)
    {    
        std::cerr << e.what() << "\n";
    }
    std::cout << "longest: " << span.longestSpan() << "\n";
    std::cout << "shortest: " << span.shortestSpan() << "\n";

    return 0;
}