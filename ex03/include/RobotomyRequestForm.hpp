/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 15:27:48 by tblaase           #+#    #+#             */
/*   Updated: 2022/04/11 11:58:01 by tblaase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Header-protection
#pragma once

// Includes
#include <string>
#include <iostream>
#include <cstdlib>
#include "Bureaucrat.hpp"
#include "Form.hpp"

// classes

class Bureaucrat;

class From;

class RobotomyRequestForm: public Form
{
	private:
		const std::string _target;
	// moved the default Constructor to private because subject asks for orthodox canonical form
	// but also asks for the Forms to only have one constructor that takes one argument
		RobotomyRequestForm(void);
	public:
	// Constructors
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(RobotomyRequestForm &src);

	// Deconstructors
		~RobotomyRequestForm();

	// Overloaded Operators
		RobotomyRequestForm &operator=(const RobotomyRequestForm &src);

	// Public Methods
		void execute(Bureaucrat const &executor)const;
	// Getter
		std::string getTarget(void)const;
	// Setter

};

// // ostream Overload
std::ostream	&operator<<(std::ostream &o, RobotomyRequestForm *a);
