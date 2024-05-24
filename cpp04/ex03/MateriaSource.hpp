#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : IMateriaSource
{
    private:
        AMateria* known[4];

    public:
        MateriaSource();
        ~MateriaSource();
        MateriaSource(const MateriaSource& copy);
        MateriaSource& operator=(const MateriaSource& copy);
        void learnMateria(AMateria*) override;
        AMateria* createMateria(std::string const & type) override;  
}

#endif