/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 15:27:24 by tblaase           #+#    #+#             */
/*   Updated: 2022/04/06 16:14:01 by tblaase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Header-protection
#pragma once

// Includes
#include <string>
#include <iostream>
#include "Form.hpp"

// classes

class From;

class PresidentialPardonForm: public Form
{
	private:
		// Private Members

	public:
	// Constructors
		PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm &src);

	// Deconstructors
		~PresidentialPardonForm();

	// Overloaded Operators
		PresidentialPardonForm &operator=(const PresidentialPardonForm &src);

	// Public Methods
		void execute(Bureaucrat const &executor)const;
	// Getter

	// Setter

};

// // ostream Overload
std::ostream	&operator<<(std::ostream &o, PresidentialPardonForm *a);
std::ostream	&operator<<(std::ostream &o, PresidentialPardonForm a);