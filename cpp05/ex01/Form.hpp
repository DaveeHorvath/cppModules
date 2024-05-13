#ifndef FORM_HPP
#define FORM_HPP
#include <exception>
#include <ostream>
#include <string>
class Bureaucrat;
class Form {
	private:
		const std::string name;
		bool isSigned;
		const int requiredToSign;
		const int requiredToExecute;
	public:
		Form() = delete;
		Form(std::string _name, int _toSign, int toExecute);
		~Form() = default;
		Form(const Form& other) = default;
		Form& operator=(Form& other);
		void beSigned(Bureaucrat b);
		std::string getName() const;
		int getSignGrade() const;
		int getExecuteGrade() const;
		bool getIsSigned() const;
		class GradeTooHighException : public std::exception
		{
			const char * what() const noexcept;
		};
		class GradeTooLowException : public std::exception
		{
			const char * what() const noexcept;
		};
};

std::ostream& operator<<(std::ostream& os, const Form& f);
#endif
