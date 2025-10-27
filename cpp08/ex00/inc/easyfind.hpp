/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 09:44:16 by dde-carv          #+#    #+#             */
/*   Updated: 2025/10/27 10:40:30 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <algorithm>
# include <iostream>
# include <deque>
# include <vector>
# include <list>

class NotFound : public std::exception
{
	virtual const char* what() const throw();
};

const char* NotFound::what() const throw()
{
	return "Can't find the value in the container!!";
}

template <typename T>
typename T::iterator	easyfind(T &haystack, int needle)
{
	typename T::iterator	it;
	it = std::find(haystack.begin(), haystack.end(), needle);
	if (it == haystack.end())
		throw NotFound();
	return it;
}
