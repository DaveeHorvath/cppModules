#ifndef ICE_HPP
#define ICE_HPP
#include "AMateria.hpp"
#include <string>
class Ice : public AMateria{
	protected:
		const std::string type;
	public:
		Ice();
		~Ice() = default;
		Ice(const Ice& copy);
		Ice& operator=(const Ice& copy);

		AMateria* clone() const override;
		void use(ICharacter& target) override;
};

#endif
