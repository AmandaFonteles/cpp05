/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontele <afontele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 15:27:36 by afontele          #+#    #+#             */
/*   Updated: 2026/02/05 19:01:29 by afontele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/AForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/Intern.hpp"
#include <ctime>

void	test1() {
	std::cout << YELLOW << "=== TEST 1 ===" << END << std::endl;
	
	std::cout << "=== CONSTRUCTORS ===" << std::endl;
	AForm		*f;
	Bureaucrat	b("Signer", 146);
	Bureaucrat	c("Executer", 138);
	Intern		i;

	f = i.makeForm("shrubbery creation", "Lily");
	if (!f)
		return ;

	std::cout << "=== Actual state ===" << std::endl;
	std::cout << *f;
	std::cout << b;
	std::cout << c;
	
	std::cout << "=== Bureaucrat tries to sign the form ===" << std::endl;
	b.signForm(*f);
	
	b.incrementGrade();
	
	std::cout << "=== Bureaucrat tries to sign the form ===" << std::endl;
	b.signForm(*f);
	std::cout << "=== Actual state ===" << std::endl;
	std::cout << *f;
	
	std::cout << "=== Bureaucrat tries to execute the form ===" << std::endl;
	c.executeForm(*f);
	
	c.incrementGrade();
	
	std::cout << "=== Bureaucrat tries to execute the form ===" << std::endl;
	c.executeForm(*f);
	
	std::cout << "=== DESTRUCTORS ===" << std::endl;
	delete	f;
}


void	test2() {
	std::cout << YELLOW << "=== TEST 2 ===" << END << std::endl;
	
	std::cout << "=== Trying to create invalid Form ===" << std::endl;
	AForm		*f;
	Bureaucrat	b("Signer", 73);
	Intern		i;

	f = i.makeForm("Tchubirubi", "Mimi");
	if (!f)
		return ;
}

int main(void)
{
	//RobotomyRequestForm - I moved to the main, because if I call execute multiple times in one sec (with srand inside), it will give me the same answer;
	std::srand(time(NULL));
	
	test1();
	std::cout << "\n=============================================\n" << std::endl;
	test2();
	std::cout << "\n=============================================\n" << std::endl;
	
	return (0);
}