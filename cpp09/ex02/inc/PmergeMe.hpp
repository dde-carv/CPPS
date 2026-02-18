/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 09:43:34 by dde-carv          #+#    #+#             */
/*   Updated: 2026/02/18 09:38:16 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include <deque>

#include <algorithm>
#include <sys/time.h>
#include <iostream>
#include <iomanip>

class	PmergeMe
{
	public:
		PmergeMe();
		~PmergeMe();

		double sortVector(std::vector<int> &vec);
		double sortDeque(std::deque<int> &deq);

	private:
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);

		void	mergeInsertVector(std::vector<int> &vec);
		void	mergeInsertDeque(std::deque<int> &deq);
};
