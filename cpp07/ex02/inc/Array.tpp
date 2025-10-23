/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 16:09:28 by dde-carv          #+#    #+#             */
/*   Updated: 2025/10/23 17:35:14 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
Array<T>::Array() : _array(new T[0]), _size(0)
{}

template <typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]), _size(n)
{
	for(unsigned int i = 0; i < _size; i++)
		_array[i] = T();
}

template <typename T>
Array<T>::Array(const Array &other) : _array(new T[0])
{
	*this = other;
}

template <typename T>
Array<T>	&Array<T>::operator=(const Array &other)
{
	if (_array)
		delete[] _array;

	if (this != &other)
	{
		_size = other.size();
		_array = new T[_size];
		for(unsigned int i = 0; i < _size; i++)
			_array[i] = other._array[i];
	}
	return *this;
}

template <typename T>
Array<T>::~Array()
{
	if (_array)
		delete[] _array;
}

template <typename T>
T			&Array<T>::operator[](unsigned int i) const
{
	if (_array && (i >= this->size()))
		throw OutOfBounds();
	return _array[i];
}

template <typename T>
unsigned int	Array<T>::size() const
{
	if (!_array)
		return 0;
	return _size;
}

template <typename T>
const char* Array<T>::OutOfBounds::what() const throw()
{
	return "the index is out of bounds!!";
}
