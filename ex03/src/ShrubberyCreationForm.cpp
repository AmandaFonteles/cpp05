/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontele <afontele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 15:56:17 by afontele          #+#    #+#             */
/*   Updated: 2026/02/04 15:36:05 by afontele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery Form", 145, 137), _target("default") {
	std::cout << getName() << " default constructor called." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shrubbery Form", 145, 137), _target(target) {
	std::cout << getName() << " constructor called." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other) {
	std::cout << getName() << " copy constructor called." << std::endl;
	this->_target = other._target;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
	if (this != &other) {
		AForm::operator=(other);
		this->_target = other._target;
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << getName() << " destructor called." << std::endl;
}

std::string	ShrubberyCreationForm::getTarget() const {
	return (this->_target);
}

void		ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
	if (!this->isSigned())
		throw (AForm::NoSignException());
	else if (executor.getGrade() > this->getExecGrade())
		throw (AForm::GradeTooLowException());
	else {
		std::ofstream	file;

		file.open((_target + "_shrubbery").c_str());
		if (file.fail()) {
			std::cerr << "Error opening file\n";
			return ;
		}
		file << "     A" << std::endl;
		file << "    AAA" << std::endl;
		file << "   AAAAA" << std::endl;
		file << "  AAAAAAA" << std::endl;
		file << "    | |" << std::endl;

		file.close();
	}
}

std::ostream	&operator<<(std::ostream &out, const ShrubberyCreationForm &obj) {
	out << YELLOW << obj.getName() << ", sign grade " << obj.getSigGrade()
	<< ", execution grade " << obj.getExecGrade() << obj.getIsSigned() << END << std::endl;
	return (out);
}