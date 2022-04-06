/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 15:27:48 by tblaase           #+#    #+#             */
/*   Updated: 2022/04/06 15:50:52 by tblaase          ###   ########.fr       */
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

class RobotomyRequestForm: public Form
{
	private:
		// Private Members

	public:
	// Constructors
		RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm &src);

	// Deconstructors
		~RobotomyRequestForm();

	// Overloaded Operators
		RobotomyRequestForm &operator=(const RobotomyRequestForm &src);

	// Public Methods

	// Getter

	// Setter

};