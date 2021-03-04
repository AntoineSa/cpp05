/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asablayr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 10:49:11 by asablayr          #+#    #+#             */
/*   Updated: 2021/03/04 14:58:41 by asablayr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <fstream>

RobotomyRequestForm::RobotomyRequestForm(std::string name): Form(name, 72, 45)
{
	std::cout << "creation du RobotomyRequestForm : " << getName() << "\n";
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const& copy): Form(copy.getName(), copy.getSignRank(), copy.getExeRank())
{
	std::cout << "naissance par copie d'un RobotomyRequestForm\n";
}

RobotomyRequestForm& RobotomyRequestForm::operator = (RobotomyRequestForm const & copy)
{
	if(copy.getCheck())
		setCheck();
	std::cout << "copy d'un RobotomyRequestForm\n";
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "destruction du RobotomyRequestForm " << getName() << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
	try
	{
		Form::execute(executor);
	}
	catch (std::exception& e)
	{
		throw e;
	}
	std::cout << "** rattling noise of screws **\t" << executor.getName() << " has been robotomized\n";
}
