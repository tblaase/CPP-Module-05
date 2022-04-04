/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 19:43:07 by tblaase           #+#    #+#             */
/*   Updated: 2022/04/04 21:32:56 by tblaase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Header-protection
#pragma once

// Includes
#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

// classes

class Form
{
	private:
		const std::string _name;
		bool _is_signed;
		const int _sign_grade;
		const int _exec_grade;

	public:
	// Constructors
		Form(void);
		Form(const Form &src);
		Form(int sign_grade, int exec_grade);
		Form(const std::string name);
		Form(const std::string name, int sign_grade, int exec_grade);

	// Deconstructors
		~Form();

	// Overloaded Operators
		Form &operator=(const Form &src);

	// Public Methods
		void beSigned(Bureaucrat &signer);
	// Getter
		const std::string getName(void)const;
		const std::string getIsSigned(void)const;
		int getSignGrade(void)const;
		int getExecGrade(void)const;

	//Exceptions
	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
};

// ostream Overload
std::ostream	&operator<<(std::ostream &o, Form *a);
std::ostream	&operator<<(std::ostream &o, Form a);
