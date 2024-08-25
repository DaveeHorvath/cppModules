#ifndef PMERGE_HPP
#define PMERGE_HPP

#include <algorithm>
#include <string>
#include <iostream>
#include <chrono>
template <template <typename> class Container>
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
    //template <template <typename> class Container>
    Container<int> merge(Container<std::pair<int, int>> smaller, Container<int> bigger)
    {
        for (auto& it : smaller)
        {
            auto other = std::find(bigger.begin(), bigger.end(), it.second);
            auto loc = std::lower_bound(bigger.begin(), other, it.first);
            bigger.insert(loc, it.first);
        }
        return (bigger);
    }
public:
    Pmerge(std::string s)
    {
        Container<int> cont{};
        std::stringstream ss {s};
        for (std::string l; std::getline(ss, l, ' ');)
            cont.push_back(std::stoi(l));
        std::cout << cont.size() << "\n";
        auto start = std::chrono::high_resolution_clock::now();
        cont = sortList(cont);
        auto end = std::chrono::high_resolution_clock::now();
        double dur = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
        for (auto& a : cont)
        {
            std::cout << a << " ";
        }
        std::cout << "\n" << dur << "us for " << cont.size() << " elements\n";
    }
    Pmerge() = delete;      
    ~Pmerge() = default;
    Pmerge(const Pmerge& other) = delete;
    Pmerge& operator=(const Pmerge& other) = delete;
};

#endif