#include "Serializer.hpp"
#include "Data.hpp"

#include <iostream>

int main()
{
    Data d{};

    std::cout << "address of Data: " << &d << std::endl;
    uintptr_t raw = Serializer::serialize(&d);
    std::cout << "Serialised: " << raw << std::endl;
    Data *ptr = Serializer::deserialize(raw);
    std::cout << "Desirialised: " << ptr << std::endl;
    std::cout << "originalData: " << &d << std::endl;
}