/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 15:28:09 by tblaase           #+#    #+#             */
/*   Updated: 2022/04/06 15:28:19 by tblaase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"


// Constructors
RobotomyRequestForm::RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm Default Constructor called" << std::endl;
	/*CODE*/
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src)
{
	std::cout << "RobotomyRequestForm Copy Constructor called" << std::endl;
	*this = src;
}

// Deconstructors
RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm Deconstructor called" << std::endl;
	/*CODE*/
}

// Overloaded Operators
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
	std::cout << "RobotomyRequestForm Assignation operator called" << std::endl;
	if (this == &src)
		return *this;

	/*CODE*/
	return *this;
}

// Public Methods

// Getter

// Setter

