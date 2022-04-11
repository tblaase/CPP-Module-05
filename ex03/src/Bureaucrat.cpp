/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 09:42:50 by tblaase           #+#    #+#             */
/*   Updated: 2022/04/11 11:49:58 by tblaase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

// Here the try catch statements are used because it just makes sense

// Constructors
Bureaucrat::Bureaucrat(void): _name("default"), _grade(150)
{
	std::cout << "Bureaucrat Default Constructor called for " << this->getName() <<
	" with grade of " << this->getGrade() << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src): _name(src.getName() + "_copy")
{
	std::cout << "Bureaucrat Copy Constructor called to copy " << src.getName() <<
	" into " << this->getName() << std::endl;
	*this = src;
}

Bureaucrat::Bureaucrat(int grade): _name("default")
{
	std::cout << "Bureaucrat Constructor called for " << this->getName() <<
	" with grade of " << grade << std::endl;
	try
	{
		this->setGrade(grade);
	}
	catch(Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << "\033[33mConstructing " << this->getName() <<
		" failed: " << e.what() << std::endl <<
		"Grade now set to 1" << "\033[0m" << std::endl;
		this->setGrade(1);
	}
	catch(Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << "\033[33mConstructing " << this->getName() <<
		" failed: " << e.what() << std::endl <<
		"Grade now set to 150" << "\033[0m" << std::endl;
		this->setGrade(150);
	}
}

Bureaucrat::Bureaucrat(const std::string name): _name(name), _grade(150)
{
	std::cout << "Bureaucrat Constructor called for " << this->getName() <<
	" with grade of " << this->getGrade() << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade): _name(name)
{
	std::cout << "Bureaucrat Constructor called for " << this->getName() <<
	" with grade of " << grade << std::endl;
	try
	{
		this->setGrade(grade);
	}
	catch(Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << "\033[33mConstructing " << this->getName() <<
		" failed: " << e.what() << std::endl <<
		"Grade now set to 1" << "\033[0m" << std::endl;
		this->setGrade(1);
	}
	catch(Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << "\033[33mConstructing " << this->getName() <<
		" failed: " << e.what() << std::endl <<
		"Grade now set to 150" << "\033[0m" << std::endl;
		this->setGrade(150);
	}

}

// Deconstructors
Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat Deconstructor for " << this->getName() << " called" << std::endl;
}

// Overloaded Operators
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src)
{
	std::cout << "Bureaucrat Assignation operator called" << std::endl;
	if (this == &src)
		return *this;

	this->_grade = src.getGrade();
	return *this;
}

// Public Methods
void	Bureaucrat::incrementGrade(void)
{
	try
	{
		std::cout << "Trying to increment grade of " << this->getName() << std::endl;
		this->setGrade(this->_grade - 1);
	}
	catch(Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << "\033[33mIncrementing grade of " << this->getName() <<
		" failed: " << e.what() << "\033[0m" << std::endl;
	}
}

void	Bureaucrat::decrementGrade(void)
{
	try
	{
		std::cout << "Trying to decrement grade of " << this->getName() << std::endl;
		this->setGrade(this->_grade + 1);
	}
	catch(Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << "\033[33mDecrementing grade of " << this->getName() <<
		" failed: " << e.what() << "\033[0m" << std::endl;
	}
}

void	Bureaucrat::signForm(Form &form)
{
		form.beSigned(*this);
}

void	Bureaucrat::executeForm(Form &form)const
{
		form.execute(*this);
}

// Getter
const std::string	Bureaucrat::getName(void)const
{
	return (this->_name);
}

size_t	Bureaucrat::getGrade(void)const
{
	return (this->_grade);
}

// Setter
void	Bureaucrat::setGrade(int grade)
{
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade = grade;
}

// Exceptions
const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low");
};

const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high");
};

// ostream Overload
std::ostream	&operator<<(std::ostream &o, Bureaucrat *a)
{
	o << "Bureaucrat " << a->getName() << ":\n\tgrade: " << a->getGrade() << std::endl;
	return (o);
}
