#include "Bureaucrat.hpp"
#include <iostream>

void testException(int grade, int increments, int testnumber)
{
	std::cout << testnumber << ".test\n";
	try
	{
		Bureaucrat dumb("dumb", grade);
		for (int i = increments; i > 0; i--) {
			std::cout << dumb;
			dumb.decrementGrade();
		}
		for (int i = increments; i < 0; i++) {
			std::cout << dumb;
			dumb.incrementGrade();
		}
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << "\n";
	}
}

int main()
{
	testException(0, 0, 0); // test 0
	testException(-1, 0, 1);// test 1
	testException(151, 0, 2);// test 2
	testException(152, 0, 3);// test 3
	testException(1, 1, 4);// test 4
	testException(2, 2, 5);// test 5
	testException(150, -1, 6);// test 6
	testException(149, -2, 7);// test 7
	testException(1, -150, 8);// test 8
	testException(150, 150, 9);// test 9
}
