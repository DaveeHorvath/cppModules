#include "Character.hpp"
#include "AMateria.hpp"
#include <iostream>

Character::Character(const std::string _name) : name(_name) {
	std::cout << "Character constructor called\n";	
	dropped = new LinkedList<AMateria *>(nullptr);
	for (int i = 0; i < 4; i++)
		slots[i] = nullptr;
}
Character::Character(const Character& copy){
	std::cout << "Character copy constructor called\n";
	for (int i = 0; i < 4; i++)
		slots[i] = copy.slots[i];
}
Character& Character::operator=(const Character& copy){
	if (&copy == this)
		return *this;
	for (int i = 0; i < 4; i++)
		slots[i] = copy.slots[i];
	return *this;
}

Character::~Character(){
	LinkedList<AMateria *> *tmp;
	while (dropped)
	{
		tmp = dropped;
		if (dropped->getValue() != nullptr)
			delete dropped->getValue();
		delete dropped;
		dropped = tmp->next;
	}
}

std::string const& Character::getName() const {
	return name;
}
void Character::equip(AMateria* m) {	
	for (int i = 0; i < 4; i++)
	{
		if (slots[i] == nullptr)
		{
			slots[i] = m;
		}
	}
}
void Character::unequip(int idx){
	if (0 <= idx && idx < 4)
	{
		dropped->append(slots[idx]);	
		slots[idx] = nullptr;
	}
}
void Character::use(int idx, ICharacter& target) {	
	if (0 <= idx && idx < 4 && slots[idx] != nullptr)
	{
		slots[idx]->use(target);
	}
}
