#include "Cat.hpp"
#include "Dog.hpp"
#include "AAnimal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

void mandatory()
{
	const AAnimal* meta = new AAnimal();
	const AAnimal* j = new Dog();
	const AAnimal* i = new Cat();
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
		AAnimal a;
		AAnimal b(a);
		AAnimal c;
		c = a;
		std::cout << a.getType() << "\n";
		a.makeSound();
	}
	std::cout << " -  AAnimal test complete - \n";
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

void mandatorybrain()
{
	const AAnimal* j = new Dog();
	const AAnimal* i = new Cat();
	delete j;//should not create a leak
	delete i;

	AAnimal* animals[100];
	for (int i = 0; i < 50; i++) {
		animals[i] = new Cat();
	}
	for (int i = 50; i < 100; i++) {
		animals[i] = new Dog();
	}
	for (int i = 0; i < 100; i++) {
		std::cout << animals[i]->getType() << "\n";
	}
	for (int i = 0; i < 100; i++) {
		delete animals[i];
	}
}

void ownbraintest()
{
	Cat a;
	a.setIdea(0, "funny idea");
	Cat b(a);
	std::cout << b.getIdea(0);
	Cat c;
	c = a;
	std::cout << c.getIdea(0);
}

int main( void )
{
	mandatory();
	std::cout << "== mandatory complete ==\n";
	wrongtest();
	std::cout << "== wrong test complete ==\n";
	owntest();
	std::cout << "== own tests complete ==\n";
	mandatorybrain();
	std::cout << "== mandatory brain test complete ==\n";
	ownbraintest();
	std::cout << "== own brain test complete ==\n";
	return 0;
}

