/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 08:51:46 by dde-carv          #+#    #+#             */
/*   Updated: 2025/10/28 09:51:31 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack();
		MutantStack(const MutantStack &other);
		MutantStack	&operator=(const MutantStack &other);
		~MutantStack();

	typedef typename std::deque<T>::iterator			iterator;
	typedef typename std::deque<T>::reverse_iterator	reverse_iterator;

	iterator	begin();
	iterator	end();
	reverse_iterator	rbegin();
	reverse_iterator	rend();
};

#include "../src/MutantStack.tpp"
