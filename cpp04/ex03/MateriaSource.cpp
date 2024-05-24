#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    for (int i = 0; i < 4; i++)
		known[i] = nullptr;
}

MateriaSource::~MateriaSource()
{}

MateriaSource::MateriaSource(const MateriaSource& copy)
{
    for (int i = 0; i < 4; i++)
		known[i] = copy.known[i];
}

MateriaSource& operator=(const MateriaSource& copy)
{
    
}