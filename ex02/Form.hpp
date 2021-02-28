/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asablayr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 10:36:57 by asablayr          #+#    #+#             */
/*   Updated: 2021/02/24 15:28:50 by asablayr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <string>
#include "Bureaucrat.hpp"

class Form
{
	public:
			Form(std::string const &name, unsigned int signRank, unsigned int exeRank);
			Form(Form const &);
			Form& operator = (Form const &);
			~Form();

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
					return "grade high low.\n";
				}
			};
			class AlreadySigned : public std::exception
			{
				const char* what() const throw() 
				{
					return "the form has already been signed.\n";
				}
			};

			std::string const &getName() const;
			unsigned int getSignRank() const;
			unsigned int getExeRank() const;
			bool getCheck() const;
			void beSigned(Bureaucrat const &);

	protected:
			std::string const& _name;
			bool _check;
			unsigned int const _signRank;
			unsigned int const _exeRank;
};

std::ostream& operator << (std::ostream &out, const Form &);

#endif
