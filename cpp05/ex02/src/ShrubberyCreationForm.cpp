/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 10:39:31 by dde-carv          #+#    #+#             */
/*   Updated: 2025/10/09 14:32:45 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

/************ Constructors and Destructor ************/

ShrubberyCreationForm::ShrubberyCreationForm()
 : AForm("Default", "Default", 145, 137)
{
	std::cout << GREEN << "ShrubberyCreationForm default constructor called." << std::endl << RST;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
 : AForm("RobotomyRequestForm", target, 145, 137)
{
	std::cout << GREEN << "ShrubberyCreationForm custom constructor called." << std::endl << RST;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
 : AForm(other._name, other._target, other._gradeToSign, other._gradeToExec)
{
	std::cout << GREEN << "ShrubberyCreationForm copy constructor called." << std::endl << RST;
	*this = other;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other && other.getSigned() == true)
		_signed = other._signed;
	std::cout << YELLOW << "ShrubberyCreationForm copy assignment operator called." << std::endl << RST;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << RED << "ShrubberyCreationForm destructor called." << std::endl << RST;
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor)
{
	std::cout << BLUE << "The Bureaucrat " << executor.getName() \
	 << " planted a Shrubbery tree at " << _target << "!" << std::endl << RST;
	std::string fileName = _target + "_shrubbery";
	std::ofstream outFile(fileName.c_str(), std::fstream::trunc);
	if (!outFile.is_open() || outFile.fail())
		std::cout << RED << "Error opening file " << fileName << " in ShrubberyCreationForm!" << std::endl << RST;
	outFile << std::endl \
	 << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣤⣤⣦⣤⣤⣄⣀⣀⣀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n" \
	 << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣼⠟⡍⢆⡱⠌⢥⠋⡝⣩⢋⠛⡿⣦⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n" \
	 << "⠀⠀⠀⠀⠀⠀⠀⢀⣤⣴⣶⠾⢏⡜⠰⡡⢆⠹⡠⢋⠔⡢⢌⠓⡤⢛⣷⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n" \
	 << "⠀⠀⠀⠀⠀⢀⣾⠟⣩⠒⢤⡉⠦⢌⠣⡑⠬⣑⠢⢍⡒⠥⢊⡑⢆⠣⢿⡷⢶⣤⡀⠀⠀⠀⠀⠀⠀\n" \
	 << "⠀⠀⠀⠀⠀⢸⡟⡘⢤⡉⠦⣘⠡⢎⡡⢍⠲⢄⡋⠴⡘⠬⡑⡌⢎⠒⡅⢎⢢⡙⣷⡀⠀⠀⠀⠀⠀\n" \
	 << "⠀⠀⠀⠀⣠⣼⡿⠘⣄⠸⢃⡄⡛⠤⣀⠇⠼⢠⡘⢣⡘⢣⠸⢠⠜⢣⠸⢄⣃⠸⣻⣇⠀⠀⠀⠀⠀\n" \
	 << "⠀⢀⣴⡿⢋⡕⢢⡙⠤⣉⠖⡰⢉⡒⡡⢎⢡⢃⠬⡡⠜⡡⢎⠡⢎⡡⠚⢤⢂⡓⣘⠛⠿⣶⣄⠀⠀\n" \
	 << "⠀⣾⢏⡰⢃⠜⡰⢌⡒⡡⠎⡔⠣⣌⠱⢌⢢⡉⠦⣑⢡⠣⢌⡃⠦⣑⠩⡒⠬⡰⢡⡉⢖⡰⢹⣷⠀\n" \
	 << "⠸⣿⢂⠦⣉⠲⠡⢆⡑⢆⠓⠬⡑⠤⠓⡌⢆⠜⡡⢆⠣⠜⢢⠜⡡⢆⠣⢅⡓⡰⢡⢊⡒⢌⠆⣿⡇\n" \
	 << "⠀⠻⣧⡒⡡⢎⡑⢎⠰⡊⢍⡒⢩⠜⣵⡘⠬⡘⡔⢊⡌⢣⣃⡜⢰⢊⠱⡌⠴⣁⠣⢆⡉⠖⣸⡿⠀\n" \
	 << "⠀⢰⡿⢡⡑⠦⡘⡌⡱⢘⢢⢉⠖⣸⣿⣿⣦⡱⠌⣥⣼⣾⣿⢃⠣⡌⢣⢘⠒⡌⡱⢂⣭⣾⠟⠁⠀\n" \
	 << "⠀⢸⣷⠡⠜⢢⠱⣌⡑⠎⡤⢃⢮⣿⣿⣿⣿⡟⡿⣿⣿⣿⣿⡌⡱⢌⣑⣊⠱⣘⠰⢃⣿⡇⠀⠀⠀\n" \
	 << "⠀⠀⠻⣷⣭⣆⣣⠛⠿⣿⣶⠿⣿⣟⢿⣿⣿⡟⡜⣿⣿⣿⡿⠿⣿⡿⡛⣃⢣⣼⣦⣷⠟⠁⠀⠀⠀\n" \
	 << "⠀⠀⠀⠀⠉⠉⠻⢿⣴⣢⣄⣯⣾⢿⣮⡽⢿⡟⡸⢿⣟⢫⣜⣷⡿⣷⡇⣦⣿⠋⠁⠀⠀⠀⠀⠀⠀\n" \
	 << "⠀⠀⠀⠀⠀⠀⠀⠀⠉⠉⠉⠉⠀⠀⠙⣿⣆⠳⣩⠖⣸⣶⡿⠛⠛⠿⠛⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀\n" \
	 << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢼⣧⠛⣤⠛⣼⡏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n" \
	 << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⡗⡏⣆⢏⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n" \
	 << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⡿⡱⢜⣊⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n" \
	 << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣟⡥⠳⣌⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n" \
	 << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣯⠖⡹⢤⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n" \
	 << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⡷⣋⠵⣃⢾⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n" \
	 << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣯⡕⣮⢱⣾⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n" \
	 << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣯⡕⢬⣃⢿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n" \
	 << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢹⣗⠮⡱⣌⠾⣷⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n" \
	 << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣤⣾⣏⣶⡱⡜⡸⢽⣷⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n" \
	 << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣴⣿⣏⣿⡿⠛⣷⣭⣽⣷⣾⣿⣦⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n" \
	 << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠛⠁⠀⠀⠈⠛⠛⠛⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
}
