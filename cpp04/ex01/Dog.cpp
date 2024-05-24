#include "Dog.hpp"
#include <iostream>

Dog::Dog() : Animal()
{
	type = "Dog";
	brain = new Brain();
	std::cout << "Dog default constructor called\n";
}


Dog::Dog(Dog& d)
{
	type = d.type;
	brain = new Brain(*d.brain);
	std::cout << "Dog copy constructor called\n";
}

Dog& Dog::operator=(Dog& d)
{
	if (this == &d)
	{
		if (brain)
			delete brain;
		type = d.type;
		brain = new Brain(*d.brain);
	}
	return *this;
}

Dog::~Dog()
{
	delete brain;
	std::cout << "Dog destructor called\n";
}

void Dog::makeSound() const
{
	std::cout << "Wuff\n";
}
void Dog::setIdea(int i, std::string s)
{
	brain->setIdea(i, s);
}

std::string Dog::getIdea(int i)
{
	return (brain->getIdea(i));
}
