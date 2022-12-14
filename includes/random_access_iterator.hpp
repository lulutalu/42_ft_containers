/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 14:29:26 by lduboulo          #+#    #+#             */
/*   Updated: 2023/01/04 18:45:20 by lulutalu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP

# include "iterator.hpp"

namespace ft {

template <class T>
class random_access_iterator : public ft::iterator<ft::random_access_iterator_tag, T>
{
		public :

				typedef typename ft::iterator<ft::random_access_iterator_tag, T>::value_type			value_type;
				typedef typename ft::iterator<ft::random_access_iterator_tag, T>::difference_type		difference_type;
				typedef typename ft::iterator<ft::random_access_iterator_tag, T>::pointer				pointer;
				typedef typename ft::iterator<ft::random_access_iterator_tag, T>::reference				reference;
				typedef typename ft::iterator<ft::random_access_iterator_tag, T>::iterator_category		iterator_category;

		private :

				pointer		_ptr;

/*				random_access_iterator(void);											// Default constructor
				random_access_iterator(const random_access_iterator& x);				// Copy Constructor
				random_access_iterator(pointer _newPtr);								// Constructor with pointer argument

				random_access_iterator& operator = (const random_access_iterator& x); 	// Operator Overload

				~random_access_iterator(void);											// Destructor


				bool	operator == (const random_access_iterator& rhs) const;			// Equal comparison
				bool	operator != (const random_access_iterator& rhs) const;			// Not Equal Comparison

				reference	operator * (void) const;									// Dereference rvalue
				pointer		operator -> (void) const;									// Dereference rvalue

				random_access_iterator	&operator ++ (void);							// Pre-Increment
				random_access_iterator	operator ++ (int);								// Post-Increment

				random_access_iterator	&operator -- (void);							// Pre-Decrement
				random_access_iterator	operator -- (int);								// Post-Decrement

				random_access_iterator	operator + (difference_type n) const;			// Return an iterator to actual iterator + n
				random_access_iterator	operator - (difference_type n) const;			// Return an iterator to actual iterator - n

				difference_type			operator - (const random_access_iterator& rhs); // Return the distance between two iterators

				bool	operator < (const random_access_iterator& rhs) const;			// Is this iterator smaller than rhs iterator
				bool	operator > (const random_access_iterator& rhs) const;			// Is this iterator bigger than rhs iterator
				bool	operator <= (const random_access_iterator& rhs) const;			// Is this iterator smaller or equal to rhs iterator
				bool	operator >= (const random_access_iterator& rhs) const;			// Is this iterator bigger or equal to rhs iterator

				random_access_iterator	operator += (difference_type n) const;			// Return an iterator to actual iterator + n
				random_access_iterator	operator -= (difference_type n) const;			// Return an iterator to actual iterator - n

				reference	operator [] (difference_type n);							// Return a reference to value at n position in container

				pointer		getPointer(void) const ;									// Getter for private member _ptr 

*/

		public :

				random_access_iterator(void) : _ptr(NULL) {}

				random_access_iterator(const random_access_iterator& x) : _ptr(x._ptr) {}

				random_access_iterator(pointer _newPtr) : _ptr(_newPtr) {}

				random_access_iterator&		operator = (const random_access_iterator& x) {
						if (&x == this)
								return (*this);
						this->_ptr = x._ptr;
						return (*this);
				}

				~random_access_iterator(void) {
						this->_ptr = NULL;
				}

				bool		operator == (const random_access_iterator& rhs) const {
						return (this->_ptr == rhs._ptr);
				}

				bool		operator != (const random_access_iterator& rhs) const {
						return (this->_ptr != rhs._ptr);
				}

				reference	operator * (void) const {
						return (*this->_ptr);
				}

				pointer		operator -> (void) const {
						return (&(*this->_ptr));
				}

				random_access_iterator&		operator ++ (void) {
						this->_ptr++;
						return (*this);
				}

				random_access_iterator		operator ++ (int) {
						random_access_iterator	tmp (*this);

						this->_ptr++;
						return (tmp);
				}

				random_access_iterator&		operator -- (void) {
						this->_ptr--;
						return (*this);
				}

				random_access_iterator		operator -- (int) {
						random_access_iterator	tmp(*this);

						this->_ptr--;
						return (tmp);
				}

				random_access_iterator		operator + (difference_type n) const {
						return (this->_ptr + n);
				}

				random_access_iterator		operator - (difference_type n) const {
						return (this->_ptr - n);
				}

				difference_type			operator - (const random_access_iterator& rhs) {
						random_access_iterator	tmp(*this);
						difference_type			res = 0;

						if (tmp < rhs) {
								while (tmp != rhs) {
										tmp++;
										res--;
								}
						}
						else if (tmp > rhs) {
								while (tmp != rhs) {
										tmp--;
										res++;
								}
						}
						return (res);
				}

				bool	operator < (const random_access_iterator& rhs) const {
						return (this->_ptr < rhs._ptr);
				}

				bool	operator > (const random_access_iterator& rhs) const {
						return (this->_ptr > rhs._ptr);
				}

				bool	operator <= (const random_access_iterator& rhs) const {
						return (this->_ptr <= rhs._ptr);
				}

				bool	operator >= (const random_access_iterator& rhs) const {
						return (this->_ptr >= rhs._ptr);
				}

				random_access_iterator	operator += (difference_type n) {
						this->_ptr += n;
						return (*this);
				}

				random_access_iterator	operator -= (difference_type n) {
						this->_ptr -= n;
						return (*this);
				}

				reference	operator [] (difference_type n) const {
						return (*(this->_ptr + n));
				}

				operator	random_access_iterator<const value_type> (void) const {
					return (random_access_iterator<const value_type>(this->_ptr));
				}

				pointer		getPointer(void) const {
						return (this->_ptr);
				}

}; // random access iterator class

/*		template <class T>																// Return an iterator to cur iterator + n
		typename ft::random_access_iterator<T>	operator + (typename ft::random_access_iterator<T>::difference_type n,
																typename ft::random_access_iterator<T>& cur);
*/

		template <typename T>
		typename ft::random_access_iterator<T>	operator + (typename ft::random_access_iterator<T>::difference_type n,
						ft::random_access_iterator<T>& cur) {
				return (&(*cur) + n);
		}

		template <typename T1, typename T2>
		typename ft::random_access_iterator<T1>::difference_type	operator - (
						const ft::random_access_iterator<T1> lhs, const ft::random_access_iterator<T2> rhs) {
				ft::random_access_iterator<T1>									tmp(lhs);
				typename ft::random_access_iterator<T1>::difference_type		res = 0;

				if (lhs < rhs) {
						while (tmp != rhs) {
								tmp++;
								res--;
						}
				}
				else if (lhs > rhs) {
						while (tmp != rhs) {
								tmp--;
								res++;
						}
				}
				return (res);
		}

		template <typename T1, typename T2>
		bool	operator != (const ft::random_access_iterator<T1>& lhs, const ft::random_access_iterator<T2>& rhs) {
				return (lhs.getPointer() != rhs.getPointer());
		}

		template <typename T1, typename T2>
		bool	operator == (const ft::random_access_iterator<T1>& lhs, const ft::random_access_iterator<T2>& rhs) {
				return (lhs.getPointer() == rhs.getPointer());
		}

		template <typename T1, typename T2>
		bool	operator > (const ft::random_access_iterator<T1>& lhs, const ft::random_access_iterator<T2>& rhs) {
				return (lhs.getPointer() > rhs.getPointer());
		}

		template <typename T1, typename T2>
		bool	operator < (const ft::random_access_iterator<T1>& lhs, const ft::random_access_iterator<T2>& rhs) {
				return (lhs.getPointer() < rhs.getPointer());
		}

		template <typename T1, typename T2>
		bool	operator >= (const ft::random_access_iterator<T1>& lhs, const ft::random_access_iterator<T2>& rhs) {
				return (lhs.getPointer() >= rhs.getPointer());
		}

		template <typename T1, typename T2>
		bool	operator <= (const ft::random_access_iterator<T1>& lhs, const ft::random_access_iterator<T2>& rhs) {
				return (lhs.getPointer() <= rhs.getPointer());
		}

} // namespace

#endif
