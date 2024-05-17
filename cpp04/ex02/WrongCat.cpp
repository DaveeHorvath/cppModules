#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat() : WrongAnimal()
{
	type = "WrongCat";
	std::cout << "WrongCat default constructor called\n";
}


WrongCat::WrongCat(WrongCat& c)
{
	type = c.type;
	std::cout << "WrongCat copy constructor called\n";
}

WrongCat& WrongCat::operator=(WrongCat& c)
{
	type = c.type;
	return *this;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called\n";
}

void WrongCat::makeSound() const
{
	std::cout << "Somehow wrong meow\n";
}
