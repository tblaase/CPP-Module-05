/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 19:52:02 by tblaase           #+#    #+#             */
/*   Updated: 2022/04/04 21:34:06 by tblaase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

// Constructors
Form::Form(void): _name("default"), _is_signed(false), _sign_grade(150), _exec_grade(150)
{
	std::cout << "Form Default Constructor called" << std::endl;
}

Form::Form(const Form &src): _name(src.getName() + "_copy"), _is_signed(false), _sign_grade(src.getSignGrade()), _exec_grade(src.getExecGrade())
{
	std::cout << "Form Copy Constructor called to copy " << src.getName() <<
	" into " << this->getName() << std::endl;
	*this = src;
}

Form::Form(int sign_grade, int exec_grade): _name("default"), _is_signed(false), _sign_grade(sign_grade), _exec_grade(exec_grade)
{
	std::cout << "Form Constructor called for " << this->getName() <<
	" with sign-grade of " << sign_grade << " and execution-grade of " << exec_grade <<
	std::endl;
	const int i = this->getSignGrade();
	const int j = this->getExecGrade();
	if (i > 150 || j > 150)
		throw(Form::GradeTooHighException());
	else if( i < 1 || j < 1)
		throw(Form::GradeTooLowException());
}

Form::Form(const std::string name): _name(name), _is_signed(false), _sign_grade(150), _exec_grade(150)
{
	std::cout << "Form Constructor called for " << this->getName() <<
	" with sign-grade of " << this->getSignGrade() <<
	" and execution-grade of " << this->getExecGrade() << std::endl;
}

Form::Form(const std::string name, int sign_grade, int exec_grade): _name(name), _is_signed(false), _sign_grade(sign_grade), _exec_grade(exec_grade)
{
	std::cout << "Form Constructor called for " << this->getName() <<
	" with sign-grade of " << sign_grade << " and execution-grade of " << exec_grade <<
	std::endl;
	const int i = this->getSignGrade();
	const int j = this->getExecGrade();
	if (i > 150 || j > 150)
		throw(Form::GradeTooHighException());
	else if( i < 1 || j < 1)
		throw(Form::GradeTooLowException());
}

// Deconstructors
Form::~Form()
{
	std::cout << "Form Deconstructor for " << this->getName() << " called" << std::endl;
}

// Overloaded Operators
Form &Form::operator=(const Form &src)
{
	std::cout << "Form Assignation operator called" << std::endl;
	if (this == &src)
		return *this;

	//nothing to assign in this class
	return *this;
}

// Public Methods
void Form::beSigned(Bureaucrat &signer)
{
	if ((int)signer.getGrade() > this->getSignGrade())
		throw(Form::GradeTooLowException());
	else
		this->_is_signed = true;
}

// Getter
const std::string	Form::getName(void)const
{
	return (this->_name);
}

const std::string	Form::getIsSigned(void)const
{
	if (this->_is_signed)
		return ("true");
	else
		return ("false");
}

int	Form::getSignGrade(void)const
{
	return (this->_sign_grade);
}

int	Form::getExecGrade(void)const
{
	return (this->_exec_grade);
}

// Setter

// ostream Overload
std::ostream	&operator<<(std::ostream &o, Form *a)
{
	o << "Form " << a->getName() <<
	"\n\tsign-grade: " << a->getSignGrade() <<
	"\n\texecution-grade: " << a->getExecGrade() <<
	"\n\tis signed: " << a->getIsSigned() <<
	std::endl;
	return (o);
}

std::ostream	&operator<<(std::ostream &o, Form a)
{
	o << "Form " << a.getName() <<
	"\n\tsign-grade: " << a.getSignGrade() <<
	"\n\texecution-grade: " << a.getExecGrade() <<
	"\n\tis signed: " << a.getIsSigned() <<
	std::endl;
	return (o);
}
