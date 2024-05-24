#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal()
{
	type = "";
	std::cout << "WrongAnimal default constructor called\n";
}


WrongAnimal::WrongAnimal(WrongAnimal& a)
{
	type = a.type;
	std::cout << "WrongAnimal copy constructor called\n";
}

WrongAnimal& WrongAnimal::operator=(WrongAnimal& a)
{
	type = a.type;
	return *this;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called\n";
}

void WrongAnimal::makeSound() const
{
	std::cout << "Wrong Weird animal noises\n";
}

std::string WrongAnimal::getType() const
{
	return type;
}	
