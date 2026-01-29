/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontele <afontele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 15:56:53 by afontele          #+#    #+#             */
/*   Updated: 2026/01/29 18:47:16 by afontele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequest Form", 72, 45), _target("default") {
	std::cout << getName() << "default constructor called." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequest Form", 72, 45), _target(_target) {
	std::cout << getName() << "constructor called." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm("RobotomyRequest Form", 72, 45), _target(_target) {
	std::cout << getName() << "copy constructor called." << std::endl;
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
	std::cout << getName() << "destructor called." << std::endl;
}

std::string	RobotomyRequestForm::getTarget() const {
	return (this->_target);
}

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const {
	
}

std::ostream	&operator<<(std::ostream &out, const RobotomyRequestForm &obj) {
	out << YELLOW << obj.getName() << ", sign grade " << obj.getSigGrade()
	<< ", execution grade " << obj.getExecGrade() << obj.getIsSigned() << END << std::endl;
	return (out);
}