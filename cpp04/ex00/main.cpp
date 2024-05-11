#include "Cat.hpp"
#include "Dog.hpp"
#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

void mandatory()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	delete meta;
	delete i;
	delete j;
}

void wrongtest()
{
	const WrongAnimal* meta = new WrongAnimal();
	const WrongAnimal* i = new WrongCat();
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the wrong cat sound!
	meta->makeSound();
	delete meta;
	delete i;
}

void owntest()
{
	{
		Animal a;
		Animal b(a);
		Animal c;
		c = a;
		std::cout << a.getType() << "\n";
		a.makeSound();
	}
	std::cout << " -  Animal test complete - \n";
	{
		Dog a;
		Dog b(a);
		Dog c;
		c = a;
		std::cout << a.getType() << " " << b.getType() << " " << c.getType() << "\n";
		a.makeSound();
		b.makeSound();
		c.makeSound();
	}
	std::cout << " - Dog test complete - \n";
	{
		Cat a;
		Cat b(a);
		Cat c;
		c = a;
		std::cout << a.getType() << " " << b.getType() << " " << c.getType() << "\n";
		a.makeSound();
		b.makeSound();
		c.makeSound();
	}
	std::cout << " - Cat test complete - \n";
}

int main( void )
{
	mandatory();
	std::cout << "== mandatory complete ==\n";
	wrongtest();
	std::cout << "== wrong test complete ==\n";
	owntest();
	std::cout << "== own tests complete ==\n";
	return 0;
}

