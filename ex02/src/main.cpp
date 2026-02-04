/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontele <afontele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 15:27:36 by afontele          #+#    #+#             */
/*   Updated: 2026/02/04 16:46:12 by afontele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/AForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"

void	test1() {
	std::cout << YELLOW << "=== TEST 1 ===" << END << std::endl;
	
	std::cout << "=== CONSTRUCTORS ===" << std::endl;
	AForm		*f = new ShrubberyCreationForm("Pipa");
	Bureaucrat	b("Signer", 146);
	Bureaucrat	c("Executer", 138);

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
	
	std::cout << "=== CONSTRUCTORS ===" << std::endl;
	AForm		*f = new RobotomyRequestForm("Pipo");
	Bureaucrat	b("Signer", 73);
	Bureaucrat	c("Executer", 46);

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

void	test3() {
	std::cout << YELLOW << "=== TEST 3 ===" << END << std::endl;
	
	std::cout << "=== CONSTRUCTORS ===" << std::endl;
	AForm		*f = new PresidentialPardonForm("Pipe");
	Bureaucrat	b("Signer", 26);
	Bureaucrat	c("Executer", 6);

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

void	test4() {
	std::cout << YELLOW << "=== TEST 4 ===" << END << std::endl;
	
	std::cout << "=== CONSTRUCTORS ===" << std::endl;
	AForm		*f = new PresidentialPardonForm("Amanda");
	Bureaucrat	b("Signer", 26);
	Bureaucrat	c("Executer", 6);

	std::cout << "=== Actual state ===" << std::endl;
	std::cout << *f;
	std::cout << b;
	std::cout << c;
	
	std::cout << "=== Bureaucrat tries to sign the form ===" << std::endl;
	b.signForm(*f);
	
	b.incrementGrade();
	
	std::cout << "=== Bureaucrat tries to sign the form ===" << std::endl;
	b.signForm(*f);
	std::cout << "=== F Form ===" << std::endl;
	std::cout << *f;
	
	AForm	*g = f;
	
	std::cout << "=== G Form ===" << std::endl;
	std::cout << *g;
	std::cout << "=== Bureaucrat tries to execute the form ===" << std::endl;
	c.executeForm(*g);
	
	c.incrementGrade();
	
	std::cout << "=== Bureaucrat tries to execute the form ===" << std::endl;
	c.executeForm(*f);
	
	std::cout << "=== DESTRUCTORS ===" << std::endl;
	delete	f;
	delete g;
}

void	test5() {
	std::cout << YELLOW << "=== TEST 5 ===" << END << std::endl;
	
	std::cout << "=== CONSTRUCTORS ===" << std::endl;
	AForm		*f = new RobotomyRequestForm("Lily");
	AForm		*g = new RobotomyRequestForm("Fifi");
	Bureaucrat	b("Signer", 73);
	Bureaucrat	c("Executer", 46);

	std::cout << "=== Actual state ===" << std::endl;
	std::cout << *f;
	std::cout << *g;
	std::cout << b;
	std::cout << c;
	
	std::cout << "=== Bureaucrat tries to sign the form ===" << std::endl;
	b.signForm(*f);
	
	b.incrementGrade();
	
	std::cout << "=== Bureaucrat tries to sign the form ===" << std::endl;
	b.signForm(*f);
	std::cout << "=== F Form ===" << std::endl;
	std::cout << *f;
	
	g = f;
	
	std::cout << "=== G Form after assignement ===" << std::endl;
	std::cout << *g;
	std::cout << "=== Bureaucrat tries to execute the form ===" << std::endl;
	c.executeForm(*g);
	
	c.incrementGrade();
	
	std::cout << "=== Bureaucrat tries to execute the form ===" << std::endl;
	c.executeForm(*f);
	
	std::cout << "=== DESTRUCTORS ===" << std::endl;
	delete	f;
	delete g;
}
 //CHeck why is leaking and invalid read
int main(void)
{
	//RobotomyRequestForm - I moved to the main, because if I call execute multiple times in one sec (with srand inside), it will give me the same answer;
	std::srand(time(NULL));
	
	test1();
	std::cout << "=============================================\n" << std::endl;
	test2();
	std::cout << "=============================================\n" << std::endl;
	test3();
	std::cout << "=============================================\n" << std::endl;
	test4();
	std::cout << "=============================================\n" << std::endl;
	test5();
	std::cout << "=============================================\n" << std::endl;
	return (0);
}