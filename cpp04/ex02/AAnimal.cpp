#include "AAnimal.hpp"
#include <iostream>

AAnimal::AAnimal()
{
	type = "";
	std::cout << "AAnimal default constructor called\n";
}


AAnimal::AAnimal(AAnimal& a)
{
	type = a.type;
	std::cout << "AAnimal copy constructor called\n";
}

AAnimal& AAnimal::operator=(AAnimal& a)
{
	type = a.type;
	return *this;
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal destructor called\n";
}

void AAnimal::makeSound() const
{
	std::cout << "Weird animal noises\n";
}

std::string AAnimal::getType() const
{
	return type;
}

