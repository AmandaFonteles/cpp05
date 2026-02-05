/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontele <afontele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 11:48:07 by afontele          #+#    #+#             */
/*   Updated: 2026/02/05 18:56:29 by afontele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Intern.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/Bureaucrat.hpp"

Intern::Intern()
{
	// std::cout << "Intern Constructor called." << std::endl;
}

Intern::Intern(const Intern &other) {
	*this = other;
}

Intern	&Intern::operator=(const Intern &other) {
	if (this != &other) {
		return *this;
	}
	return *this;
}

Intern::~Intern()
{
	// std::cout << "Intern Destructor called." << std::endl;
}

AForm	*Intern::makePresidential(const std::string &target) {
	return (new PresidentialPardonForm(target));
}

AForm	*Intern::makeRobotomy(const std::string &target) {
	return (new RobotomyRequestForm(target));
}

AForm	*Intern::makeShrubbery(const std::string &target) {
	return (new ShrubberyCreationForm(target));
}

AForm	*Intern::makeForm(const std::string &formType, const std::string &target) {
	AForm	*(Intern::*ptrarray[3])(const std::string&) = {&Intern::makePresidential, &Intern::makeRobotomy, &Intern::makeShrubbery};
	std::string	t[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};

	for (int i = 0; i < 3; i++) {
		if (t[i] == formType) {
			std::cout << GREEN << "Intern creates " << formType << END << std::endl;
			return ((this->*ptrarray[i])(target));
		}
	}
	std::cerr << RED << "Intern can't create form: Wrong form type" << END << std::endl;
	return (NULL);
}