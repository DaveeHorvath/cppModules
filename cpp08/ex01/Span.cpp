#include "Span.hpp"

Span::Span(unsigned int N) : size(N)
{
    numbers = std::list<int>();
    min = UINT32_MAX;
}

Span::Span(const Span& other)
{
    numbers = other.numbers;
    min = other.min;
    size = other.size;
}

Span& Span::operator=(const Span& other)
{
    if (this != &other)
    {
        numbers = other.numbers;
        min = other.min;
        size = other.size;
    }
    return *this;
}

void Span::addNumber(int n)
{
    if (numbers.size() == size)
        throw SizeReachedException();
    auto i = std::lower_bound(numbers.begin(), numbers.end(), n);
    numbers.insert(i, n);
    int prev = *std::prev(i, 2);
    int next = *i;
    if (numbers.size() > 1 && std::prev(i, 1) != numbers.end() && std::abs(next - n) < min)
        min = std::abs(next - n);
    if (numbers.size() > 1 && std::prev(i, 1) != numbers.begin() && std::abs(prev - n) < min)
        min = std::abs(prev - n);
}

int Span::shortestSpan() {if (numbers.size() < 2) throw NoSpanFoundException(); return min;}
int Span::longestSpan() {if (numbers.size() < 2) throw NoSpanFoundException(); return *std::prev(numbers.end()) - *numbers.begin();}

const char * Span::SizeReachedException::what() const noexcept {return "Size limit reached";}
const char * Span::NoSpanFoundException::what() const noexcept {return "Not enough numbers";}


