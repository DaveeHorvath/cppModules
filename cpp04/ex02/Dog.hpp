#ifndef DOG_HPP
#define DOG_HPP

#include "Brain.hpp"
#include "AAnimal.hpp"
class Dog : public AAnimal
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
