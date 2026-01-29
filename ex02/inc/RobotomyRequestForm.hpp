/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontele <afontele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 15:56:44 by afontele          #+#    #+#             */
/*   Updated: 2026/01/29 19:06:46 by afontele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
private:
	std::string	_target;
	
public:
	RobotomyRequestForm();
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(RobotomyRequestForm const &other);
	RobotomyRequestForm	&operator=(RobotomyRequestForm const &other);
	~RobotomyRequestForm();
	std::string	getTarget() const;
	void	execute(Bureaucrat const &executor) const;
};

std::ostream	&operator<<(std::ostream &out, const RobotomyRequestForm &obj);