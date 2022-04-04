/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 10:30:36 by tblaase           #+#    #+#             */
/*   Updated: 2022/04/04 16:38:04 by tblaase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	{
		std::cout << "\033[34mConstructing\033[0m" << std::endl;
		Bureaucrat *a = new Bureaucrat();
		std::cout << std::endl;
		std::cout << "\033[34mTesting\033[0m" << std::endl;
		std::cout << a;
		a->incrementGrade();
		std::cout << a;
		a->decrementGrade();
		std::cout << a;
		std::cout << std::endl;
		std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
		delete a;
		std::cout << std::endl;
	}
	std::cout << "-------------------------------------------------------" << std::endl;
	{
		std::cout << "\033[34mConstructing\033[0m" << std::endl;
		Bureaucrat *a = new Bureaucrat(1);
		std::cout << std::endl;
		std::cout << "\033[34mTesting\033[0m" << std::endl;
		std::cout << a;
		a->decrementGrade();
		std::cout << a;
		a->incrementGrade();
		std::cout << a;
		std::cout << std::endl;
		std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
		delete a;
		std::cout << std::endl;
	}
	std::cout << "-------------------------------------------------------" << std::endl;
	{
		std::cout << "\033[34mConstructing\033[0m" << std::endl;
		Bureaucrat *a = new Bureaucrat(0);
		std::cout << std::endl;
		std::cout << "\033[34mTesting\033[0m" << std::endl;
		std::cout << a;
		a->decrementGrade();
		std::cout << a;
		a->incrementGrade();
		std::cout << a;
		std::cout << std::endl;
		std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
		delete a;
		std::cout << std::endl;
	}
	std::cout << "-------------------------------------------------------" << std::endl;
	{
		std::cout << "\033[34mConstructing\033[0m" << std::endl;
		Bureaucrat *a = new Bureaucrat(160);
		std::cout << std::endl;
		std::cout << "\033[34mTesting\033[0m" << std::endl;
		std::cout << a;
		a->decrementGrade();
		std::cout << a;
		a->incrementGrade();
		std::cout << a;
		std::cout << std::endl;
		std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
		delete a;
		std::cout << std::endl;
	}
	std::cout << "-------------------------------------------------------" << std::endl;
	{
		std::cout << std::endl;
		std::cout << "\033[34mConstructing\033[0m" << std::endl;
		Bureaucrat *a = new Bureaucrat("Peter", -200);
		std::cout << std::endl;
		std::cout << "\033[34mTesting a\033[0m" << std::endl;
		std::cout << a;
		a->decrementGrade();
		std::cout << a;
		std::cout << std::endl;
		std::cout << "\033[34mConstructing b\033[0m" << std::endl;
		Bureaucrat *b = new Bureaucrat(*a);
		std::cout << std::endl;
		std::cout << "\033[34mDeconstructing a\033[0m" << std::endl;
		delete a;
		std::cout << std::endl;
		std::cout << "\033[34mTesting b\033[0m" << std::endl;
		std::cout << b;
		b->decrementGrade();
		std::cout << b;
		std::cout << std::endl;
		std::cout << "\033[34mDeconstructing b\033[0m" << std::endl;
		delete b;
		std::cout << std::endl;
	}
}