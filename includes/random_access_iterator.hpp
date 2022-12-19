/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 14:29:26 by lduboulo          #+#    #+#             */
/*   Updated: 2022/12/19 16:02:20 by lulutalu         ###   ########.fr       */
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


				random_access_iterator(void);											// Default constructor
				random_access_iterator(const random_access_iterator& x);				// Copy Constructor

				random_access_iterator& operator = (const random_access_iterator& x); 	// Operator Overload

				~random_access_iterator(void);											// Destructor


				bool	operator == (const random_access_iterator& rhs);				// Equal comparison
				bool	operator != (const random_access_iterator& rhs);				// Not Equal Comparison

				reference	operator * (void) const;									// Dereference rvalue
				pointer		operator -> (void) const;									// Dereference rvalue

				random_access_iterator	&operator ++ (void);							// Pre-Increment
				random_access_iterator	operator ++ (int);								// Post-Increment

				random_access_iterator	&operator -- (void);							// Pre-Decrement
				random_access_iterator	operator -- (int);								// Post-Decrement

				random_access_iterator	operator + (difference_type n) const;			// Return an iterator to actual iterator + n
				random_access_iterator	operator - (difference_type n) const;			// Return an iterator to actual iterator - n

}; // random access iterator class

} // namespace

#endif
