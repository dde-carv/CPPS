/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 09:43:34 by dde-carv          #+#    #+#             */
/*   Updated: 2026/04/28 16:20:26 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <vector>
# include <deque>
# include <string>
# include <iostream>
# include <algorithm>
# include <sstream>
# include <stdexcept>
# include <climits>
# include <sys/time.h>
# include <iomanip>

class PmergeMe
{
	public:
		PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
		~PmergeMe();

		void	loadSequence(int ac, char **av);
		void	run();

	private:
		std::vector<int>	_vec;
		std::deque<int>		_deq;

		void	mergeVec(std::vector<int> &seq);
		void	mergeDeq(std::deque<int> &seq);

		template <typename T>
		void	printSeq(const std::string &label, const T &seq) const;

		static int				parsePositiveInt(const std::string &s);
		static std::vector<int>	insertOrder(int n);
};

template <typename T>
void	PmergeMe::printSeq(const std::string &label, const T &seq) const
{
	std::cout << label << ": ";
	for (typename T::const_iterator it = seq.begin(); it != seq.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}
