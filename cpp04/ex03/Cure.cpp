#include "Cure.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>

Cure::Cure() : AMateria("cure"){
	std::cout << "Cure Default constructor\n";
}
Cure::Cure(const Cure& copy) : AMateria(copy){
	std::cout << "Cure Copy constructor\n";
}

Cure& Cure::operator=(const Cure& copy)
{
	return *this;
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals" << target.getName() << "\'s wounds *\n";
}
