/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 15:28:09 by tblaase           #+#    #+#             */
/*   Updated: 2022/04/06 19:53:59 by tblaase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

// Constructors
RobotomyRequestForm::RobotomyRequestForm(): Form("RobotomyRequestForm", 72, 45), _target("default")
{
	std::cout << "RobotomyRequestForm Default Constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): Form("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout << "RobotomyRequestForm Constructor for taget " << this->getTarget() << " called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &src): Form("RobotomyRequestForm", 72, 45), _target(src.getTarget())
{
	std::cout << "RobotomyRequestForm Copy Constructor called to copy " << src.getName() <<
	" into " << this->getName() << std::endl;

	*this = src;
}

// Deconstructors
RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm Deconstructor " << this->getName() << " called" << std::endl;
}

// Overloaded Operators
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
	std::cout << "RobotomyRequestForm Assignation operator called" << std::endl;
	if (this == &src)
		return *this;
	//nothing to assign in this class, all constants
	return *this;
}

// Public Methods
void	RobotomyRequestForm::execute(Bureaucrat const &executor)const
{
	if ((int)executor.getGrade() > this->getExecGrade())
		throw (Form::GradeTooLowException());
	else if (this->getIsSignedBool() == false)
		std::cout << this->getName() << " needs to be signed before executing it" << std::endl;
	else if (rand() % 2)
		std::cout << "BRRRRRRRRRRRRRR\n" << this->getTarget() << " was robotomized" << std::endl;
	else
		std::cout << "Robotomy failed" << std::endl;
}

// Getter
std::string	RobotomyRequestForm::getTarget(void)const
{
	return (this->_target);
}

// Setter

// ostream Overload
std::ostream	&operator<<(std::ostream &o, RobotomyRequestForm *a)
{
	o << "Form " << a->getName() <<
	":\n\tsign-grade:\t" << a->getSignGrade() <<
	"\n\texec-grade:\t" << a->getExecGrade() <<
	"\n\tis signed:\t" << a->getIsSigned() <<
	std::endl;
	return (o);
}

// std::ostream	&operator<<(std::ostream &o, RobotomyRequestForm a)
// {
// 	o << "Form " << a.getName() <<
// 	":\n\tsign-grade:\t" << a.getSignGrade() <<
// 	"\n\texec-grade:\t" << a.getExecGrade() <<
// 	"\n\tis signed:\t" << a.getIsSigned() <<
// 	std::endl;
// 	return (o);
// }