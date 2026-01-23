/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontele <afontele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 15:12:39 by afontele          #+#    #+#             */
/*   Updated: 2026/01/23 16:00:31 by afontele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class	Bureaucrat;

class	AForm {
private:
	const std::string	_formName;
	bool				_signed;
	const int			_sigGrade;
	const int			_execGrade;
public:
	AForm();
	AForm(const std::string name, const int gradeSig, const int gradeExec);
	AForm(const AForm &other);
	AForm				&operator=(const AForm &other);
	virtual	~AForm();
	const std::string	getName() const;
	bool				isSigned() const;
	int					getSigGrade()const ;
	int					getExecGrade() const;
	virtual void		beSigned(const Bureaucrat &b) = 0;
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

std::ostream	&operator<<(std::ostream &out, const AForm &obj);

#endif