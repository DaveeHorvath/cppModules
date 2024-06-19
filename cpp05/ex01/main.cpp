#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
	Bureaucrat b = Bureaucrat("bob", 1);
	// test 1
	try
	{
		Form f = Form("job application", 0, 5);
	}	
	catch (std::exception& e)
	{
		std::cout << e.what() << "\n";
	}
	// test 2
	try
	{
		Form f = Form("job application", 5, 0);
	}	
	catch (std::exception& e)
	{
		std::cout << e.what() << "\n";
	}

	// test 3
	try
	{
		Form f = Form("job application", 151, 1);
	}	
	catch (std::exception& e)
	{
		std::cout << e.what() << "\n";
	}
	// test 4
	try
	{
		Form f = Form("job application", 1, 151);
	}	
	catch (std::exception& e)
	{
		std::cout << e.what() << "\n";
	}

	Form toSign{"to sign", 5, 5};
	toSign.beSigned(b);

	Bureaucrat weakBob{"Weak bob", 150};
	try
	{
		Form cantSign{"cant sign", 5, 5};
		cantSign.beSigned(weakBob);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Form alsoCantSign{"also cant sign", 150, 5};
		alsoCantSign.beSigned(weakBob);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	

}
