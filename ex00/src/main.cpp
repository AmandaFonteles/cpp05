/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontele <afontele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 15:27:36 by afontele          #+#    #+#             */
/*   Updated: 2026/01/16 13:20:09 by afontele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main() {
	std::cout << YELLOW <<"=== CONSTRUCTORS ===\n\n" << END;
	Bureaucrat	a;
	Bureaucrat	b("Pipa", 1);
	Bureaucrat	*c = new Bureaucrat("Pipo", 2);
	Bureaucrat	d(b);
	
	std::cout << YELLOW << "\n=== TESTS ===\n\n" << END;
	std::cout << "Trying to decrement grade of " <<a.getName() << std::endl;
	std::cout << a;
	try
	{
		a.decrementGrade();
	}
	catch(Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << RED << e.what() << '\n' << END;
	}
	std::cout << "Bureaucrat " << a.getName() << " should not have changed grade." << std::endl;
	std::cout << a << std::endl;

	std::cout << "\nTrying to increment grade of " << b.getName() << std::endl;
	std::cout << b;
	try
	{
		b.incrementGrade();
	}
	catch(Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << RED << e.what() << '\n' << END;
	}
	std::cout << "Bureaucrat " << b.getName() << " should not have changed grade." << std::endl;
	std::cout << b << std::endl;
	
	std::cout << "\nTrying to decrement grade of " << c->getName() << std::endl;
	std::cout << *c;
	try
	{
		c->decrementGrade();
	}
	catch(Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << RED << e.what() << '\n' << END;
	}
	std::cout << "Bureaucrat " << c->getName() << " should have changed grade." << std::endl;
	std::cout << *c << std::endl;
	
	std::cout << "\nTrying to increment grade of " << d.getName() << std::endl;
	std::cout << d;
	try
	{
		d.incrementGrade();
	}
	catch(Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << RED << e.what() << '\n' << END;
	}
	std::cout << "Bureaucrat " << d.getName() << " should not have changed grade." << std::endl;
	std::cout << d;
	
	std::cout << "\nTrying to create Bureaucrat with grade 0" << std::endl;
	try
	{
		Bureaucrat("Non existent", 0);
	}
	catch(Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << RED << e.what() << '\n' << END;
	}
	std::cout << "Bureaucrat Non existent should not have been created." << std::endl;
	
	std::cout << YELLOW << "\n=== DESTRUCTORS ===\n\n" << END;
	delete c;
	
	return (0);
}