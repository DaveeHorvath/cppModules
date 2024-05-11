#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
class Dog : public Animal
{
	public:
		Dog();
		~Dog();
		Dog(Dog& d);
		Dog& operator=(Dog& d);
		void makeSound() const;
};

#endif
