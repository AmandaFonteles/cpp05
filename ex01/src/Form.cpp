/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontele <afontele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 15:12:29 by afontele          #+#    #+#             */
/*   Updated: 2026/01/16 16:56:16 by afontele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _formName("default"), _signed(false), _sigGrade(150), _execGrade(150) {
	std::cout << "Default Form created" << std::endl;
}

Form::Form(const std::string name, const int gradeSig, const int gradeExec)
: _formName(name), _signed(false), _sigGrade(gradeSig), _execGrade(gradeExec) {
	std::cout << name << " Form created" << std::endl;
}

Form::Form(const Form &other)
: _formName(other._formName + "_copy"), _sigGrade(other._sigGrade), _execGrade(other._execGrade) {
	std::cout << "Copy " << _formName << " created" << std::endl;
	*this = other;
}

Form	&Form::operator=(const Form &other) {
	if (this != &other)
		this->_signed = other._signed;
	return (*this);
}

Form::~Form() {
	std::cout << _formName << " destroyed" << std::endl;
}

const std::string	Form::getName() const {
	return (this->_formName);
}

const int	Form::getSigGrade() const {
	return (this->_sigGrade);
}

const int	Form::getExecGrade() const {
	return (this->_execGrade);
}

bool	Form::isSigned() const {
	return (this->_signed);
}

const std::string	Form::getIsSigned() const {
	if (isSigned())
		return (" is signed");
	return (" isn't signed");
}

void	Form::beSigned(const Bureaucrat &b) {
	if (b.getGrade() <= this->_sigGrade)
		this->_signed = true;
	else
		throw (Form::GradeTooLowException());
}

const char *Form::GradeTooHighException::what()const throw() {
	
}

const char *Form::GradeTooLowException::what()const throw() {
	
}

std::ostream	&operator<<(std::ostream &out, const Form &obj) {
	out << "The Form " << obj.getName() << ", sign grade " << obj.getSigGrade()
	<< ", execution grade " << obj.getExecGrade() << obj.getIsSigned() << std::endl;
	return (out);
}