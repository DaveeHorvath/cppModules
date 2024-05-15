#include "AForm.hpp"
#include "ShrubberryCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
ShrubberyCreationForm::ShrubberyCreationForm(std::string _target) : AForm("ShrubberyCreationForm", 147, 137), target(_target) {}

void ShrubberyCreationForm::execute(Bureaucrat const& executor) 
{
	AForm::execute(executor);
	std::cout << "writting to file\n";
}
