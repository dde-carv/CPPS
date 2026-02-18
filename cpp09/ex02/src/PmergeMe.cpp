/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 09:43:53 by dde-carv          #+#    #+#             */
/*   Updated: 2026/02/18 09:38:22 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMe.hpp"

PmergeMe::PmergeMe()
{}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	(void)other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	(void)other;
	return *this;
}

PmergeMe::~PmergeMe()
{}

// Calculates the difference of time between
// the start and the end of the algorithm
// and it converts it for microseconds
static double	elapsedInUs(timeval tStart, timeval tEnd)
{
	return ((tEnd.tv_sec - tStart.tv_sec) * 1000000.0) + ((tEnd.tv_usec - tStart.tv_usec) / 1000.0);
}

// Gets the start of execution time and the end
// of execution time to calculate the difference
// and calls the algorithm for the vector
double	PmergeMe::sortVector(std::vector<int> &vec)
{
	struct timeval tStart, tEnd;

	gettimeofday(&tStart, NULL);
	mergeInsertVector(vec);
	gettimeofday(&tEnd, NULL);
	return elapsedInUs(tStart, tEnd);
}

// Gets the start of execution time and the end
// of execution time to calculate the difference
// and calls the algorithm for the deque
double	PmergeMe::sortDeque(std::deque<int> &deq)
{
	struct timeval tStart, tEnd;

	gettimeofday(&tStart, NULL);
	mergeInsertDeque(deq);
	gettimeofday(&tEnd, NULL);
	return elapsedInUs(tStart, tEnd);
}

void	PmergeMe::mergeInsertVector(std::vector<int> &vec)
{
	int size = vec.size();

	if (size < 2)
		return ;

	int pairs = size / 2;
	std::vector<int>	firsts;
	std::vector<int>	seconds;
	// Reserves space in memory to prevent reallocations
	firsts.reserve(pairs + (size % 2));
	seconds.reserve(pairs);

	for (int i = 0; i < pairs; i++)
	{
		int a = vec[2 * i], b = vec[2 * i + 1];
		if (a > b)
			std::swap(a, b);
		firsts.push_back(a);
		seconds.push_back(b);
	}

	if (size % 2 == 1)
		firsts.push_back(vec[size - 1]);

	mergeInsertVector(firsts);

	for (size_t i = 0; i < seconds.size(); i++)
	{
		int value = seconds[i];
		std::vector<int>::iterator pos = std::lower_bound(firsts.begin(), firsts.end(), value);
		firsts.insert(pos, value);
	}

	std::copy(firsts.begin(), firsts.end(), vec.begin());
}

void	PmergeMe::mergeInsertDeque(std::deque<int> &deq)
{
	int size = deq.size();

	if (size < 2)
		return ;

	int pairs = size / 2;
	std::deque<int>	firsts;
	std::deque<int>	seconds;

	for (int i = 0; i < pairs; i++)
	{
		int a = deq[2 * i], b = deq[2 * i + 1];
		if (a > b)
			std::swap(a, b);
		firsts.push_back(a);
		seconds.push_back(b);
	}

	if (size % 2 == 1)
		firsts.push_back(deq[size - 1]);

	mergeInsertDeque(firsts);

	for (size_t i = 0; i < seconds.size(); i++)
	{
		int value = seconds[i];
		std::deque<int>::iterator pos = std::lower_bound(firsts.begin(), firsts.end(), value);
		firsts.insert(pos, value);
	}

	std::copy(firsts.begin(), firsts.end(), deq.begin());
}
