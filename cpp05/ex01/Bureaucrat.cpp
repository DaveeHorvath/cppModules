#include "Bureaucrat.hpp"
#include <iostream>
Bureaucrat::Bureaucrat(const std::string _name, int _grade) : name(_name)
{
	if (_grade > 150)
		throw Bureaucrat::GradeTooLowException();
	if (_grade < 1)
		throw Bureaucrat::GradeTooHighException(); 
	grade = _grade;
}	
Bureaucrat::~Bureaucrat()
{}
Bureaucrat& Bureaucrat::operator=(Bureaucrat& other)
{
	grade = other.getGrade();
	return *this;
}

std::string Bureaucrat::getName() const
{
	return name;
}

int Bureaucrat::getGrade() const
{
	return grade;
}

void Bureaucrat::incrementGrade()
{
	if (grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	grade--;
}

void Bureaucrat::decrementGrade() 
{
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	grade++;
}

const char * Bureaucrat::GradeTooHighException::what() const noexcept
{
	return "Grade too high";
}

const char * Bureaucrat::GradeTooLowException::what() const noexcept
{
	return "Grade too low";
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
	std::cout << b.getName() << ", bureaucrat grade " << b.getGrade() << "\n";
	return os;
}
