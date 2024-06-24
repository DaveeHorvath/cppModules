#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>


template<typename T>
typename T::iterator easyfind(T container, int val) { 
    return std::find(container.begin(), container.end(), val);
}

#endif