/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreation.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asablayr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 10:36:57 by asablayr          #+#    #+#             */
/*   Updated: 2021/03/04 14:14:27 by asablayr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERY_HPP
# define SHRUBBERY_HPP

#include <string>
#include <fstream>
#include "Form.hpp"

#define ASCII_TREE "                                                         .\n                                              .         ;\n                 .              .              ;%     ;;\n                   ,           ,                :;%  %;\n                    :         ;                   :;%;'     .,\n           ,.        %;     %;            ;        %;'    ,;\n             ;       ;%;  %%;        ,     %;    ;%;    ,%'\n              %;       %;%;      ,  ;       %;  ;%;   ,%;'\n               ;%;      %;        ;%;        % ;%;  ,%;'\n                `%;.     ;%;     %;'         `;%%;.%;'\n                 `:;%.    ;%%. %@;        %; ;@%;%'\n                    `:%;.  :;bd%;          %;@%;'\n                      `@%:.  :;%.         ;@@%;'\n                        `@%.  `;@%.      ;@@%;\n                          `@%%. `@%%    ;@@%;\n                            ;@%. :@%%  %@@%;\n                              %@bd%%%bd%%:;\n                                #@%%%%%:;;\n                                %@@%%%::;\n                                %@@@%(o);  . '\n                                %@@@o%;:(.,'\n                            `.. %@@@o%::;\n                               `)@@@o%::;\n                                %@@(o)::;\n                               .%@@@@%::;\n                               ;%@@@@%::;.\n                              ;%@@@@%%:;;;.\n                          ...;%@@@@@%%:;;;;,.."

#define BOT_RANK 150

class Shrubbery : public Form
{
	public:
			Shrubbery(std::string name);
			Shrubbery(Shrubbery const &);
			Shrubbery& operator = (Shrubbery const &);
			~Shrubbery();

			virtual void execute(Bureaucrat const &executor) const;

	private:
};

#endif
