#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
RobotomyRequestForm::RobotomyRequestForm(std::string _target) : AForm("RobotomyRequestForm", 72, 45), target(_target) {}

void RobotomyRequestForm::execute(Bureaucrat const& executor) 
{
	AForm::execute(executor);
	std::cout << target << "has been 50% robotomised\n";
}
