#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>
class Rpn  {
    private:
        std::stack<char> stck;
    public:
        Rpn() = delete;
        Rpn(std::string s);
        ~Rpn() = default;
        Rpn(const Rpn& other) = delete;
        Rpn& operator=(const Rpn& other) = delete;
        int get();
};

#endif