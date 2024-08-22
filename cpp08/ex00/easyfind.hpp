#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <exception>

template<typename T>
typename T::iterator easyfind(T container, int val) { 
    typename T::iterator it = std::find(container.begin(), container.end(), val);
    if (it == container.end())
        throw std::runtime_error("Value isnt in container");
    return it;
}

#endif