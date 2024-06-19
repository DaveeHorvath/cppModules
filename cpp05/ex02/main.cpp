#include "Bureaucrat.hpp"
#include <iostream>
#include "PresidentialPardonForm.hpp"
#include "ShrubberryCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{
	Bureaucrat bob{"Bob", 150};
	Bureaucrat tom{"Tom", 50};
	Bureaucrat president{"Zaphod Beenlebrox", 1};

	std::cout << "<====Shrubbery form test====>\n";
	ShrubberyCreationForm s{"you"};
	
	tom.executeFrom(s);
	bob.singForm(s);
	tom.singForm(s);
	bob.executeFrom(s);
	tom.executeFrom(s);

	std::cout << "<====Robotomy form test====>\n";
	RobotomyRequestForm R{"you"};
	president.executeFrom(R);
	bob.singForm(R);
	tom.singForm(R);
	bob.executeFrom(R);
	tom.executeFrom(R);
	president.executeFrom(R);
	
	std::cout << "<====Presidential form test====>\n";
	PresidentialPardonForm P{"you"};
	bob.singForm(P);
	tom.singForm(P);
	president.singForm(P);
	bob.executeFrom(P);
	tom.executeFrom(P);
	president.executeFrom(P);
	
}