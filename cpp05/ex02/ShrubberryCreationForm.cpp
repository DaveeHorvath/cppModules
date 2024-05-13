#include "AFrom.hpp"
#include "ShrubberryCreationForm.hpp"
#include <iostream>
ShrubberyCreationForm::ShrubberyCreationForm(std::string _target) : AForm("ShrubberyCreationForm", 147, 137), target(_target) {}

void executeForm(Bureaucrat const& executor) 
{
	std::cout << "writting to file\n";
}
