/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontele <afontele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 15:31:36 by afontele          #+#    #+#             */
/*   Updated: 2026/01/23 12:31:01 by afontele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default Bureaucrat"), _grade(150) {
	std::cout << _name << " created." << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name) {
	//use set_grade and try catch inside the constructor?
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

void	Bureaucrat::signForm(Form &f)
{
	if (f.isSigned()) {
		std::cout << YELLOW << "Form " << f.getName() << " is already signed." << END << std::endl;
		return ;
	}
	try
	{
		f.beSigned(*this);
	}
	catch(const std::exception &e)
	{
		std::cout << RED << this->_name << " couldn't sign " << f.getName() << " because " << e.what() << END << std::endl ;
		return ;
	}
}

const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return (RED "Grade is too high" END);
}

const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return (RED "Grade is too low" END);
}

std::ostream	&operator<<(std::ostream &out, const Bureaucrat &other)
{
	out << YELLOW << other.getName() << ", bureaucrat grade " << other.getGrade() << "." << END << std::endl;
	return (out);
}