#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP
#include <string>

class WrongAnimal
{
	protected:
		std::string type;
	public:
		WrongAnimal();
		virtual ~WrongAnimal();
		WrongAnimal(WrongAnimal& a);
		WrongAnimal& operator=(WrongAnimal&a);
		virtual void makeSound() const;
		std::string getType() const;
};

#endif
