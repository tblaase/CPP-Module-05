/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 15:27:53 by tblaase           #+#    #+#             */
/*   Updated: 2022/04/06 15:42:05 by tblaase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Header-protection
#pragma once

// Includes
#include <string>
#include <iostream>
#include "Form.hpp"

// classes

class Form;

class ShrubberyCreationForm: public Form
{
	private:
		// Private Members

	public:
	// Constructors
		ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm &src);

	// Deconstructors
		~ShrubberyCreationForm();

	// Overloaded Operators
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &src);

	// Public Methods

	// Getter

	// Setter

};