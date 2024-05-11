#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include <string>
class Animal
{
	protected:
		std::string type;
	public:
		Animal();
		virtual ~Animal();
		Animal(Animal& a);
		Animal& operator=(Animal&a);
		virtual void makeSound() const;
		std::string getType() const;
		void setIdea(int i, std::string s);
		std::string& getIdea(int i);
};

#endif
