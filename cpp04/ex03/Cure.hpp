#ifndef CURE_HPP
#define CURE_HPP
#include "AMateria.hpp"
#include <string>
class Cure : public AMateria{
	protected:
		const std::string type;
	public:
		Cure();
		~Cure() = default;
		Cure(const Cure& copy);
		Cure& operator=(const Cure& copy);

		AMateria* clone() const override;
		void use(ICharacter& target) override;
};

#endif
