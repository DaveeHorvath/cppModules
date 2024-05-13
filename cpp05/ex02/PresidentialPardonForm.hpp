#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP
#include "AFrom.hpp"
class PresidentialPardonForm : public AForm
{
	private:
		std::string target;

	public:
		PresidentialPardonForm() = delete;
		PresidentialPardonForm(std::string _target);
		PresidentialPardonForm(const PresidentialPardonForm& other) = default;
		~PresidentialPardonForm() = default;
		PresidentialPardonForm& operator=(PresidentialPardonForm& other) = default;

		void executeForm(Bureaucrat const & executor) override;
};

#endif
