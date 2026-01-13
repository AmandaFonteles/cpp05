/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontele <afontele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 15:27:36 by afontele          #+#    #+#             */
/*   Updated: 2026/01/13 17:46:10 by afontele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main() {
	Bureaucrat	a;
	Bureaucrat	b("Lili", 1);
	
	try
	{
		a.decrementGrade();
	}
	catch(Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	try
	{
		b.incrementGrade();
	}
	catch(Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return (0);
}