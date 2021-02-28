/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asablayr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 10:36:57 by asablayr          #+#    #+#             */
/*   Updated: 2021/02/24 19:11:13 by asablayr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include <string>
#include <fstream>
#include "Form.hpp"

#define ASCII_TREE "-|-"

class RobotomyRequestForm : public Form
{
	public:
			RobotomyRequestForm(std::string const &name);
			RobotomyRequestForm(RobotomyRequestForm const &);
			RobotomyRequestForm& operator = (RobotomyRequestForm const &);
			~RobotomyRequestForm();

			void action();

	private:
};

std::ostream& operator << (std::ostream &out, const RobotomyRequestForm &);

#endif
