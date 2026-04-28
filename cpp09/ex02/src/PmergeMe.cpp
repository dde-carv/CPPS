/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 09:43:53 by dde-carv          #+#    #+#             */
/*   Updated: 2026/04/28 16:21:33 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other) : _vec(other._vec), _deq(other._deq) {}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
		_vec = other._vec;
		_deq = other._deq;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}

int	PmergeMe::parsePositiveInt(const std::string &s)
{
	if (s.empty())
		throw std::runtime_error("empty argument");
	for (size_t i = 0; i < s.size(); i++)
	{
		if (!std::isdigit(s[i]))
			throw std::runtime_error("invalid argument: " + s);
	}
	long val = std::atol(s.c_str());
	if (val <= 0 || val > INT_MAX)
		throw std::runtime_error("argument out of range: " + s);
	return static_cast<int>(val);
}

void	PmergeMe::loadSequence(int ac, char **av)
{
	if (ac < 2)
		throw std::runtime_error("no arguments provided");
	for (int i = 1; i < ac; i++)
	{
		int val = parsePositiveInt(std::string(av[i]));
		_vec.push_back(val);
		_deq.push_back(val);
	}
}

std::vector<int>	PmergeMe::insertOrder(int n)
{
	std::vector<int>	order;
	if (n == 0)
		return order;

	order.push_back(0);

	int	prev = 1;
	int	curr = 3;
	while (prev < n)
	{
		int	hi = (curr < n) ? curr : n;
		for (int i = hi; i > prev; i--)
			order.push_back(i - 1);
		int	next = curr + 2 * prev;
		prev = curr;
		curr = next;
	}

	std::vector<bool>	done(n, false);
	for (int i = 0; i < (int)order.size(); i++)
		if (order[i] < n)
			done[order[i]] = true;
	for (int i = 0; i < n; i++)
		if (!done[i])
			order.push_back(i);

	return order;
}

void	PmergeMe::mergeVec(std::vector<int> &seq)
{
	int	n = (int)seq.size();
	if (n <= 1)
		return;

	bool	odd = (n % 2 == 1);
	int		straggler = odd ? seq.back() : 0;
	int		m = n / 2;

	typedef std::pair<int, int>		Pair;
	std::vector<Pair>				pairs;
	for (int i = 0; i < m; i++)
	{
		int	a = seq[2 * i];
		int	b = seq[2 * i + 1];
		if (a < b)
			std::swap(a, b);
		pairs.push_back(Pair(a, b));
	}

	std::vector<int>	main;
	for (int i = 0; i < m; i++)
		main.push_back(pairs[i].first);

	mergeVec(main);

	std::sort(pairs.begin(), pairs.end());

	std::vector<int>	pend;
	for (int i = 0; i < m; i++)
		pend.push_back(pairs[i].second);

	std::vector<int>			result(main);
	std::vector<int>			ord = insertOrder(m);
	for (int k = 0; k < (int)ord.size(); k++)
	{
		int	idx = ord[k];
		int	val = pend[idx];
		std::vector<int>::iterator	bnd = std::upper_bound(result.begin(), result.end(), pairs[idx].first);
		std::vector<int>::iterator	pos = std::lower_bound(result.begin(), bnd, val);
		result.insert(pos, val);
	}

	if (odd)
	{
		std::vector<int>::iterator	pos = std::lower_bound(result.begin(), result.end(), straggler);
		result.insert(pos, straggler);
	}

	seq = result;
}

void	PmergeMe::mergeDeq(std::deque<int> &seq)
{
	int	n = (int)seq.size();
	if (n <= 1)
		return;

	bool	odd = (n % 2 == 1);
	int		straggler = odd ? seq.back() : 0;
	int		m = n / 2;

	typedef std::pair<int, int>		Pair;
	std::vector<Pair>				pairs;
	for (int i = 0; i < m; i++)
	{
		int	a = seq[2 * i];
		int	b = seq[2 * i + 1];
		if (a < b)
			std::swap(a, b);
		pairs.push_back(Pair(a, b));
	}

	std::deque<int>	main;
	for (int i = 0; i < m; i++)
		main.push_back(pairs[i].first);

	mergeDeq(main);

	std::sort(pairs.begin(), pairs.end());

	std::vector<int>	pend;
	for (int i = 0; i < m; i++)
		pend.push_back(pairs[i].second);

	std::deque<int>				result(main);
	std::vector<int>			ord = insertOrder(m);
	for (int k = 0; k < (int)ord.size(); k++)
	{
		int	idx = ord[k];
		int	val = pend[idx];
		std::deque<int>::iterator	bnd = std::upper_bound(result.begin(), result.end(), pairs[idx].first);
		std::deque<int>::iterator	pos = std::lower_bound(result.begin(), bnd, val);
		result.insert(pos, val);
	}

	if (odd)
	{
		std::deque<int>::iterator	pos = std::lower_bound(result.begin(), result.end(), straggler);
		result.insert(pos, straggler);
	}

	seq = result;
}

void	PmergeMe::run()
{
	printSeq("Before", _vec);

	struct timeval	start, end;

	gettimeofday(&start, NULL);
	mergeVec(_vec);
	gettimeofday(&end, NULL);
	double	vecTime = (end.tv_sec - start.tv_sec) * 1e6
		+ (end.tv_usec - start.tv_usec);

	gettimeofday(&start, NULL);
	mergeDeq(_deq);
	gettimeofday(&end, NULL);
	double	deqTime = (end.tv_sec - start.tv_sec) * 1e6
		+ (end.tv_usec - start.tv_usec);

	printSeq("After", _vec);

	std::cout << "Time to process a range of " << _vec.size()
		<< " elements with std::vector : "
		<< std::fixed << std::setprecision(5) << vecTime << " us" << std::endl;
	std::cout << "Time to process a range of " << _deq.size()
		<< " elements with std::deque  : "
		<< std::fixed << std::setprecision(5) << deqTime << " us" << std::endl;
}
