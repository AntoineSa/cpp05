/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asablayr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 11:43:26 by asablayr          #+#    #+#             */
/*   Updated: 2021/03/04 15:45:17 by asablayr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreation.hpp"
#include "RobotomyRequestForm.hpp"
#include <iostream>

int main()
{
	try {
		std::cout << "trying to create rank 0 bureaucrat\n";
		Bureaucrat supreme_leader("supreme_leader", 0);
	}
	catch (std::exception& e) {
		std::cout << e.what();
	}
	std::cout << std::endl;

	try {
		std::cout << "trying to create rank 151 bureaucrat\n";
		Bureaucrat lowlife("lowlife", 151);
	}
	catch (std::exception& e) {
		std::cout << e.what();
	}
	std::cout << std::endl;

	try {
		Bureaucrat peon("peon", 150);
		std::cout << peon;
		Form formA("Formulaire A", 3, 100);
		std::cout << formA;
		peon.signForm(formA);
		peon.executeForm(formA);
	}
	catch (std::exception& e) {
		std::cout << "error returned : "<< e.what();
	}
	std::cout << std::endl;

	try {
		Bureaucrat peon("peon", 150);
		std::cout << peon;
		Shrubbery shrubbery("shrubb");
		std::cout << shrubbery;
		peon.signForm(shrubbery);
		peon.executeForm(shrubbery);
	}
	catch (std::exception& e) {
		std::cout << "error returned : "<< e.what();
	}
	std::cout << std::endl;

	try {
		Bureaucrat leader("leader", 1);
		std::cout << leader;
		Shrubbery shrubbery("shrubb");
		std::cout << shrubbery;
		leader.signForm(shrubbery);
		leader.executeForm(shrubbery);
	}
	catch (std::exception& e) {
		std::cout << "error returned : "<< e.what();
	}	
	std::cout << std::endl;

	try {
		Bureaucrat leader("leader", 1);
		std::cout << leader;
		PresidentialPardonForm presidential_pardon("presidential request");
		std::cout << presidential_pardon;
		leader.signForm(presidential_pardon);
		leader.executeForm(presidential_pardon);
	}
	catch (std::exception& e) {
		std::cout << "error returned : "<< e.what();
	}	
	std::cout << std::endl;

	try {
		Bureaucrat leader("New leader", 4);
		std::cout << leader;
		RobotomyRequestForm robotomy_request("express robotomy request");
		std::cout << robotomy_request;
		leader.signForm(robotomy_request);
		leader.executeForm(robotomy_request);
	}
	catch (std::exception& e) {
		std::cout << "error returned : "<< e.what();
	}	
	std::cout << std::endl;
	return 0;
}
