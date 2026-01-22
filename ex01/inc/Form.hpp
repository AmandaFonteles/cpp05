/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontele <afontele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 15:12:39 by afontele          #+#    #+#             */
/*   Updated: 2026/01/22 13:54:33 by afontele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class	Bureaucrat;

class	Form {
private:
	const std::string	_formName;
	bool				_signed;
	const int			_sigGrade;
	const int			_execGrade;
public:
	Form();
	Form(const std::string name, const int gradeSig, const int gradeExec);
	Form(const Form &other);
	Form	&operator=(const Form &other);
	~Form();
	const std::string	getName() const;
	bool				isSigned() const;
	int			getSigGrade()const ;
	int			getExecGrade() const;
	void				beSigned(const Bureaucrat &b);
	const std::string	getIsSigned() const;
	class	GradeTooHighException : public std::exception
	{
	public:
		virtual const char *what()const throw();
	};
	class	GradeTooLowException : public std::exception 
	{
	public:
		virtual const char *what()const throw();
	};
};

std::ostream	&operator<<(std::ostream &out, const Form &obj);

#endif