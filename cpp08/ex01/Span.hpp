#ifndef SPAN_HPP
#define SPAN_HPP

#include <list>
#include <exception>
#include <algorithm>
#include <iostream>

class Span{
    private:
        unsigned int size;
        long min;
        std::list<int> numbers;
    public:
        Span() = delete;
        Span(unsigned int N);
        Span(const Span& other);
        Span& operator=(const Span& other);
    
    void addNumber(int n);
    int shortestSpan();
    int longestSpan();
    template <typename T>
    void addRange(T begin, T end)
    {
        while (begin != end)
            addNumber(*begin++);
    }

    class SizeReachedException : public std::exception {
        const char* what() const noexcept;
    };
    class NoSpanFoundException : public std::exception {
        const char* what() const noexcept;
    };
};

#endif