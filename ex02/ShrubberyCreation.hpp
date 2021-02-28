/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreation.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asablayr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 10:36:57 by asablayr          #+#    #+#             */
/*   Updated: 2021/02/24 19:40:50 by asablayr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERY_HPP
# define SHRUBBERY_HPP

#include <string>
#include <fstream>
#include "Form.hpp"

#define ASCII_TREE "-|-"
#define BOT_RANK 150

class Shrubbery : public Form
{
	public:
			Shrubbery(std::string const &name);
			Shrubbery(Shrubbery const &);
			Shrubbery& operator = (Shrubbery const &);
			~Shrubbery();

			void action();

	private:
};

std::ostream& operator << (std::ostream &out, const Shrubbery &);

#endif
