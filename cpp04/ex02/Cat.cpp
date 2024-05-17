#include "Cat.hpp"
#include <iostream>
Cat::Cat() : AAnimal()
{
	type = "Cat";
	brain = new Brain();
	std::cout << "Cat default constructor called\n";
}


Cat::Cat(Cat& c)
{
	type = c.type;
	brain = new Brain(*c.brain);
	std::cout << "Cat copy constructor called\n";
}

Cat& Cat::operator=(Cat& c)
{
	if (this == &c)
	{
		if (brain)
			delete brain;
		type = c.type;
		brain = new Brain(*c.brain);
	}
	return *this;
}

Cat::~Cat()
{
	delete brain;
	std::cout << "Cat destructor called\n";
}

void Cat::makeSound() const
{
	std::cout << "Meow\n";
}

void Cat::setIdea(int i, std::string s)
{
	brain->setIdea(i, s);
}

std::string Cat::getIdea(int i)
{
	return (brain->getIdea(i));
}
