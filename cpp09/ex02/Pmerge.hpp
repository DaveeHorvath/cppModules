#ifndef PMERGE_HPP
#define PMERGE_HPP

#include <algorithm>
#include <string>
#include <iostream>
#include <chrono>
template <template <class T, class Allocator = std::allocator<T>> class Container>
class Pmerge{
private:

    //template <template <typename> class Cont>
    Container<int> sortList(Container<int> list)
    {
        Container<std::pair<int, int>> smaller{};
        Container<int> bigger{};

        if (list.size() == 1)
            return list;
        if (list.size() % 2 == 1)
        {
            smaller.push_back(std::make_pair(list.back(), 2147483647));
            list.pop_back();
        }

        for (auto it = list.begin(); it != list.end(); it++)
        {
            int cur = *it;
            int next = *(++it);
            if (next > cur)
            {
                smaller.push_back(std::make_pair(cur, next));
                bigger.push_back(next);
            }
            else
            {
                smaller.push_back(std::make_pair(next, cur));
                bigger.push_back(cur);
            }
        }
        bigger = sortList(bigger);
        return merge(smaller, bigger);
    }

    void debug_print(Container<std::pair<int, int>> smaller, Container<int> bigger)
    {
        /*
            debug print
        */
        std::cout << "<================================>\n";
        std::cout << "Smaller: ";
        for (auto s : smaller)
        {
            std::cout << s.first << " " << s.second << ", ";
        }
        std::cout << "\n";
        std::cout << "Bigger: ";
        for (auto s : bigger)
        {
            std::cout << s << ", ";
        }
        std::cout << "\n";
    }

    /*
        this is the closest im willing to get to O(log n), the current algos O complexity:

    */
    Container<int> merge(Container<std::pair<int, int>> smaller, Container<int> bigger)
    {
        //debug_print(smaller, bigger);
        for (auto start = bigger.begin(); start != bigger.end(); start++)
        {
            auto smal = std::find_if(smaller.begin(), smaller.end(), [&](std::pair<int, int> x){return x.second == *start; });
            if (smal != smaller.end())
            {
                auto pos = std::lower_bound(bigger.begin(), start, smal->first);
                bigger.insert(pos, smal->first);
                smaller.erase(smal);
            }
        }
        if (smaller.size() > 0)
        {
            auto pos = std::lower_bound(bigger.begin(), bigger.end(), smaller.begin()->first);
            bigger.insert(pos, smaller.begin()->first);
            smaller.erase(smaller.begin());
        }
        if (smaller.size() != 0)
            throw std::runtime_error("Failed algorithm");
        return (bigger);
    }
public:
    Pmerge(std::string s)
    {
        Container<int> cont{};
        std::stringstream ss {s};
        for (std::string l; std::getline(ss, l, ' ');)
        {
            int i = std::stoi(l);
            if (std::find_if(cont.begin(), cont.end(), [&](int x){return x == i;}) != cont.end())
                throw std::runtime_error("Elements arent unique");
            cont.push_back(i);
        }
        std::cout << "Before: ";
        for (auto& a : cont)
            std::cout << a << " ";
        std::cout << "\n";
        auto start = std::chrono::high_resolution_clock::now();
        cont = sortList(cont);
        auto end = std::chrono::high_resolution_clock::now();
        double dur = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
        std::cout << "After: ";
        for (auto& a : cont)
            std::cout << a << " ";
        std::cout << "\n";
        std::cout << dur << "us for " << cont.size() << " elements\n";
    }
    Pmerge() = delete;      
    ~Pmerge() = default;
    Pmerge(const Pmerge& other) = delete;
    Pmerge& operator=(const Pmerge& other) = delete;
};

#endif