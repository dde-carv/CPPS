/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 09:43:34 by dde-carv          #+#    #+#             */
/*   Updated: 2026/04/02 16:45:10 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include <deque>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <sys/time.h>
#include <cstdlib>
#include <climits>
#include <cctype>
#include <string>

class PmergeMe
{
	private:
		PmergeMe(const PmergeMe &src);
		PmergeMe	&operator=(const PmergeMe &src);

		void	mergeInsertVector(std::vector<int> &vec);
		void	mergeInsertDeque(std::deque<int> &deq);

	public:
		PmergeMe();
		~PmergeMe();

		double	sortVector(std::vector<int> &vec);
		double	sortDeque(std::deque<int> &deq);
};
