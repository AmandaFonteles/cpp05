/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontele <afontele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 11:47:45 by afontele          #+#    #+#             */
/*   Updated: 2026/02/05 18:53:50 by afontele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <AForm.hpp>

class Intern {
public:
	Intern();
	Intern(const Intern &other);
	Intern	&operator=(const Intern &other);
	~Intern();
	AForm	*makeForm(const std::string &formType, const std::string &target);
private:
	AForm	*makePresidential(const std::string &target);
	AForm	*makeRobotomy(const std::string &target);
	AForm	*makeShrubbery(const std::string &target);
};
