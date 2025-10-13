/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 10:39:31 by dde-carv          #+#    #+#             */
/*   Updated: 2025/10/13 15:49:15 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ShrubberyCreationForm.hpp"

/************ Constructors and Destructor ************/

ShrubberyCreationForm::ShrubberyCreationForm()
 : AForm("ShrubberyCreationForm", "Default", 145, 137)
{
	std::cout << GREEN << "ShrubberyCreationForm default constructor called." << RST << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
 : AForm("ShrubberyCreationForm", target, 145, 137)
{
	std::cout << GREEN << "ShrubberyCreationForm custom constructor called." << RST << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
 : AForm(other)
{
	std::cout << GREEN << "ShrubberyCreationForm copy constructor called." << RST << std::endl;

	*this = other;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
		AForm::operator=(other);

	std::cout << YELLOW << "ShrubberyCreationForm copy assignment operator called." << RST << std::endl;

	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << RED << "ShrubberyCreationForm destructor called." << RST << std::endl;
}

void	ShrubberyCreationForm::action(Bureaucrat const &executor) const
{
	std::cout << BLUE << "The Bureaucrat " << executor.getName() \
	 << " planted a Shrubbery tree at " << _target << "!" << RST << std::endl;
	std::string fileName = _target + "_shrubbery";
	std::ofstream outFile(fileName.c_str(), std::fstream::trunc);
	if (!outFile.is_open() || outFile.fail())
		std::cout << RED << "Error opening file " << fileName << " in ShrubberyCreationForm!" << RST << std::endl;
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
