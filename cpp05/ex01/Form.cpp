#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
Form::Form(std::string _name, int _toSign, int _toExecute) : name(_name), requiredToSign(_toSign), requiredToExecute(_toExecute)
{
	if (_toSign > 150 || _toExecute > 150)
		throw new GradeTooHighException();
	if (_toSign < 1 || _toExecute < 1)
		throw new GradeTooLowException();
	isSigned = false;
}

void Form::beSigned(Bureaucrat b)
{
	if (b.getGrade() < requiredToSign)
		throw new GradeTooLowException();
	isSigned = true;
}

const char * Form::GradeTooLowException::what() const noexcept
{
	return "Form grade too low";
}

const char * Form::GradeTooHighException::what() const noexcept
{
	return "Form grade high low";
}

std::string Form::getName() const
{
	return name;
}

int Form::getSignGrade() const
{
	return requiredToSign;
}

int Form::getExecuteGrade() const
{
	return requiredToExecute;
}

bool Form::getIsSigned() const
{
	return isSigned;
}

std::ostream& operator<<(std::ostream& os, const Form& f)
{
	std::cout << f.getName() << ", bureaucrat grade " << f.getSignGrade() << f.getExecuteGrade() << f.getIsSigned() << "\n";
	return os;
}
