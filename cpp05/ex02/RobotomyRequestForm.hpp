#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP
#include "AForm.hpp"
class RobotomyRequestForm : public AForm
{
	private:
		std::string target;

	public:
		RobotomyRequestForm() = delete;
		RobotomyRequestForm(std::string _target);
		RobotomyRequestForm(const RobotomyRequestForm& other) = default;
		~RobotomyRequestForm() = default;
		RobotomyRequestForm& operator=(RobotomyRequestForm& other) = default;

		void execute(Bureaucrat const & executor) override;
};

#endif
