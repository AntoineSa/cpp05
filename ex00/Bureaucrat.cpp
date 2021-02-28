/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asablayr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 10:49:11 by asablayr          #+#    #+#             */
/*   Updated: 2021/02/24 12:48:46 by asablayr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat(std::string const& name, unsigned int grade): _name(name), _grade(grade)
{
	if (_grade < TOP_RANK)
		throw GradeTooHighException();
	if (_grade > BOT_RANK)
		throw GradeTooHighException();
	std::cout << "naissance d'un bureacrate\n";
}

Bureaucrat::Bureaucrat(Bureaucrat const& copy): _name(copy.getName()), _grade(copy.getGrade())
{
	std::cout << "naissance par copie d'un bureaucrate\n";
}

Bureaucrat& Bureaucrat::operator = (Bureaucrat const & copy)
{
	_grade = copy.getGrade();
	std::cout << "copy d'un bureaucrate\n";
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "destruction du bureaucrate " << _name << std::endl;
}

void Bureaucrat::incrementGrade()
{
	try
	{
		std::cout << _name << " is trying to move up a rank\n";
		if (_grade - 1> BOT_RANK)
			throw GradeTooLowException();
		else if (_grade - 1< TOP_RANK)
			throw GradeTooHighException();
		else
		{
			_grade --;
			std::cout << _name << " has moved up a rank\n";
		}
	}
	catch (std::exception& e)
	{
		std::cout << e.what();
		return ;
	}
}

void Bureaucrat::decrementGrade()
{
	try
	{
		std::cout << _name << " is trying to move down a rank\n";
		if (_grade + 1 > BOT_RANK)
			throw GradeTooLowException();
		else if (_grade  + 1< TOP_RANK)
			throw GradeTooHighException();
		else
		{
			_grade ++;
			std::cout << _name << " has moved down a rank\n";
		}
	}
	catch (std::exception& e)
	{
		std::cout << e.what();
		return ;
	}
}

int Bureaucrat::getGrade() const
{
	return (_grade);
}

std::string const &Bureaucrat::getName() const
{
	return (_name);
}

std::ostream& operator << (std::ostream &out, const Bureaucrat &bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << std::endl;
	return (out);
}
