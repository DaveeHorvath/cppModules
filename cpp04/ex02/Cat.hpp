#ifndef CAT_HPP
#define CAT_HPP
#include "Brain.hpp"
#include "AAnimal.hpp"
class Cat : public AAnimal
{
	private:
		Brain* brain;
	public:
		Cat();
		~Cat();
		Cat(Cat& c);
		Cat& operator=(Cat& c);
		void makeSound() const;
		void setIdea(int i, std::string s);
		std::string getIdea(int i);
};

#endif
