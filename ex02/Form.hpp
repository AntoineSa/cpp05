/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asablayr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 10:36:57 by asablayr          #+#    #+#             */
/*   Updated: 2021/03/04 14:28:01 by asablayr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <string>
#include "Bureaucrat.hpp"

class Form
{
	public:
			Form(std::string name, unsigned int signRank, unsigned int exeRank);
			Form(Form const &);
//			Form& operator = (Form const &);
			virtual ~Form();

			std::string getName() const;
			unsigned int getSignRank() const;
			unsigned int getExeRank() const;
			bool getCheck() const;
			void setCheck();
			void beSigned(Bureaucrat const &);
			virtual void execute (Bureaucrat const &executor) const;

	protected:
			Form();
			class GradeTooLowException : public std::exception
			{
				const char* what() const throw() 
				{
					return "grade too low.\n";
				}
			};
			class GradeTooHighException : public std::exception
			{
				const char* what() const throw() 
				{
					return "grade too low.\n";
				}
			};
			class AlreadySignedException : public std::exception
			{
				const char* what() const throw() 
				{
					return "the form has already been signed.\n";
				}
			};
			class NotSignedException : public std::exception
			{
				const char* what() const throw() 
				{
					return "the form hasn't been signed yet.\n";
				}
			};
			class SignTooLowException : public std::exception
			{
				const char* what() const throw() 
				{
					return "grade is too low to sign form.\n";
				}
			};
			class ExeTooLowException : public std::exception
			{
				const char* what() const throw() 
				{
					return "grade is too low to execute form.\n";
				}
			};

	private:
			std::string const _name;
			bool _check;
			unsigned int const _signRank;
			unsigned int const _exeRank;
};

std::ostream& operator << (std::ostream &out, const Form &);

#endif
