/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontele <afontele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 15:31:12 by afontele          #+#    #+#             */
/*   Updated: 2026/01/17 16:32:40 by afontele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#include <string>
#include "Form.hpp"

class Bureaucrat : public Form
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
	void		signForm(Form &f);
	//Exception nested classes
	class		GradeTooHighException : public std::exception //should be virtual?
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

std::ostream	&operator<<(std::ostream &out, Bureaucrat &obj);

#endif