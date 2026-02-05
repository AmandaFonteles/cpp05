/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontele <afontele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 15:56:53 by afontele          #+#    #+#             */
/*   Updated: 2026/02/04 18:14:58 by afontele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequest Form", 72, 45), _target("default") {
	std::cout << getName() << " default constructor called." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequest Form", 72, 45), _target(target) {
	std::cout << getName() << " constructor called." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other) {
	std::cout << getName() << " copy constructor called." << std::endl;
	this->_target = other._target;
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
	if (this != &other) {
		AForm::operator=(other);
		this->_target = other._target;
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << getName() << " destructor called." << std::endl;
}

std::string	RobotomyRequestForm::getTarget() const {
	return (this->_target);
}

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const {
	if (!this->isSigned())
		throw (AForm::NoSignException());
	else if (executor.getGrade() > this->getExecGrade())
		throw (AForm::GradeTooLowException());
	else {
		int	ram = rand();
		std::cout << GREEN << "RrrRrRrRroAR" << END << std::endl;
		if (ram % 2) {
			std::cout << GREEN << this->_target << " has been robotomized successfully." << END << std::endl;
		}
		else
			std::cout << GREEN << this->_target << " robotomy failed." << END << std::endl;
	}
}

std::ostream	&operator<<(std::ostream &out, const RobotomyRequestForm &obj) {
	out << YELLOW << obj.getName() << ", sign grade " << obj.getSigGrade()
	<< ", execution grade " << obj.getExecGrade() << obj.getIsSigned() << END << std::endl;
	return (out);
}