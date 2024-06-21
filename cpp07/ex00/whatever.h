#ifndef WHATEVER_H
#define WHATEVER_H

#include <iostream>

template<typename T>
concept swapable = requires(T x, T y) {x = y;};

template<typename T>
concept comparable = requires(T x, T y) {x < y; x > y;};

template<typename T> requires swapable<T>
void swap(T &a, T &b) {
    T tmp = a;
    a = b;
    b = tmp;
};

template<typename T> requires comparable<T>
T min(T a, T b)
{
    if (a < b)
        return a;
    return b;
}

template<typename T> requires comparable<T>
T max(T a, T b)
{
    if (a > b)
        return a;
    return b;
}

#endif