/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfalkau <lfalkau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 06:01:48 by lfalkau           #+#    #+#             */
/*   Updated: 2021/03/04 14:46:40 by asablayr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include <iostream>

// Constructors && Destructor

Form::Form(std::string name, unsigned int rqs, unsigned int rqe) : _name(name),  _signRank(rqs), _exeRank(rqe)
{
	if (rqs < 1 || rqe < 1)
		throw GradeTooHighException();
	if (rqs > 150 || rqe > 150)
		throw GradeTooLowException();
	std::cout << "Form '" << _name << "' created\n";
}

Form::Form(Form const &copied) : _name(copied._name), _signRank(copied._signRank), _exeRank(copied._exeRank)
{
	std::cout << "Form '" << _name << "' created by copy\n";
}

Form::~Form()
{
	std::cout << "Form '" << _name << "' shredded and destroyed\n";
}

// Methods

std::string Form::getName() const
{
	return (_name);
}

bool Form::getCheck() const
{
	return (_check);
}

void Form::setCheck()
{
	if (!_check)
		_check = true;
	else
		throw AlreadySignedException();
}

unsigned int Form::getSignRank() const
{
	return (_signRank);
}

unsigned int Form::getExeRank() const
{
	return (_exeRank);
}

void Form::beSigned(Bureaucrat const &bureaucrat)
{
	if (bureaucrat.getGrade() > _signRank)
		throw Form::SignTooLowException();
	else if (_check)
		throw AlreadySignedException();
	else
		_check = true;
}

void Form::execute(Bureaucrat const &executor) const
{
	if (_check == false)
		throw Form::NotSignedException();
	else if (executor.getGrade() > getExeRank())
		throw Form::ExeTooLowException();
}

// External stream overload

std::ostream& operator << (std::ostream &out,const Form& form)
{
	if (form.getCheck() == true)
		out << "Form " << form.getName() << " is signed.\n";
	else
		out << "Form " << form.getName() << " isn't signed. Minimal grade to sign: " << form.getSignRank() << " Minimal grade to exec: " << form.getExeRank() << ".\n";
	return (out);
}
