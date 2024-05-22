#include "Ice.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>

Ice::Ice() : AMateria("cure"){
	std::cout << "Ice Default constructor\n";
}
Ice::Ice(const Ice& copy) : AMateria(copy){
	std::cout << "Ice Copy constructor\n";
}

Ice& Ice::operator=(const Ice& copy)
{
	return *this;
}

void Ice::use(ICharacter& target)
{
	std::cout << "* heals" << target.getName() << "\'s wounds *\n";
}
