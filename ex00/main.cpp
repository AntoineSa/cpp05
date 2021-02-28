/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asablayr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 11:43:26 by asablayr          #+#    #+#             */
/*   Updated: 2021/02/24 12:48:35 by asablayr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "iostream"

int main()
{
	try {
		Bureaucrat leader("leader", 0);
	}
	catch (std::exception& e)
	{
		std::cout << e.what();
	}
	Bureaucrat leader("leader", 1);
	try {
		Bureaucrat peon("peon", 151);
	}
	catch (std::exception& e)
	{
		std::cout << e.what();
	}
	Bureaucrat peon("peon", 150);
	
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
	return 0;
}
