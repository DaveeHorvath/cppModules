#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP
#include <cstdint>

#include "Data.hpp"

class Serializer
{
public:
    Serializer() = delete;
    ~Serializer() = delete;
    Serializer(const Serializer& other) = delete;
    Serializer& operator=(const Serializer& other) = delete;
    static uintptr_t serialize(Data *ptr);
    static Data* deserialize(uintptr_t raw);
};



#endif