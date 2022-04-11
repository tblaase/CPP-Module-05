/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 19:43:07 by tblaase           #+#    #+#             */
/*   Updated: 2022/04/11 12:51:08 by tblaase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Header-protection
#pragma once

// Includes
#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

// classes

class Bureaucrat;

class Form
{
	protected:
		const std::string _name;
		bool _is_signed;
		const int _sign_grade;
		const int _exec_grade;

		// Constructors
		Form(void);
		Form(int sign_grade, int exec_grade);
		Form(const std::string name);
		Form(const std::string name, int sign_grade, int exec_grade);

	public:
	// Copy Constructor
		Form(const Form &src);

	// Deconstructors
		virtual ~Form();

	// Overloaded Operators
		Form &operator=(const Form &src);
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

	class FormNotSignedException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

	// Public Methods
		void beSigned(Bureaucrat const &signer);
		virtual void execute(Bureaucrat const &executor)const = 0;
	// Getter
		const std::string getName(void)const;
		const std::string getIsSigned(void)const;
		bool getIsSignedBool(void)const;
		int getSignGrade(void)const;
		int getExecGrade(void)const;
};

// ostream Overload
std::ostream	&operator<<(std::ostream &o, Form *a);
