#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

template<class T, class Container=std::deque<T>>
class MutantStack : public std::stack<T, Container>
{
    public:
        typedef std::stack<T, Container> stack;
        typedef typename Container::iterator iterator;
        typedef typename Container::const_iterator const_iterator;
        MutantStack(){};
        ~MutantStack(){};
        MutantStack(const MutantStack& other) : stack(other){};
        MutantStack& operator=(const MutantStack& other) {
            if (this != &other)
                stack::operator=(other);
            return *this;
        }
        iterator begin() { return this->c.begin(); }
        iterator end() { return this->c.end(); }
        const_iterator begin() const { return this->c.begin(); }
        const_iterator end() const { return this->c.end(); }

};

#endif