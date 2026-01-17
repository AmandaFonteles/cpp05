/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontele <afontele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 15:27:36 by afontele          #+#    #+#             */
/*   Updated: 2026/01/17 16:54:05 by afontele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

//TODO: debug and test

int	main() {
	Bureaucrat	b("bureaucrat", 1);
	Form	f("form", 100, 100);

	b.signForm(f);
	return (0);
}