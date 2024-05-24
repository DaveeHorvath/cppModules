#include "Animal.hpp"
#include <iostream>

Animal::Animal()
{
	type = "";
	std::cout << "Animal default constructor called\n";
}


Animal::Animal(Animal& a)
{
	type = a.type;
	std::cout << "Animal copy constructor called\n";
}

Animal& Animal::operator=(Animal& a)
{
	type = a.type;
	return *this;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called\n";
}

void Animal::makeSound() const
{
	std::cout << "Weird animal noises\n";
}

std::string Animal::getType() const
{
	return type;
}

