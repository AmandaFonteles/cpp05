/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontele <afontele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 15:57:26 by afontele          #+#    #+#             */
/*   Updated: 2026/02/04 15:53:28 by afontele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardon Form", 25, 5), _target("default") {
	std::cout << getName() << " default constructor called." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardon Form", 25, 5), _target(target)
{
	std::cout << getName() << " constructor called." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &other) : AForm(other) {
	std::cout << getName() << " copy constructor called." << std::endl;
	this->_target = other._target;
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(PresidentialPardonForm const &other) {
	if (this != &other) {
		AForm::operator=(other);
		this->_target = other._target;
	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << getName() << " destructor called." << std::endl;
}

std::string	PresidentialPardonForm::getTarget() const {
	return (this->_target);
}

void	PresidentialPardonForm::execute(Bureaucrat const &executor) const {
	if (!this->isSigned())
		throw (AForm::NoSignException());
	else if (executor.getGrade() > this->getExecGrade())
		throw (AForm::GradeTooLowException());
	else
		std::cout << GREEN << this->_target << " has been pardoned by Zaphod Beeblebrox" << END << std::endl;
}

std::ostream	&operator<<(std::ostream &out, const PresidentialPardonForm &obj) {
	out << YELLOW << obj.getName() << ", sign grade " << obj.getSigGrade()
	<< ", execution grade " << obj.getExecGrade() << obj.getIsSigned() << END << std::endl;
	return (out);
}