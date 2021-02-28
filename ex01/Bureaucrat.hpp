/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asablayr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 10:36:57 by asablayr          #+#    #+#             */
/*   Updated: 2021/02/24 12:26:43 by asablayr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>

#define TOP_RANK 1
#define BOT_RANK 150

class Form;

class Bureaucrat
{
	public:
			Bureaucrat(std::string const &name, unsigned int grade);
			Bureaucrat(Bureaucrat const &);
			Bureaucrat& operator = (Bureaucrat const &);
			~Bureaucrat();

			class GradeTooLowException : public std::exception
			{
				const char* what() const throw() 
				{
					return "err: Rank too low.\n";
				}
			};
			class GradeTooHighException : public std::exception
			{
				const char* what() const throw() 
				{
					return "err: Rank too high.\n";
				}
			};

			std::string const &getName() const;
			unsigned int getGrade() const;
			void incrementGrade();
			void decrementGrade();
			void signForm(Form & form) const;

	private:
			std::string const& _name;
			unsigned int _grade;
};

std::ostream& operator << (std::ostream &out, const Bureaucrat &);

#endif
