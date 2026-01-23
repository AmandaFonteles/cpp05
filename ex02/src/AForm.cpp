/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontele <afontele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 15:12:29 by afontele          #+#    #+#             */
/*   Updated: 2026/01/23 12:30:39 by afontele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
//ADD VALIDATION FOR GRADES IN FORM 1-150
Form::Form() : _formName("Default Form"), _signed(false), _sigGrade(150), _execGrade(150) {
	std::cout << _formName << " created." << std::endl;
}

Form::Form(const std::string name, const int gradeSig, const int gradeExec)
: _formName(name), _signed(false), _sigGrade(gradeSig), _execGrade(gradeExec) 
{
	if (gradeExec > 150 || gradeSig > 150)
		throw(Form::GradeTooLowException());
	if (gradeExec < 1 || gradeSig < 1)
		throw(Form::GradeTooHighException());

	std::cout << name << " Form created" << std::endl;
}

//We include "_copy" to the name only for debugging purposes, usually we would not do this.
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
	std::cout << "Form" << _formName << " destroyed" << std::endl;
}

const std::string	Form::getName() const {
	return (this->_formName);
}

int	Form::getSigGrade() const {
	return (this->_sigGrade);
}

int	Form::getExecGrade() const {
	return (this->_execGrade);
}

bool	Form::isSigned() const {
	return (this->_signed);
}

const std::string	Form::getIsSigned() const {
	if (isSigned())
		return (" is signed.");
	return (" isn't signed.");
}

void	Form::beSigned(const Bureaucrat &b) {
	if (b.getGrade() <= this->_sigGrade) {
		this->_signed = true;
		std::cout << GREEN << b.getName() << " signed " << this->_formName << "." << END << std::endl;
	}
	else
		throw (Form::GradeTooLowException());
}

const char *Form::GradeTooHighException::what()const throw() {
	return (RED "Grade is too high" END);
}

const char *Form::GradeTooLowException::what()const throw() {
	return (RED "Grade is too low" END);
}

std::ostream	&operator<<(std::ostream &out, const Form &obj) {
	out << YELLOW << obj.getName() << ", sign grade " << obj.getSigGrade()
	<< ", execution grade " << obj.getExecGrade() << obj.getIsSigned() << END << std::endl;
	return (out);
}