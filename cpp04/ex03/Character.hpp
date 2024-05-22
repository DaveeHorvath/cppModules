#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include "ICharacter.hpp"
class Character : public ICharacter
{
	private:
		const std::string name;
	public:
		Character();
		Character(const Character &copy);
		Character &operator=(const Character &copy);
		~Character();

		std::string const & getName() const override;
		void equip(AMateria* m) override;
		void unequip(int idx) override;
		void use(int idx, ICharacter& target) override;
};

#endif
