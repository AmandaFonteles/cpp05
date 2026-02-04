/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontele <afontele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 15:31:12 by afontele          #+#    #+#             */
/*   Updated: 2026/02/02 17:06:42 by afontele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#include <string>
#include "AForm.hpp"

#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define END "\033[0m"

class	AForm;

class Bureaucrat
{
private:
	const std::string	_name;
	int					_grade;
	
public:
	Bureaucrat();
	Bureaucrat(const std::string name, int grade);
	Bureaucrat(Bureaucrat const &copy);
	Bureaucrat	&operator=(Bureaucrat const &copy);
	~Bureaucrat();
	const std::string	getName() const ;
	int			getGrade() const;
	void		incrementGrade(); //--
	void		decrementGrade(); //++
	void		signForm(AForm &f);
	void		executeForm(AForm const &form) const;
	//Exception nested classes
	class		GradeTooHighException : public std::exception
	{
	public:
		virtual const char *what()const throw();
	};
	class		GradeTooLowException : public std::exception 
	{
	public:
		virtual const char *what()const throw();
	};
};

std::ostream	&operator<<(std::ostream &out, const Bureaucrat &obj); // obj should be a pointer?why?

#endif