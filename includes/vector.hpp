/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:43:16 by lduboulo          #+#    #+#             */
/*   Updated: 2022/12/06 13:19:02 by lduboulo         ###   ########.fr       */
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

		size_type	size() const;
		size_type	max_size() const;
		void		resize(size_type n, value_type val = value_type());
		size_type	capacity() const;
		bool		empty() const;
		void		reserve(size_type n);
};

}
#endif
