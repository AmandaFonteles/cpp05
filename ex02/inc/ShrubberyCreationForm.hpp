/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontele <afontele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 15:56:01 by afontele          #+#    #+#             */
/*   Updated: 2026/01/29 19:06:52 by afontele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class	ShrubberyCreationForm : public AForm
{
private:
	std::string	_target;
	ShrubberyCreationForm();

public:
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(const ShrubberyCreationForm &other);
	ShrubberyCreationForm	&operator=(const ShrubberyCreationForm &other);
	~ShrubberyCreationForm();
	std::string	getTarget() const;
	void		execute(Bureaucrat const &executor) const;
};

std::ostream	&operator<<(std::ostream &out, const ShrubberyCreationForm &obj);