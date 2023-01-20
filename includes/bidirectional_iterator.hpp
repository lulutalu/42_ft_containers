/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bidirectional_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulutalu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 17:15:00 by lulutalu          #+#    #+#             */
/*   Updated: 2023/01/20 17:30:16 by lulutalu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIDIRECTIONAL_ITERATOR_HPP
# define BIDIRECTIONAL_ITERATOR_HPP

# include "iterator.hpp"

namespace ft {

template <class T>
class bidirectional_iterator : public ft::iterator<ft::bidirectional_iterator_tag, T>
{

		public :

				typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::value_type		value_type;
				typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::difference_type	difference_type;
				typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::pointer			pointer;
				typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::reference			reference;
				typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::iterator_category	iterator_category;

		private :

				pointer		_ptr;

		public :

/*				bidirectional_iterator(void);													// Default constructor
				bidirectional_iterator(const bidirectional_iterator& x);						// Copy constructor
				bidirectional_iterator(pointer newPtr);											// Assignation constructor

				bidirectional_iterator&		operator = (const bidirectional_iterator& x);		// Overload of equal operator

				~bidirectional_iterator(void);													// Destructor

				bool	operator == (const bidirectional_iterator& rhs) const;					// Boolean equal comparison
				bool	operator != (const bidirectional_iterator& rhs) const;					// Boolean not equal comparison

				reference	operator * (void) const;											// Return a reference to value pointed by inner pointer
				pointer		operator -> (void) const;											// Return the inner pointer

				bidirectional_iterator&		operator ++ (void);									// Pre-Increment
				bidirectional_iterator		operator ++ (int);									// Post-Increment

				bidirectional_iterator&		operator -- (void);									// Pre-Decrement
				bidirectional_iterator		operator -- (int);									// Post-Decrement

				pointer		getPointer(void) const ;											// Getter for inner pointer
*/

				bidirectional_iterator(void) : _ptr(NULL) {}

				bidirectional_iterator(const bidirectional_iterator& x) : _ptr(x._ptr) {}

				bidirectional_iterator(pointer newPtr) : _ptr(newPtr) {}

				bidirectional_iterator&		operator = (const bidirectional_iterator& x) {
						if (&x == this)
								return (*this);
						this->_ptr = x._ptr;
						return (*this);
				}

				~bidirectional_iterator(void) {
						this->_ptr = NULL;
				}

				bool	operator == (const bidirectional_iterator& rhs) const {
						return (this->_ptr == rhs._ptr);
				}

				bool	operator != (const bidirectional_iterator& rhs) const {
						return (this->_ptr != rhs._ptr);
				}

				reference	operator * (void) const {
						return (*this->_ptr);
				}

				pointer		operator -> (void) const {
						return (&(*this->_ptr));
				}

				bidirectional_iterator&		operator ++ (void) {
						this->_ptr++;
						return (*this);
				}

				bidirectional_iterator		operator ++ (int) {
						bidirectional_iterator	tmp(*this);

						this->_ptr++;
						return (tmp);
				}

				bidirectional_iterator&		operator -- (void) {
						this->_ptr--;
						return (*this);
				}

				bidirectional_iterator		operator -- (int) {
						bidirectional_iterator	tmp(*this);

						this->_ptr--;
						return (tmp);
				}

				pointer		getPointer(void) const {
						return (this->_ptr);
				}

				operator	bidirectional_iterator<const value_type> (void) const {
						return (bidirectional_iterator<const value_type>(this->_ptr));
				}

}; // class definition

template <typename T1, typename T2>
bool	operator == (const ft::bidirectional_iterator<T1>& lhs, const ft::bidirectional_iterator<T2>& rhs) {
		return (lhs.getPointer() == rhs.getPointer());
}

template <typename T1, typename T2>
bool	operator != (const ft::bidirectional_iterator<T1>& lhs, const ft::bidirectional_iterator<T2>& rhs) {
		return (lhs.getPointer() != rhs.getPointer());
}

} // namespace

#endif
