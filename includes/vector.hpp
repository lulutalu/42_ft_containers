/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:43:16 by lduboulo          #+#    #+#             */
/*   Updated: 2022/12/06 13:24:30 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>
# include <cstdio>

namespace ft {

template <class T, class Alloc = std::allocator<T>>
class vector
{
	private :

	public :

		////////////////////////////////////////////////////////////////////////
		////////////////////////////////////////////////////////////////////////
		///							Member Types							////
		////////////////////////////////////////////////////////////////////////
		////////////////////////////////////////////////////////////////////////

		typedef	T								value_type;
		typedef	std::allocator<value_type>		allocator_type;

		typedef value_type&						reference;
		typedef value_type*						pointer;
		typedef const value_type&				const_reference;
		typedef const value_type*				const_pointer;

		typedef std::size_t						size_type;
		typedef std::ptrdiff_t					difference_type;

		////////////////////////////////////////////////////////////////////////
		////////////////////////////////////////////////////////////////////////
		///							Member Functions						////
		////////////////////////////////////////////////////////////////////////
		////////////////////////////////////////////////////////////////////////
		///							Base Functions							////
		////////////////////////////////////////////////////////////////////////

		vector();
		~vector();

		explicit vector(const allocator_type& alloc = allocator_type());																			// Default Constructor
		explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type());							// Fill Constructor
//		template <class InputIterator>		vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());		// Range Constructor
		vector(const vector& x);																													// Copy Constructor

		vector&	operator = (const vector& x);

		////////////////////////////////////////////////////////////////////////
		///							Capacity Functions						////
		////////////////////////////////////////////////////////////////////////

		size_type	size() const;												// Return number of element inside the vector
		size_type	max_size() const;											// Return maximum size possible of vector define by the system or some library
		void		resize(size_type n, value_type val = value_type());			// Resize the container so it contains n elements
		size_type	capacity() const;											// Return the maximum number of element storeable inside the vector
		bool		empty() const;												// Check whether or not the vector contains 0 element
		void		reserve(size_type n);										// Request that the capacity of the vector should at least be of n element
};

}
#endif
