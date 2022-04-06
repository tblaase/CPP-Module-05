/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 15:28:00 by tblaase           #+#    #+#             */
/*   Updated: 2022/04/06 15:28:07 by tblaase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"


// Constructors
PresidentialPardonForm::PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm Default Constructor called" << std::endl;
	/*CODE*/
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src)
{
	std::cout << "PresidentialPardonForm Copy Constructor called" << std::endl;
	*this = src;
}

// Deconstructors
PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm Deconstructor called" << std::endl;
	/*CODE*/
}

// Overloaded Operators
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &src)
{
	std::cout << "PresidentialPardonForm Assignation operator called" << std::endl;
	if (this == &src)
		return *this;

	/*CODE*/
	return *this;
}

// Public Methods

// Getter

// Setter

