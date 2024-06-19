#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
PresidentialPardonForm::PresidentialPardonForm(std::string _target) : AForm("PresidentialPardonForm", 25, 5), target(_target) {}

void PresidentialPardonForm::execute(Bureaucrat const& executor) const
{
	AForm::execute(executor);
	std::cout << target << " has been pardond by our lord, savior and president Zaphod Beenlebrox!\n";
}
