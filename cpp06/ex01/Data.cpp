#include "Data.hpp"

Data::Data() {}
Data::~Data() {}

Data::Data(const Data& other) { x = other.x; }

Data& Data::operator=(const Data& other) { x = other.x; return *this; }