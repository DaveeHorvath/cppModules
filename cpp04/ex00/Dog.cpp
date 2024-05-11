#include "Dog.hpp"
#include <iostream>

Dog::Dog() : Animal()
{
	type = "Dog";
	std::cout << "Dog default constructor called\n";
}


Dog::Dog(Dog& d)
{
	type = d.type;
	std::cout << "Dog copy constructor called\n";
}

Dog& Dog::operator=(Dog& d)
{
	type = d.type;
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called\n";
}

void Dog::makeSound() const
{
	std::cout << "Wuff\n";
}
