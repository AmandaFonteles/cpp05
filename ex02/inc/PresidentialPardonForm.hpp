/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontele <afontele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 15:57:17 by afontele          #+#    #+#             */
/*   Updated: 2026/01/29 18:52:27 by afontele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class PresidentialPardonForm : public AForm {
private:
	std::string	_target;
public:
	PresidentialPardonForm();
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(PresidentialPardonForm const &other);
	PresidentialPardonForm	&operator=(PresidentialPardonForm const &other);
	~PresidentialPardonForm();
	std::string	getTarget() const;
	void	execute(Bureaucrat const &executor) const;
};

std::ostream	&operator<<(std::ostream &out, PresidentialPardonForm const &obj);
