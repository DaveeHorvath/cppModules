#ifndef AMATERIA_HPP
#define AMATERIA_HPP
#include "ICharacter.hpp"
#include <string>
class AMateria {
	protected:
		const std::string type;
	public:
		AMateria() = delete;
		AMateria(const std::string _type);
		virtual ~AMateria() = default;
		AMateria(const AMateria& copy);
		AMateria& operator=(const AMateria& copy) = delete;
		std::string const& getType() const;

		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif
