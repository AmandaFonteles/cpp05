/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontele <afontele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 15:12:29 by afontele          #+#    #+#             */
/*   Updated: 2026/02/04 15:59:18 by afontele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _formName("Default Form"), _signed(false), _sigGrade(150), _execGrade(150) {
	std::cout << _formName << " AForm constructor called." << std::endl;
}

AForm::AForm(const std::string name, const int gradeSig, const int gradeExec)
: _formName(name), _signed(false), _sigGrade(gradeSig), _execGrade(gradeExec) 
{
	if (gradeExec > 150 || gradeSig > 150)
		throw(AForm::GradeTooLowException());
	if (gradeExec < 1 || gradeSig < 1)
		throw(AForm::GradeTooHighException());

	std::cout << _formName << " AForm constructor called." << std::endl;
}

//We include "_copy" to the name only for debugging purposes, usually we would not do this.
AForm::AForm(const AForm &other)
: _formName(other._formName + "_copy"), _sigGrade(other._sigGrade), _execGrade(other._execGrade) {
	std::cout << "Copy " << _formName << " created" << std::endl;
	*this = other;
}

AForm	&AForm::operator=(const AForm &other) {
	if (this != &other)
		this->_signed = other._signed;
	return (*this);
}

AForm::~AForm() {
	std::cout << _formName << " AForm destroyed." << std::endl;
}

const std::string	AForm::getName() const {
	return (this->_formName);
}

int	AForm::getSigGrade() const {
	return (this->_sigGrade);
}

int	AForm::getExecGrade() const {
	return (this->_execGrade);
}

bool	AForm::isSigned() const {
	return (this->_signed);
}

const std::string	AForm::getIsSigned() const {
	if (isSigned())
		return (" is signed.");
	return (" isn't signed.");
}

void	AForm::beSigned(const Bureaucrat &b) {
	if (b.getGrade() <= this->_sigGrade) {
		this->_signed = true;
		std::cout << GREEN << b.getName() << " signed " << this->_formName << "." << END << std::endl;
	}
	else
		throw (AForm::GradeTooLowException());
}

const char *AForm::GradeTooHighException::what()const throw() {
	return (RED "Grade is too high" END);
}

const char *AForm::GradeTooLowException::what()const throw() {
	return (RED "Grade is too low" END);
}

const char *AForm::NoSignException::what()const throw() {
	return (RED "The form isn't signed" END);
}

std::ostream	&operator<<(std::ostream &out, const AForm &obj) {
	out << YELLOW << obj.getName() << ", sign grade " << obj.getSigGrade()
	<< ", execution grade " << obj.getExecGrade() << obj.getIsSigned() << END << std::endl;
	return (out);
}