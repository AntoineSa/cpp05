/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asablayr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 10:36:57 by asablayr          #+#    #+#             */
/*   Updated: 2021/03/04 10:29:04 by asablayr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include <string>
#include <fstream>
#include "Form.hpp"

class RobotomyRequestForm : public Form
{
	public:
			RobotomyRequestForm(std::string name);
			RobotomyRequestForm(RobotomyRequestForm const &);
			RobotomyRequestForm& operator = (RobotomyRequestForm const &);
			~RobotomyRequestForm();

			virtual void execute(Bureaucrat const& executor) const;

	private:
};

#endif
