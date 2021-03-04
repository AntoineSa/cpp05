/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asablayr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 10:49:11 by asablayr          #+#    #+#             */
/*   Updated: 2021/03/04 13:34:41 by asablayr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <fstream>

PresidentialPardonForm::PresidentialPardonForm(std::string const& name): Form(name, 25, 5)
{
	std::cout << "creation d'un PresidentialPardonForm : '" << getName() << "'\n";
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const& copy): Form(copy.getName(), copy.getSignRank(), copy.getExeRank())
{
	std::cout << "naissance par copie d'un PresidentialPardonForm\n";
}

PresidentialPardonForm& PresidentialPardonForm::operator = (PresidentialPardonForm const & copy)
{
	if(copy.getCheck())
		setCheck();
	std::cout << "copy d'un RobotomyRequestForm\n";
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "destruction du PresidentialPardonForm :  " << getName() << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const& executor) const
{
	if (executor.getGrade() > getExeRank())
		throw GradeTooLowException();
	else
		std::cout << executor.getName() <<" has been pardonned by Zafod Beeblebrox.\n";
}
