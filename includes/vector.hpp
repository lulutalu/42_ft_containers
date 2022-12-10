/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:43:16 by lduboulo          #+#    #+#             */
/*   Updated: 2022/12/10 17:23:42 by lulutalu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>
# include <iostream>
# include <cstdio>
# include <stdexcept>

namespace ft {

template <class T, class Alloc = std::allocator<T> >
class vector
{

	public :

		////////////////////////////////////////////////////////////////////////
		////////////////////////////////////////////////////////////////////////
		///							Member Types							////
		////////////////////////////////////////////////////////////////////////
		////////////////////////////////////////////////////////////////////////

		typedef	T								value_type;
		typedef	Alloc							allocator_type;

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
/*

		explicit vector(const allocator_type& alloc = allocator_type());																			// Default Constructor
		explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type());							// Fill Constructor
		template <class InputIterator>		vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());		// Range Constructor
		vector(const vector& x);																													// Copy Constructor

		vector&	operator = (const vector& x);

		~vector();

		////////////////////////////////////////////////////////////////////////
		///							Capacity Functions						////
		////////////////////////////////////////////////////////////////////////

		size_type	size() const;												// Return number of element inside the vector
		size_type	max_size() const;											// Return maximum size possible of vector define by the system or some library
		void		resize(size_type n, value_type val = value_type());			// Resize the container so it contains n elements
		size_type	capacity() const;											// Return the maximum number of element storeable inside the vector
		bool		empty() const;												// Check whether or not the vector contains 0 element
		void		reserve(size_type n);										// Request that the capacity of the vector should at least be of n element
		
		////////////////////////////////////////////////////////////////////////
		///							Element access							////
		////////////////////////////////////////////////////////////////////////

		reference 		operator [] (size_type n);								// Return a reference to the element at position n
		const_reference	operator [] (size_type n) const;						// Return a const reference to the element at position n
		reference		at(size_type n);										// Return a reference to the element at position n with out-of-bounds checking
		const_reference	at(size_type n) const;									// Return a const reference to the element at postion n with out-of-bounds checking
		reference		front(void);											// Return a reference to the first element of the vector
		const_reference	front(void) const;										// Return a const reference to the first element of the vector
		reference		back(void);												// Return a reference to the last element of the vector
		const_reference back(void) const;										// Return a const reference to the last element of the vector
		pointer			data(void);												// Return a pointer to the underlying element storage of the vector
		const_pointer	data(void) const;										// Return a const pointer to the underlying element storage of the vector
*/
    private :

		allocator_type	_alloc;
		pointer			_pointer;
		size_type		_size;
		size_type		_capacity;

    public :

		explicit vector (const allocator_type& alloc = allocator_type()) :
				_alloc(alloc), _pointer(NULL), _size(0), _capacity(0) {}

		explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) :
				_alloc(alloc), _pointer(NULL), _size(n), _capacity(n)
		{
				try {
						_pointer = _alloc.allocate(n);
				}
				catch (std::bad_alloc& e) {
						std::cout << e.what() << std::endl;
				}
				for (size_type i = 0; i < _size; i++)
						_alloc.construct(_pointer + i, val);
		}

		//template <class InputIterator>
		//vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()) WIP

		vector(const vector& x) : _alloc(x._alloc), _pointer(NULL), _size(x._size), _capacity(x._capacity) {
				*this = x;
		}

/*		vector	&operator = (const vector& x) {
				if (&x == this)
						return (*this);
				try {
						_pointer = _alloc.allocate(_size);
				}
				catch (std::bad_alloc& e) {
						std::cout << e.what() << std::endl;
				}
				for (size_type i = 0; i < _size; i++)
						_alloc.construct(_pointer + i, x._pointer + i)
		}*/// WIP

		~vector(void) {
				for (size_type i = 0; i < _size; i++)
						_alloc.destroy(_pointer + i);
				_alloc.deallocate(_pointer, _capacity);
		}

		////////////////////////////////////////////////////////////////////////
		///							Capacity Functions						////
		////////////////////////////////////////////////////////////////////////

		size_type	size() const {
				return (this->_size);
		}

		size_type	max_size() const {
				return (this->_alloc.max_size());
		}

		// Resize the container so it contains n elements
		// If n for resize is bigger than the actual capacity, declare another pointer with enough space (old_capacity * 2)
		// Copy the values of old pointer inside and destroy the old pointer.
		//
		// Later on, the function clear could be used

		void		resize(size_type n, value_type val = value_type()) {
				if (n > this->max_size())
						throw (std::length_error("Size requested is too big\n"));
				if (n > _capacity) {
						pointer	newPointer;

						try {
								if (n <= _capacity * 2)
										newPointer = _alloc.allocate(_capacity * 2);
								else
										newPointer = _alloc.allocate(n);
						}
						catch (std::bad_alloc& e) {
								std::cout << e.what() << std::endl;
						}
						for (size_type i = 0; i < _size; i++)
								_alloc.construct(newPointer + i, _pointer + i);
						for (size_type i = _size; i < n; i++)
								_alloc.construct(newPointer + i, val);
						for (size_type i = 0; i < _size; i++)
								_alloc.destroy(_pointer + i);
						_alloc.deallocate(_pointer, _capacity);
						_pointer = newPointer;
						_size = n;
						if (n <= _capacity * 2)
								_capacity *= 2;
						else
								_capacity = n;
				}
				else if (n < _size) {
						for (size_type i = n; i < _size; i++)
								_alloc.destroy(_pointer + i);
						_size = n;
				}
				else if (n > _size && n <= _capacity) {
						for (size_type i = _size; i < n; i++)
								_alloc.construct(_pointer + i, val);
						_size = n;
				}
		}

		size_type	capacity() const {
				return (this->_capacity);
		}

		bool		empty() const {
				if (_size == 0)
						return (true);
				return (false);
		}

		void		reserve(size_type n) {
				if (n > this->max_size())
						throw (std::length_error("Size requested is too big\n"));
				else if (n > _capacity) {
						pointer	newPointer;

						try {
								newPointer = _alloc.allocate(n);
						}
						catch (std::bad_alloc& e) {
								std::cout << e.what() << std::endl;
						}
						for (size_type i = 0; i < _size; i++)
								_alloc.construct(newPointer + i, _pointer + i);
						for (size_type i = 0; i < _size; i++)
								_alloc.destroy(_pointer + i);
						_alloc.deallocate(_pointer, _capacity);
						_pointer = newPointer;
						_capacity = n;
				}
		}

};
	

}
#endif
