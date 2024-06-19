#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP
#include "AForm.hpp"
class ShrubberyCreationForm : public AForm
{
	private:
		std::string target;

	public:
		ShrubberyCreationForm() = delete;
		ShrubberyCreationForm(std::string _target);
		ShrubberyCreationForm(const ShrubberyCreationForm& other) = default;
		~ShrubberyCreationForm() = default;
		ShrubberyCreationForm& operator=(ShrubberyCreationForm& other) = default;

		void execute(Bureaucrat const & executor) const override;
};

#endif
