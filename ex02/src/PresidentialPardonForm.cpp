/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 15:28:00 by tblaase           #+#    #+#             */
/*   Updated: 2022/04/06 16:20:24 by tblaase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"


// Constructors
PresidentialPardonForm::PresidentialPardonForm():Form("PresidentialPardonForm", 1, 1)
{
	std::cout << "PresidentialPardonForm Default Constructor called" << std::endl;
	/*CODE*/
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src):Form()
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
void	PresidentialPardonForm::execute(Bureaucrat const &executor)const
{
	std::cout << "executed by " << executor.getName() << std::endl;
}
// Getter

// Setter

// ostream Overload
std::ostream	&operator<<(std::ostream &o, PresidentialPardonForm *a)
{
	o << "Form " << a->getName() <<
	":\n\tsign-grade:\t" << a->getSignGrade() <<
	"\n\texec-grade:\t" << a->getExecGrade() <<
	"\n\tis signed:\t" << a->getIsSigned() <<
	std::endl;
	return (o);
}

std::ostream	&operator<<(std::ostream &o, PresidentialPardonForm a)
{
	o << "Form " << a.getName() <<
	":\n\tsign-grade:\t" << a.getSignGrade() <<
	"\n\texec-grade:\t" << a.getExecGrade() <<
	"\n\tis signed:\t" << a.getIsSigned() <<
	std::endl;
	return (o);
}
