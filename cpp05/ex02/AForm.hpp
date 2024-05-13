#ifndef AFORM_HPP
#define AFORM_HPP
#include <exception>
#include <ostream>
#include <string>
class Bureaucrat;
class AForm {
	private:
		const std::string name;
		bool isSigned;
		const int requiredToSign;
		const int requiredToExecute;
	public:
		AForm() = delete;
		AForm(std::string _name, int _toSign, int toExecute);
		virtual ~AForm() = default;
		AForm(const AForm& other) = default;
		AForm& operator=(AForm& other);
		void beSigned(Bureaucrat b);
		virtual void execute(Bureaucrat const & executor);
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

std::ostream& operator<<(std::ostream& os, const AForm& f);
#endif
