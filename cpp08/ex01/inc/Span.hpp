/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 11:22:52 by dde-carv          #+#    #+#             */
/*   Updated: 2025/10/29 11:08:32 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <stdio.h>
# include <iostream>
# include <string.h>
# include <algorithm>
# include <fstream>
# include <vector>

class Span
{
	private:
		std::vector<int>	_vec;

	public:
		Span();
		Span(unsigned int N);
		Span(const Span &other);
		Span	&operator=(const Span &other);
		~Span();

		std::vector<int>	getVec()const;

		void	addNumber(int nbr);
		void	addRandom(int min, int max, unsigned int members);
		int		shortestSpan();
		int		longestSpan();
		void	printVec();

	class MaxCapacity : public std::exception
	{
		virtual const char* what() const throw();
	};

	class LessThanTwo : public std::exception
	{
		virtual const char* what() const throw();
	};

	class MoreMembersThanCapacity : public std::exception
	{
		virtual const char* what() const throw();
	};

	class MaxLessThanMin : public std::exception
	{
		virtual const char* what() const throw();
	};
};
