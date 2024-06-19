#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
AForm::AForm(std::string _name, int _toSign, int _toExecute) : name(_name), requiredToSign(_toSign), requiredToExecute(_toExecute)
{
	if (_toSign > 150 || _toExecute > 150)
		throw GradeTooHighException();
	if (_toSign < 1 || _toExecute < 1)
		throw GradeTooLowException();
	isSigned = false;
}

void AForm::beSigned(Bureaucrat b)
{
	if (b.getGrade() > requiredToSign)
		throw GradeTooLowException();
	isSigned = true;
	std::cout << "Form signed by " << b;
}

void AForm::execute(Bureaucrat const& executor) const
{
	if (!isSigned)
		throw NotSignedException();
	if (executor.getGrade() > requiredToExecute)
		throw GradeTooLowException();
	std::cout << "Form executed by " << executor;
}

const char * AForm::GradeTooLowException::what() const noexcept
{
	return "AForm grade too low";
}

const char * AForm::GradeTooHighException::what() const noexcept
{
	return "AForm grade high low";
}

const char * AForm::NotSignedException::what() const noexcept
{
	return "Form isnt signed so cant be executed";
}

std::string AForm::getName() const
{
	return name;
}

int AForm::getSignGrade() const
{
	return requiredToSign;
}

int AForm::getExecuteGrade() const
{
	return requiredToExecute;
}

bool AForm::getIsSigned() const
{
	return isSigned;
}

std::ostream& operator<<(std::ostream& os, const AForm& f)
{
	std::cout << f.getName() << ", bureaucrat grade " << f.getSignGrade() << f.getExecuteGrade() << f.getIsSigned() << "\n";
	return os;
}
