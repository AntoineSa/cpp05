/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreation.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asablayr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 10:49:11 by asablayr          #+#    #+#             */
/*   Updated: 2021/02/24 18:59:36 by asablayr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreation.hpp"
#include <iostream>
#include <fstream>

Shrubbery::Shrubbery(std::string const& name): Form(name + "_shrubbery", 145, 137)
{
	std::cout << "naissance d'un Shrubbery\n";
}

Shrubbery::Shrubbery(Shrubbery const& copy): Form(copy.getName(), copy.getSignRank(), copy.getExeRank())
{
	std::cout << "naissance par copie d'un Shrubbery\n";
}

Shrubbery& Shrubbery::operator = (Shrubbery const & copy)
{
	_check = copy.getCheck();
	std::cout << "copy d'un Shrubbery\n";
	return (*this);
}

Shrubbery::~Shrubbery()
{
	std::cout << "destruction du Shrubbery " << _name << std::endl;
}

void Shrubbery::action()
{
	std::ofstream file;
	file.open(_name.c_str());
	file << ASCII_TREE;
	file.close();
}

std::ostream& operator << (std::ostream &out, const Shrubbery &form)
{
	if (form.getCheck())
		out << " of grade ";
	else
		out << " of grade ";
	return (out);
}
