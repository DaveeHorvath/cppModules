#include "Brain.hpp"
#include <iostream>
Brain::Brain()
{
	std::cout << "Brain has been created\n";
}

Brain::~Brain()
{
	std::cout << "Brain has been created\n";	
}

Brain::Brain(Brain& b)
{
	for (int i = 0; i < 100; i++)
		ideas[i] = b.ideas[i];
}

Brain& Brain::operator=(Brain& b)
{	
	if (this == &b)
		return *this;
	for (int i = 0; i < 100; i++)
		ideas[i] = b.ideas[i];
	return *this;
}

void Brain::setIdea(int i, std::string s)
{
	if (i >= 0 && i < 100)
		ideas[i] = s;
}
std::string Brain::getIdea(int i)
{
	if (i >= 0 && i < 100)
		return ideas[i];
	else
	{
		std::cout << "We dont have this many ideas, so here is the first one\n";
		return ideas[0];
	}
}
