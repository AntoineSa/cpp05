/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asablayr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 10:49:11 by asablayr          #+#    #+#             */
/*   Updated: 2021/02/25 11:00:41 by asablayr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <fstream>

RobotomyRequestForm::RobotomyRequestForm(std::string const& name): Form(name, 72, 45)
{
	std::cout << "naissance d'un RobotomyRequestForm\n";
}

RobotomyRequestForm::RobotomyRequestForm(Shrubbery const& copy): Form(copy.getName(), copy.getSignRank(), copy.getExeRank())
{
	std::cout << "naissance par copie d'un RobotomyRequestForm\n";
}

RobotomyRequestForm& RobotomyRequestForm::operator = (Shrubbery const & copy)
{
	_check = copy.getCheck();
	std::cout << "copy d'un RobotomyRequestForm\n";
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "destruction du RobotomyRequestForm " << _name << std::endl;
}

void RobotomyRequestForm::action()
{
	std::cout << "rattling noise of screws\n";
}

std::ostream& operator << (std::ostream &out, const RobotomyRequestForm &form)
{
	if (form.getCheck())
		out << " of grade ";
	else
		out << " of grade ";
	return (out);
}
