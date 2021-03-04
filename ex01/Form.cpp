/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asablayr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 10:49:11 by asablayr          #+#    #+#             */
/*   Updated: 2021/03/04 14:37:13 by asablayr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include <iostream>

Form::Form(std::string const& name, unsigned int signRank, unsigned int exeRank): 
	_name(name), _check(false), 
	_signRank(signRank), _exeRank(exeRank)
{
	if (_signRank < TOP_RANK || _signRank < TOP_RANK)
		throw GradeTooLowException();
	else if (_exeRank > BOT_RANK || _exeRank > BOT_RANK)
		throw GradeTooHighException();
	std::cout << "naissance d'un formulaire\n";
}

Form::Form(Form const& copy): _name(copy.getName()), _signRank(copy.getSignRank()), _exeRank(copy.getExeRank())
{
	std::cout << "naissance par copie d'un formulaire\n";
}

Form& Form::operator = (Form const & copy)
{
	_check = copy.getCheck();
	std::cout << "copy d'un formulaire\n";
	return (*this);
}

Form::~Form()
{
	std::cout << "destruction du bureaucrate " << _name << std::endl;
}

void Form::beSigned(Bureaucrat const &bureaucrat)
{
	std::cout << bureaucrat.getName() << " is trying to sign the form : " << _name << std::endl;
	if (_check == true)
		throw AlreadySigned();
	if (bureaucrat.getGrade() > _signRank)
		throw GradeTooLowException();
	else
	{
		_check = true;
		std::cout << bureaucrat.getName() << " has signed the form\n";
	}
}

unsigned int Form::getSignRank() const
{
	return (_signRank);
}

unsigned int Form::getExeRank() const
{
	return (_exeRank);
}

bool Form::getCheck() const
{
	return (_check);
}

std::string const &Form::getName() const
{
	return (_name);
}

std::ostream& operator << (std::ostream &out, const Form &form)
{
	if (form.getCheck())
		out << form.getName() << " of grade " << form.getSignRank() << " has been signed.\n";
	else
		out << form.getName() << " of grade " << form.getSignRank() << " hasn't been signed.\n";
	return (out);
}
