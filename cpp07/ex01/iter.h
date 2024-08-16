#ifndef ITER_H
#define ITER_H

#include <iostream>

template<typename T, typename F>
void iter(T* array, int len, F f){
    for (int i = 0; i < len; i++)
        f(array[i]);
};

// template<typename T>
// concept incrementable = requires(T x) {x++;};

// template<typename T>
// concept printable = requires(T x) {std::cout << x;};

template<typename T>
void f1(T& t){
    t++;
}

template<typename T>
void f2(T& t){
    std::cout << t;
}

#endif