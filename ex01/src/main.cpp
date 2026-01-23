/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontele <afontele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 15:27:36 by afontele          #+#    #+#             */
/*   Updated: 2026/01/23 15:48:25 by afontele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/Form.hpp"

void	test1() {
	std::cout << YELLOW << "=== TEST 1 ===" << END << std::endl;
	
	std::cout << "=== CONSTRUCTORS ===" << std::endl;
	Form		f;
	Bureaucrat	b;

	std::cout << "=== Actual state ===" << std::endl;
	std::cout << f;
	std::cout << b;
	
	std::cout << "=== Bureaucrat tries to sign the form ===" << std::endl;
	b.signForm(f);

	std::cout << "=== Actual state ===" << std::endl;
	std::cout << f;
	std::cout << b;
	
	std::cout << "=== DESTRUCTORS ===" << std::endl;
}


void	test2() {
	std::cout << YELLOW << "=== TEST 2 ===" << END << std::endl;
	
	std::cout << "=== CONSTRUCTORS ===" << std::endl;
	Form		f("Big Form", 2, 1);
	Bureaucrat	b("Big Bureaucrat", 3);

	std::cout << "=== Actual state ===" << std::endl;
	std::cout << f;
	std::cout << b;
	
	std::cout << "=== Bureaucrat tries to sign the form ===" << std::endl;
	b.signForm(f);
	
	std::cout << "=== Actual state ===" << std::endl;
	std::cout << f;
	std::cout << b;
	
	std::cout << "=== Increase Bureaucrat grade ===" << std::endl;
	b.incrementGrade();

	std::cout << "=== Bureaucrat tries to sign the form again ===" << std::endl;
	b.signForm(f);
	
	std::cout << "=== Actual state ===" << std::endl;
	std::cout << f;
	std::cout << b;
	
	std::cout << "=== DESTRUCTORS ===" << std::endl;	
}

void	test3() {
	std::cout << YELLOW << "=== TEST 3 ===" << END << std::endl;
	
	std::cout << "=== Trying to create a form with grade 0 ===" << std::endl;
	try {
		Form *f = new Form("Wrong Form", 0, 0);
		std::cout << *f;
	}
	catch (const std::exception &e) {
		std::cerr << RED << e.what() << std::endl << END;
	}

	std::cout << "=== Trying to create a bureaucrat with grade 1000 ===" << std::endl;
	try {
		Bureaucrat	*b = new Bureaucrat("Wrong Bureaucrat", 1000);
		std::cout << *b;
	}
	catch (const std::exception &e) {
		std::cerr << RED << e.what()<< std::endl << END;
	}
}

void	test4() {
	std::cout << YELLOW << "=== TEST 4 ===" << END << std::endl;

	std::cout << "=== CONSTRUCTORS ===" << std::endl;
	Form		f("Form f", 5, 5);
	Form		f1(f);
	Bureaucrat	b("Bur b", 3);
	Bureaucrat	b1("Bur b1", 100);

	std::cout << "=== Actual state ===" << std::endl;
	std::cout << f;
	std::cout << f1;
	std::cout << b;
	std::cout << b1;
	
	std::cout << "=== Bureaucrat tries to sign the form ===" << std::endl;
	b.signForm(f);
	b1.signForm(f1);

	std::cout << "=== Copy assigment ===" << std::endl;
	b1 = b;

	std::cout << "=== Actual state ===" << std::endl;
	std::cout << f;
	std::cout << f1;
	std::cout << b;
	std::cout << b1;
	
	std::cout << "=== DESTRUCTORS ===" << std::endl;
}

int main(void)
{
	test1();
	std::cout << "=============================================\n" << std::endl;
	test2();
	std::cout << "=============================================\n" << std::endl;
	test3();
	std::cout << "=============================================\n" << std::endl;
	test4();
	std::cout << "=============================================\n" << std::endl;
	return (0);
}