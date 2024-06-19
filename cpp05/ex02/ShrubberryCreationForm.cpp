#include "AForm.hpp"
#include "ShrubberryCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <fstream>
ShrubberyCreationForm::ShrubberyCreationForm(std::string _target) : AForm("ShrubberyCreationForm", 147, 137), target(_target) {}

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
	AForm::execute(executor);
	std::string tree(
	"	          \\/ |    |/\n"
    "      \\/ / \\||/  /_/___/_\n"
    "       \\/   |/ \\/\n"
    "  _\\__\\_\\   |  /_____/_\n"
    "         \\  | /          /\n"
	"__ _-----`  |{,-----------~\n"
    "          \\ }{\n"
    "           }{{\n"
    "           }}{\n"
    "           {{}\n"
    "     , -=-~{ .-^- _\n"
    "          `}\n"
    "            {\n"
	);

	std::ofstream towrite(target + "_shrubbery");
	if (towrite)
		towrite << tree;
}
