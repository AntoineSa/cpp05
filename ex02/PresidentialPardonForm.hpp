/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asablayr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 10:36:57 by asablayr          #+#    #+#             */
/*   Updated: 2021/03/04 14:13:31 by asablayr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include <string>
#include <fstream>
#include "Form.hpp"

class PresidentialPardonForm : public Form
{
	public:
			PresidentialPardonForm(std::string name);
			PresidentialPardonForm(PresidentialPardonForm const &);
			PresidentialPardonForm& operator = (PresidentialPardonForm const &);
			~PresidentialPardonForm();

			virtual void execute(Bureaucrat const &executor) const;

	private:
};

#endif
