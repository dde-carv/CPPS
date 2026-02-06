/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 09:43:53 by dde-carv          #+#    #+#             */
/*   Updated: 2026/02/06 18:57:27 by dde-carv         ###   ########.fr       */
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

static double	deltaInUs(clock_t start, clock_t end)
{
	return (double)(end - start) * 1e6 / CLOCKS_PER_SEC;
}

double	PmergeMe::sortVector(std::vector<int> &vec)
{
	clock_t start = clock();
	mergeInsertVector(vec);
	clock_t end = clock();
	return deltaInUs(start, end);
}

double	PmergeMe::sortDecque(std::deque<int> &deq)
{
	clock_t start = clock();
	mergeInsertDeque(deq);
	clock_t end = clock();
	return deltaInUs(start, end);
}

void	PmergeMe::mergeInsertVector(std::vector<int> &vec)
{
	int size = vec.size();

	if (size < 1)
		return ;
	if (size == 2)
	{
		if (vec[0] > vec[1])
			std::swap(vec[0], vec[1]);
		return ;
	}

	int pairs = size / 2;
	std::vector<int>	firsts;
	std::vector<int>	seconds;
	firsts.reserve(pairs + (size % 2));
	seconds.reserve(pairs);

	for (int i = 0; i < pairs; i++)
	{
		int a = vec[2 * i], b = vec[2 * i + 1];
		if (a <= b)
		{
			firsts.push_back(a);
			seconds.push_back(b);
		}
		else
		{
			firsts.push_back(b);
			seconds.push_back(a);
		}
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

	for (int i = 0; i < size; i++)
		vec[i] = firsts[i];
}

void	PmergeMe::mergeInsertDeque(std::deque<int> &deq)
{
	int size = deq.size();

	if (size < 1)
		return ;
	if (size == 2)
	{
		if (deq[0] > deq[1])
			std::swap(deq[0], deq[1]);
		return ;
	}

	int pairs = size / 2;
	std::deque<int>	firsts;
	std::deque<int>	seconds;

	for (int i = 0; i < pairs; i++)
	{
		int a = deq[2 * i], b = deq[2 * i + 1];
		if (a <= b)
		{
			firsts.push_back(a);
			seconds.push_back(b);
		}
		else
		{
			firsts.push_back(b);
			seconds.push_back(a);
		}
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

	for (int i = 0; i < size; i++)
		deq[i] = firsts[i];
}
