#include "Cat.hpp"
#include <iostream>

Cat::Cat() : Animal()
{
	type = "Cat";
	std::cout << "Cat default constructor called\n";
}


Cat::Cat(Cat& c)
{
	type = c.type;
	std::cout << "Cat copy constructor called\n";
}

Cat& Cat::operator=(Cat& c)
{
	type = c.type;
	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called\n";
}

void Cat::makeSound() const
{
	std::cout << "Meow\n";
}
