/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreation.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asablayr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 10:49:11 by asablayr          #+#    #+#             */
/*   Updated: 2021/03/04 14:28:51 by asablayr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreation.hpp"
#include <iostream>
#include <fstream>
#include <string>

Shrubbery::Shrubbery(std::string name): Form(name, 145, 137)
{
	std::cout << "naissance du Shrubbery : '" << getName() << "'\n";
}

Shrubbery::Shrubbery(Shrubbery const& copy): Form(copy.getName(), copy.getSignRank(), copy.getExeRank())
{
	std::cout << "naissance par copie d'un Shrubbery\n";
}

Shrubbery& Shrubbery::operator = (Shrubbery const & copy)
{
	if (copy.getCheck())
		setCheck();
	std::cout << "copy d'un Shrubbery\n";
	return (*this);
}

Shrubbery::~Shrubbery()
{
	std::cout << "destruction du Shrubbery " << getName() << std::endl;
}

void Shrubbery::execute(Bureaucrat const& executor) const
{
	Form::execute(executor);
	std::ofstream file;
	std::string tmp = getName() + "_shrubbery";
	file.open(tmp.c_str());
	file << ASCII_TREE;
	file.close();
	std::cout << "tree planted in " << tmp << std::endl;
}
