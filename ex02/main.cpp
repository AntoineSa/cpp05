/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asablayr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 11:43:26 by asablayr          #+#    #+#             */
/*   Updated: 2021/02/24 12:35:18 by asablayr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
	Bureaucrat leader("leader", 1);
	try {
		std::cout << "trying to create rank 0 bureaucrat\n";
		Bureaucrat supreme_leader("supreme_leader", 0);
	}
	catch (std::exception& e) {
		std::cout << e.what();
	}	
	try {
		std::cout << "trying to create rank 150 bureaucrat\n";
		Bureaucrat lowlife("lowlife", 151);
	}
	catch (std::exception& e) {
		std::cout << e.what();
	}	
	Bureaucrat peon("peon", 150);
	Form formA("Formulaire A", 3);
	Form formB("Formulaire B", 149);
	
	std::cout << std::endl;
	std::cout << leader;
	leader.decrementGrade();
	leader.incrementGrade();
	leader.incrementGrade();
	std::cout << leader;
	std::cout << std::endl;
	std::cout << peon;
	peon.incrementGrade();
	peon.decrementGrade();
	peon.decrementGrade();
	std::cout << peon;
	std::cout << std::endl;
	std::cout << formA;
	std::cout << formB;
	std::cout << std::endl;
	leader.signForm(formA);
	leader.signForm(formB);
	peon.signForm(formA);
	peon.signForm(formB);
	std::cout << std::endl;
	return 0;
}
