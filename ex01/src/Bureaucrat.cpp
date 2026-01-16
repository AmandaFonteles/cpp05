/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontele <afontele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 15:31:36 by afontele          #+#    #+#             */
/*   Updated: 2026/01/16 17:00:00 by afontele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(150) {
	std::cout << "Default Bureaucrat created" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name) {
	if (grade < 1)
		throw(Bureaucrat::GradeTooHighException());
	else if (grade > 150)
		throw(Bureaucrat::GradeTooLowException());
	else
		this->_grade = grade;
	std::cout << "Bureaucrat " << this->_name << " created" << std::endl;
}

//We include "_copy" to the name only for debugging purposes, usually we would not do this.
Bureaucrat::Bureaucrat(const Bureaucrat &copy) : _name(copy._name + "_copy")
{
	std::cout << "Bureaucrat " << this->_name << " copied" << std::endl;
	*this = copy;
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &copy)
{
	if (this != &copy) {
		this->_grade = copy.getGrade();
	}
	return (*this);
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat " << this->_name << " destroyed" << std::endl;
}

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
	if (_grade + 1 > 150)
		throw(Bureaucrat::GradeTooLowException());
	this->_grade++;
	std::cout << "Bureaucrat " << this->_name << " decremented to grade " << this->_grade << std::endl;
}

void	Bureaucrat::incrementGrade()
{
	if (_grade - 1 < 1)
		throw(Bureaucrat::GradeTooHighException());
	this->_grade--;
	std::cout << "Bureaucrat " << this->_name << " incremented to grade " << this->_grade << std::endl;
}

void	Bureaucrat::signForm()
{
	if (Form::beSigned(*this))
}

const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high: grade needs to be between 1 and 150");
}

const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low: grade needs to be between 150 and 1");
}

std::ostream	&operator<<(std::ostream &out, const Bureaucrat &other)
{
	out << other.getName() << ", bureaucrat grade " << other.getGrade() << std::endl;
	return (out);
}