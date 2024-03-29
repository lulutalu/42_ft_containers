/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:43:16 by lduboulo          #+#    #+#             */
/*   Updated: 2023/01/27 16:25:49 by lulutalu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>
# include <iostream>
# include <cstdio>
# include <stdexcept>

# include "random_access_iterator.hpp"
# include "reverse_iterator.hpp"

# include "enable_if.hpp"
# include "is_integral.hpp"

# include "equal.hpp"
# include "lexicographical_compare.hpp"

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

		typedef	T												value_type;
		typedef	Alloc											allocator_type;

		typedef typename allocator_type::reference				reference;
		typedef typename allocator_type::pointer				pointer;
		typedef typename allocator_type::const_reference		const_reference;
		typedef typename allocator_type::const_pointer			const_pointer;

		typedef ft::random_access_iterator<value_type>			iterator;
		typedef ft::random_access_iterator<const value_type>	const_iterator;
		typedef ft::reverse_iterator<iterator>					reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>			const_reverse_iterator;

		typedef std::size_t										size_type;
		typedef std::ptrdiff_t									difference_type;

/*		////////////////////////////////////////////////////////////////////////
		////////////////////////////////////////////////////////////////////////
		///							Member Functions						////
		////////////////////////////////////////////////////////////////////////

		////////////////////////////////////////////////////////////////////////
		///							Getter Functions						////
		////////////////////////////////////////////////////////////////////////

		size_type	getSize(void);

		////////////////////////////////////////////////////////////////////////
		///							Base Functions							////
		////////////////////////////////////////////////////////////////////////


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


		////////////////////////////////////////////////////////////////////////
		///							Iterators Functions						////
		////////////////////////////////////////////////////////////////////////

		iterator				begin();										// Return an iterator pointing to the first element of the container
		const_iterator			begin() const;									// Return an const iterator pointing to the first element of the container
		iterator				end();											// Return an iterator pointing to the past-the-end element of the container
		const_iterator			end() const;									// Return an const iterator pointing to the past-the-end element of the container
		reverse_iterator		rbegin();										// Return a reverse iterator pointing to the last element of the container
		const_reverse_iterator	rbegin() const;									// Return a const reverse iterator pointing to the last element of the container
		reverse_iterator		rend();											// Return a reverse iterator pointing to the theoretical pre-first element of the container
		const_reverse_iterator	rend() const;									// Return a const reverse iterator pointing to the pre-first element of the container

		////////////////////////////////////////////////////////////////////////
		///							Modifiers Functions						////
		////////////////////////////////////////////////////////////////////////

		template <class InputIterator>
		void	assign(InputIterator first, InputIterator last);				// Assign new content to vector by replacing the current content with two iterators
		void	assign(size_type n, const value_type& val);						// Assign n time val content to vector by replacing the current content

		void	push_back(const value_type& val);								// Add new element after current last element of vector (might cause re-allocation)
		void	pop_back(void);													// Remove the last element of the vector

		iterator	insert(iterator position, const value_type& val);			// Insert an element of val before the position pointed by the iterator (might cause re-alloc)
		void		insert(iterator position, size_type n, const value_type& val); 	// Insert n element of val before the position pointer by the iterator (might cause re-alloc)
		template <class InputIterator>												// Insert from first to last w/o last before position (might cause re-alloc)
		void		insert(iterator position, InputIterator first, InputIterator last);

		iterator	erase(iterator position);									// Remove the element at position. Return an iterator atthe new location of the next element (previous erase)
		iterator	erase(iterator first, iterator last);						// Remove the range of element between first and last including first.

		void		swap(vector& x);											// Exchange the content of both vectors. (this vector -> x and x -> this)

		void		clear(void);												// Remove all elements and destoying them

		////////////////////////////////////////////////////////////////////////
		///							Relational Operators					////
		////////////////////////////////////////////////////////////////////////

		template <class T, class Alloc>		bool operator == (const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs);
		template <class T, class Alloc>		bool operator != (const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs);
		template <class T, class Alloc>		bool operator < (const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs);
		template <class T, class Alloc>		bool operator <= (const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs);
		template <class T, class Alloc>		bool operator > (const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs);
		template <class T, class Alloc>		bool operator >= (const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs);

		////////////////////////////////////////////////////////////////////////
		///								Allocator							////
		////////////////////////////////////////////////////////////////////////

		allocator_type		get_allocator(void) const;

*/

    private :

		allocator_type	_alloc;
		pointer			_pointer;
		size_type		_size;
		size_type		_capacity;

    public :

		////////////////////////////////////////////////////////////////////////
		///							Base Functions							////
		////////////////////////////////////////////////////////////////////////

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

		template <class InputIterator>
		vector(typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last, const allocator_type& alloc = allocator_type()) 
																												: _alloc(alloc), _pointer(NULL) {
				size_type		n = 0;
				InputIterator	tmp = first;

				for ( ; tmp != last; tmp++)
						n++;

				this->_size = n;
				this->_capacity = n;

				try {
						this->_pointer = _alloc.allocate(this->_capacity);
				}
				catch (std::bad_alloc& e) {
						std::cout << e.what() << std::endl;
				}

				n = 0;
				for (tmp = first; tmp != last; tmp++) {
						_alloc.construct(this->_pointer + n, *tmp);
						n++;
				}
		}

		vector(const vector& x) : _alloc(x._alloc), _pointer(NULL), _size(x._size), _capacity(x._capacity) {
				*this = x;
		}

		vector	&operator = (const vector& x) {
				if (&x == this)
						return (*this);

				if (this->_pointer != NULL) {
						this->clear();
						_alloc.deallocate(this->_pointer, this->_capacity);
				}

				try {
						if (x._capacity > 0)
								this->_pointer = _alloc.allocate(x._capacity);
				}
				catch (std::bad_alloc& e) {
						std::cout << e.what() << std::endl;
				}

				for (size_type i = 0; i < x._size; i++)
						_alloc.construct(this->_pointer + i, *(x._pointer + i));

				this->_size = x._size;
				this->_capacity = x._capacity;

				return (*this);
		}

		~vector(void) {
				this->clear();
				if (this->_capacity != 0)
						_alloc.deallocate(this->_pointer, this->_capacity);
				this->_pointer = NULL;
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
				else if (n == 0) {
						for (size_type i = 0; i < this->_size; i++)
							_alloc.destroy(this->_pointer + i);
						_alloc.deallocate(this->_pointer, this->_capacity);
						this->_pointer = NULL;
						this->_size = 0;
						this->_capacity = 0;
				}
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
								_alloc.construct(newPointer + i, *(_pointer + i));
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
								_alloc.construct(newPointer + i, *(_pointer + i));
						for (size_type i = 0; i < _size; i++)
								_alloc.destroy(_pointer + i);
						_alloc.deallocate(_pointer, _capacity);
						_pointer = newPointer;
						_capacity = n;
				}
		}

		////////////////////////////////////////////////////////////////////////
		///							Element access							////
		////////////////////////////////////////////////////////////////////////

		reference 		operator [] (size_type n) {
				return (this->_pointer[n]);
		}

		const_reference	operator [] (size_type n) const {
				return (this->_pointer[n]);
		}

		reference		at(size_type n) {
				if (n >= _size)
						throw (std::out_of_range("Requested position out of range"));
				else
						return (this->_pointer[n]);
		}

		const_reference	at(size_type n) const {
				if (n >= _size)
						throw (std::out_of_range("Requested position out of range"));
				else
						return (this->_pointer[n]);
		}

		reference		front(void) {
				return (this->_pointer[0]);
		}

		const_reference	front(void) const {
				return (this->_pointer[0]);
		}

		reference		back(void) {
				return (this->_pointer[this->_size - 1]);
		}

		const_reference	back(void) const {
				return (this->_pointer[this->_size - 1]);
		}

		pointer			data(void) {
				return (this->_pointer);
		}

		const_pointer	data(void) const {
				return (this->_pointer);
		}

		////////////////////////////////////////////////////////////////////////
		///							Iterators								////
		////////////////////////////////////////////////////////////////////////

		iterator				begin(void) {
			return (iterator(this->_pointer));
		}

		const_iterator			begin(void) const {
			return (const_iterator(this->_pointer));
		}

		iterator				end(void) {
			if (this->_size == 0)
				return (this->begin());
			return (iterator(this->_pointer + this->_size));
		}

		const_iterator			end(void) const {
			if (this->_size == 0)
				return (this->begin());
			return (const_iterator(this->_pointer + this->_size));
		}

		reverse_iterator		rbegin(void) {
				return (reverse_iterator(this->_pointer + this->_size));
		}

		const_reverse_iterator	rbegin(void) const {
				return (const_reverse_iterator(this->_pointer + this->_size));
		}

		reverse_iterator		rend(void) {
				return (reverse_iterator(this->_pointer));
		}

		const_reverse_iterator	rend(void) const {
				return (const_reverse_iterator(this->_pointer));
		}

		////////////////////////////////////////////////////////////////////////
		///							Modifiers Functions						////
		////////////////////////////////////////////////////////////////////////

		void	assign(size_type n, const value_type& val) {
				if (n <= 0)
						return ;
				if (n > _capacity) {
						pointer	newPointer;
						try {
								newPointer = _alloc.allocate(n);
						}
						catch (std::bad_alloc& e) {
								std::cout << e.what() << std::endl;
						}
						this->clear();
						_alloc.deallocate(_pointer, _capacity);
						for (size_type i = 0; i < n; i++)
								_alloc.construct(newPointer + i, val);
						_pointer = newPointer;
						_size = n;
						_capacity = n;
				}
				else {
					this->clear();
						for (size_type i = 0; i < n; i++)
								_alloc.construct(_pointer + i, val);
						_size = n;
				}
		}

		template <class InputIterator>
		void	assign(typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last) {
				InputIterator	tmp;
				size_type		n = 0;

				for (tmp = first; tmp != last; tmp++)
						n++;
				if (n > _capacity) {
						pointer	newPointer;
						try {
								newPointer = _alloc.allocate(n);
						}
						catch (std::bad_alloc& e) {
								std::cout << e.what() << std::endl;
						}
						this->clear();
						_alloc.deallocate(_pointer, _capacity);
						for (size_type i = 0; i < n; i++)
								_alloc.construct(newPointer + i, *(first)++);
						_pointer = newPointer;
						_size = n;
						_capacity = n;
				}
				else {
						this->clear();
						for (size_type i = 0; i < n; i++)
								_alloc.construct(_pointer + i, *(first)++);
						_size = n;
				}

		}

		void	push_back(const value_type& val) {
				size_type	oldSize = this->_size;

				if (this->_size + 1 > this->_capacity) {
						pointer	newPointer;

						try {
								if (this->_capacity == 0)
										newPointer = _alloc.allocate(1);
								else
										newPointer = _alloc.allocate(this->_capacity * 2);
						}
						catch (std::bad_alloc& e) {
								std::cout << e.what() << std::endl;
						}

						for (size_type i = 0; i < this->_size; i++)
								_alloc.construct(newPointer + i, *(this->_pointer + i));
						_alloc.construct(newPointer + this->_size, val);
						this->clear();
						_alloc.deallocate(this->_pointer, this->_capacity);

						if (this->_capacity != 0)
								this->_capacity *= 2;
						else
								this->_capacity += 1;

						this->_pointer = newPointer;
				}
				else
						_alloc.construct(this->_pointer + this->_size, val);
				this->_size = oldSize + 1;
		}

		void	pop_back(void) {
				_alloc.destroy(this->_pointer + this->_size - 1);
				this->_size -= 1;
		}

		iterator	insert(iterator position, const value_type& val) {
				size_type	diff = 0;
				pointer		newPointer;

				for (iterator it = this->begin(); it != position; it++)
						diff++;

				if (this->_size + 1 > this->_capacity) {
						try {
								if (this->_capacity == 0) {
										this->_pointer = _alloc.allocate(1);
										this->_size = 1;
										this->_capacity = 1;
										_alloc.construct(this->_pointer, val);
										return (this->begin());
								}
								else
										newPointer = _alloc.allocate(this->_capacity * 2);
						}
						catch (std::bad_alloc& e) {
								std::cout << e.what() << std::endl;
						}
						for (size_type i = 0; i < diff; i++)
								_alloc.construct(newPointer + i, *(this->_pointer + i));
						_alloc.construct(newPointer + diff, val);
						for (size_type i = diff + 1; i <= this->_size; i++)
								_alloc.construct(newPointer + i, *(this->_pointer + i - 1));
						for (size_type i = 0; i < this->_size; i++)
								_alloc.destroy(this->_pointer + i);
						_alloc.deallocate(this->_pointer, this->_capacity);
						this->_pointer = newPointer;
						this->_size += 1;
						this->_capacity *= 2;
						return (this->_pointer + diff);
				}
				else {
						if (diff == this->_size) {
								_alloc.construct(this->_pointer + diff, val);
								this->_size += 1;
								return (this->_pointer + diff);
						}
						else {
								try {
										newPointer = _alloc.allocate(this->_capacity);
								}
								catch (std::bad_alloc& e) {
										std::cout << e.what() << std::endl;
								}
								for (size_type i = 0; i < diff; i++)
										_alloc.construct(newPointer + i, *(this->_pointer + i));
								_alloc.construct(newPointer + diff, val);
								for (size_type i = diff + 1; i <= this->_size; i++)
										_alloc.construct(newPointer + i, *(this->_pointer + i - 1));
								for (size_type i = 0; i < this->_size; i++)
										_alloc.destroy(this->_pointer + i);
								_alloc.deallocate(this->_pointer, this->_capacity);
								this->_pointer = newPointer;
								this->_size += 1;
								return (this->_pointer + diff);
						}
				}
		}

		void	insert(iterator position, size_type n, const value_type& val) {
				size_type	pos = 0;
				pointer		newPointer = NULL;
				size_type	old_cap = this->_capacity;

				for (iterator it = this->begin(); it != position; it++)
						pos++;

				if (this->_size + n <= this->_capacity) {
						try {
								newPointer = _alloc.allocate(this->_capacity);
						}
						catch (std::bad_alloc& e) {
								std::cout << e.what() << std::endl;
						}
				}
				else if (this->_size + n <= this->_capacity * 2) {
						try {
								newPointer = _alloc.allocate(this->_capacity * 2);
						}
						catch (std::bad_alloc& e) {
								std::cout << e.what() << std::endl;
						}
						this->_capacity *= 2;
				}
				else {
						try {
								newPointer = _alloc.allocate(this->_capacity + n);
						}
						catch (std::bad_alloc& e) {
								std::cout << e.what() << std::endl;
						}
						this->_capacity += n;
				}
				for (size_type i = 0; i < pos; i++)
						_alloc.construct(newPointer + i, *(this->_pointer + i));
				for (size_type i = pos; i <= pos + n; i++)
						_alloc.construct(newPointer + i, val);
				for (size_type i = pos; i < this->_size; i++)
						_alloc.construct(newPointer + i + n, *(this->_pointer + i));
				for (size_type i = 0; i < this->_size; i++)
						_alloc.destroy(this->_pointer + i);
				_alloc.deallocate(this->_pointer, old_cap);
				this->_pointer = newPointer;
				this->_size += n;
		}

		template <class InputIterator>
		void	insert(iterator position, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last) {
				size_type	pos = 0;
				pointer		newPointer = NULL;
				size_type	old_cap = this->_capacity;
				size_type	n = 0;
				size_type	old_size = this->_size;

				for (iterator it = this->begin(); it != position; it++)
						pos++;

				for (InputIterator it = first; it != last; it++)
						n++;

				if (this->_size + n <= this->_capacity) {
						try {
								newPointer = _alloc.allocate(this->_capacity);
						}
						catch (std::bad_alloc& e) {
								std::cout << e.what() << std::endl;
						}
				}
				else if (this->_size + n <= this->_capacity * 2) {
						try {
								newPointer = _alloc.allocate(this->_capacity * 2);
						}
						catch (std::bad_alloc& e) {
								std::cout << e.what() << std::endl;
						}
						this->_capacity *= 2;
				}
				else {
						try {
								newPointer = _alloc.allocate(this->_capacity + n);
						}
						catch (std::bad_alloc& e) {
								std::cout << e.what() << std::endl;
						}
						this->_capacity += n;
				}
				for (size_type i = 0; i < pos; i++)
						_alloc.construct(newPointer + i, *(this->_pointer + i));

				for (size_type i = 0; i < n; i++) {
						try { _alloc.construct(newPointer + pos + i, *first++); }
						catch (...) {
								for (size_type j = 0; j < pos + i; j++)
										_alloc.destroy(newPointer + j);
								_alloc.deallocate(newPointer, this->_capacity);
								this->clear();
								_alloc.deallocate(this->_pointer, old_cap);
								this->_pointer = NULL;
								this->_size = 0;
								this->_capacity = 0;
								throw ("Error when construct");
						}
				}

				for (size_type i = 0; i < this->_size - pos; i++)
						_alloc.construct(newPointer + n + i + pos, *(this->_pointer + pos + i));

				this->clear();
				_alloc.deallocate(this->_pointer, old_cap);
				this->_pointer = newPointer;
				this->_size = old_size + n;
		}

		iterator	erase(iterator position) {
			pointer		newPointer = NULL;
			size_type	pos = 0;
			size_type	old_size = this->_size;

			for (iterator it = this->begin(); it != position; it++)
				pos++;

			try {
				newPointer = _alloc.allocate(this->_capacity);
			}
			catch (std::bad_alloc& e) {
				std::cout << e.what() << std::endl;
			}

			for (size_type i = 0; i < pos; i++)
				_alloc.construct(newPointer + i, *(this->_pointer + i));
			for (size_type i = pos + 1; i < this->_size; i++)
				_alloc.construct(newPointer + i - 1, *(this->_pointer + i));

			this->clear();
			_alloc.deallocate(this->_pointer, this->_capacity);

			this->_pointer = newPointer;
			this->_size = old_size - 1;
			return (this->_pointer + pos);
		}

		iterator	erase(iterator first, iterator last) {
			pointer		newPointer = NULL;
			size_type	start = 0;
			size_type	n = 0;

			for (iterator it = this->begin(); it != first; it++)
				start++;

			for (iterator it = first; it != last; it++)
				n++;

			try {
				newPointer = _alloc.allocate(this->_capacity);
			}
			catch (std::bad_alloc& e) {
				std::cout << e.what() << std::endl;
			}

			for (size_type i = 0; i < start; i++)
				_alloc.construct(newPointer + i, *(this->_pointer + i));
			for (size_type i = start + n; i < this->_size; i++)
				_alloc.construct(newPointer + i - n, *(this->_pointer + i));

			for (size_type i = 0; i < this->_size; i++)
				_alloc.destroy(this->_pointer + i);
			_alloc.deallocate(this->_pointer, this->_capacity);

			this->_pointer = newPointer;
			this->_size -= n;
			return (this->_pointer + start);
		}

		void	swap(vector& x) {
			pointer		tmpPointer;
			size_type	tmpSize;
			size_type	tmpCapacity;

			tmpPointer = this->_pointer;
			tmpSize = this->_size;
			tmpCapacity = this->_capacity;

			this->_pointer = x._pointer;
			x._pointer = tmpPointer;

			this->_size = x._size;
			x._size = tmpSize;

			this->_capacity = x._capacity;
			x._capacity = tmpCapacity;
		}

		void	clear(void) {
			for (size_type i = 0; i < this->_size; i++)
				_alloc.destroy(this->_pointer + i);
			this->_size = 0;
		}

		////////////////////////////////////////////////////////////////////////
		///								Allocator							////
		////////////////////////////////////////////////////////////////////////

		allocator_type		get_allocator(void) const {
				return (this->_alloc);
		}

		////////////////////////////////////////////////////////////////////////
		///							Relational Operators					////
		////////////////////////////////////////////////////////////////////////

		friend bool	operator == (const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs) {
				if (lhs._size != rhs._size)
						return (false);
				return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
		}

		friend bool	operator != (const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs) {
				return (!(lhs == rhs));
		}

		friend bool	operator < (const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs) {
				return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
		}

		friend bool	operator <= (const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs) {
				return (!(rhs < lhs));
		}

		friend bool	operator > (const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs) {
				return (rhs < lhs);
		}

		friend bool	operator >= (const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs) {
				return (!(lhs < rhs));
		}

		friend void	swap(vector<T, Alloc>& x, vector<T, Alloc>& y) {
				x.swap(y);
		}

}; // End of Vector Class

} // End of ft namespace

#endif
