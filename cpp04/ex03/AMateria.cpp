#include "AMateria.hpp"
#include <iostream>
AMateria::AMateria(const std::string _type) : type(_type){
	std::cout << "Constructor called\n";
}
AMateria::AMateria(const AMateria& copy) : type(copy.getType()){
	std::cout << "Copy constructor called\n";
}

std::string const& AMateria::getType() const{
	return type;
}
