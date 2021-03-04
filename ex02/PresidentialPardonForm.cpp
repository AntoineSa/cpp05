/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asablayr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 10:49:11 by asablayr          #+#    #+#             */
/*   Updated: 2021/03/04 14:13:47 by asablayr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <fstream>
#include <string>

PresidentialPardonForm::PresidentialPardonForm(std::string name): Form(name, 145, 137)
{
	std::cout << "creation du Presidential pardon form : '" << getName() << "'\n";
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const& copy): Form(copy.getName(), copy.getSignRank(), copy.getExeRank())
{
	std::cout << "naissance par copie du Presidential pardon form\n";
}

PresidentialPardonForm& PresidentialPardonForm::operator = (PresidentialPardonForm const & copy)
{
	if (copy.getCheck())
		setCheck();
	std::cout << "copy d'un Presidential pardon form\n";
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "destruction du Presidential pardon form " << getName() << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const& executor) const
{
	if (executor.getGrade() > getExeRank())
		throw GradeTooLowException() ;
	std::cout << executor.getName() <<" has been pardonned by Zafod Beeblebrox\n";
}
