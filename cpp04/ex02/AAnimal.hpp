#ifndef AANIMAL_HPP
#define AANIMAL_HPP
#include <string>
class AAnimal
{
	protected:
		std::string type;
	public:
		AAnimal();
		virtual ~AAnimal();
		AAnimal(AAnimal& a);
		AAnimal& operator=(AAnimal&a);
		virtual void makeSound() const;
		std::string getType() const;
};

#endif
