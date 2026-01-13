/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontele <afontele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 15:31:36 by afontele          #+#    #+#             */
/*   Updated: 2026/01/12 17:08:50 by afontele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default bureaucrat"), _grade(150) {}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name) {
	if (grade < 1)
		throw(Bureaucrat::GradeTooHighException());
	else if (grade > 150)
		throw(Bureaucrat::GradeTooLowException());
	else
		this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : _name(copy._name)
{
	*this = copy;
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &copy)
{
	if (this != &copy) {
		this->_grade = copy._grade;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat() {}

const std::string	Bureaucrat::getName() const
{
	return (this->_name);
}

int	Bureaucrat::getGrade() const 
{
	return (this->_grade);
}

void	Bureaucrat::decrementGrade()
{
	this->_grade++;
	if (_grade > 150)
		throw(Bureaucrat::GradeTooLowException());
}

void	Bureaucrat::incrementGrade()
{
	this->_grade--;
	if (_grade < 1)
		throw(Bureaucrat::GradeTooHighException());
}

const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high: grade needs to be between 1 and 150");
}

const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low: grade needs to be between 150 and 1");
}

std::ostream	&operator<<(std::ostream &out, Bureaucrat &other)
{
	out << other.getName() << ", bureaucrat grade " << other.getGrade() << std::endl;
	return (out);
}