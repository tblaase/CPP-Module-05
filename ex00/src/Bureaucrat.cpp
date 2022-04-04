/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 09:42:50 by tblaase           #+#    #+#             */
/*   Updated: 2022/04/04 14:34:11 by tblaase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"


// Constructors
Bureaucrat::Bureaucrat(): _name("default"), _grade(150)
{
	std::cout << "Bureaucrat Default Constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy)
{
	std::cout << "Bureaucrat Copy Constructor called" << std::endl;
	*this = copy;
}

Bureaucrat::Bureaucrat(const size_t grade): _name("default")
{
	try
	{
		this->setGrade(grade);
	}
	catch(GradeTooHighException &e)
	{
		std::cerr << "\033[33mConstructing " << this->getName() << " failed: " << e.what() << std::endl <<
		"Grade now set to 150" << "\033[0m" << std::endl;
		this->setGrade(150);
	}
	catch(GradeTooLowException &e)
	{
		std::cerr << "\033[33mConstructing " << this->getName() << " failed: " << e.what() << std::endl <<
		"Grade now set to 150" << "\033[0m" << std::endl;
		this->setGrade(150);
	}
}

Bureaucrat::Bureaucrat(const std::string name): _name(name), _grade(150)
{
}

Bureaucrat::Bureaucrat(const std::string name, const size_t grade): _name(name)
{
	try
	{
		this->setGrade(grade);
	}
	catch(GradeTooHighException &e)
	{
		std::cerr << "\033[33mConstructing " << this->getName() << " failed: " << e.what() << std::endl <<
		"Grade now set to 150" << "\033[0m" << std::endl;
		this->setGrade(150);
	}
	catch(GradeTooLowException &e)
	{
		std::cerr << "\033[33mConstructing " << this->getName() << " failed: " << e.what() << std::endl <<
		"Grade now set to 150" << "\033[0m" << std::endl;
		this->setGrade(150);
	}

}

// Deconstructors
Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat Deconstructor called" << std::endl;
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
		this->setGrade(this->_grade + 1);
	}
	catch(GradeTooHighException &e)
	{
		std::cerr << "\033[33mIncrementing grade of " << this->getName() << " failed: " << e.what() << "\033[0m" << std::endl;
	}
}

void	Bureaucrat::decrementGrade(void)
{
	try
	{
		this->setGrade(this->_grade - 1);
	}
	catch(GradeTooLowException &e)
	{
		std::cerr << "\033[33mDecrementing grade of " << this->getName() << " failed: " << e.what() << "\033[0m" << std::endl;
	}
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
void	Bureaucrat::setGrade(size_t grade)
{
	if (grade > 150)
		throw Bureaucrat::GradeTooHighException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooLowException();
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
	o << "Bureaucrat " << a->getName() << " has the grade " << a->getGrade() << std::endl;
	return (o);
}
