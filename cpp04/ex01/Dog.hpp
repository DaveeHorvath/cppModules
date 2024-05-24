#ifndef DOG_HPP
#define DOG_HPP

#include "Brain.hpp"
#include "Animal.hpp"
class Dog : public Animal
{
	private:
		Brain* brain;
	public:
		Dog();
		~Dog();
		Dog(Dog& d);
		Dog& operator=(Dog& d);
		void makeSound() const;
		void setIdea(int i, std::string s);
		std::string getIdea(int i);
};

#endif
