/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulutalu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:58:36 by lulutalu          #+#    #+#             */
/*   Updated: 2023/01/20 19:14:37 by lulutalu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

# include "iterator_traits.hpp"

namespace ft {

		template <class Iterator>
		class reverse_iterator {

				public : 

				////////////////////////////////////////////////////////////////
				///						Member Types						////
				////////////////////////////////////////////////////////////////

				typedef Iterator														iterator_type;
				typedef typename iterator_traits<Iterator>::iterator_category			iterator_category;
				typedef typename iterator_traits<Iterator>::value_type					value_type;
				typedef typename iterator_traits<Iterator>::difference_type				difference_type;
				typedef typename iterator_traits<Iterator>::pointer						pointer;
				typedef typename iterator_traits<Iterator>::reference					reference;

				////////////////////////////////////////////////////////////////
				///						Member Functions					////
				////////////////////////////////////////////////////////////////

/*				reverse_iterator(void);															// Default constructor
				explicit reverse_iterator(iterator_type it);									// Initialization constructor
				template <class Iter> reverse_iterator(const reverse_iterator<Iter>& rev_it);	// Copy constructor

				iterator_type		base(void) const;											// Return a copy of the base iterator
				reference			operator * (void) const;									// Return a reference to the element pointed by the iterator	
				reverse_iterator	operator + (difference_type n) const;						// Return a reverse iterator at +n from the current element
				reverse_iterator	&operator ++ (void);										// Pre-Increment
				reverse_iterator	operator ++ (int);											// Post-Increment
				reverse_iterator	&operator += (difference_type n);							// Advance the reverse_iterator by n position
				reverse_iterator	operator - (difference_type n) const;						// Return a reverse_iterator at -n from the current element
				reverse_iterator	&operator -- (void);										// Pre-Decrement
				reverse_iterator	operator -- (int);											// Post-Decrement
				reverse_iterator	&operator -= (difference_type n);							// Decrease the reverse iterator by n position
				pointer				operator -> (void) const;									// Return a pointer to the element
				reference			operator [] (difference_type n) const;						// Dereference iterator with n offset
*/

				private :

				iterator_type	_base;

				public :

				reverse_iterator(void) : _base() {}

				explicit reverse_iterator(iterator_type it) : _base(it) {}

				template <class Iter>
				reverse_iterator(const reverse_iterator<Iter>& rev_it) : _base(rev_it.base()) {}

				iterator_type		base(void) const {
						return (iterator_type(this->_base));
				}

				reference			operator * (void) const {
						iterator_type	tmp(this->_base);

						tmp--;
						return (*tmp);
				}

				reverse_iterator	operator + (difference_type n) const {
						return (reverse_iterator(this->_base - n));
				}

				reverse_iterator	&operator ++ (void) {
						this->_base--;
						return (*this);
				}

				reverse_iterator	operator ++ (int) {
						reverse_iterator	tmp(*this);

						this->_base--;
						return (tmp);
				}

				reverse_iterator	&operator += (difference_type n) {
						this->_base -= n;
						return (*this);
				}

				reverse_iterator	operator - (difference_type n) const {
						return (reverse_iterator(this->_base + n));
				}

				reverse_iterator	&operator -- (void) {
						this->_base++;
						return (*this);
				}

				reverse_iterator	operator -- (int) {
						reverse_iterator	tmp(*this);

						this->_base++;
						return (tmp);
				}

				reverse_iterator	&operator -= (difference_type n) {
						this->_base += n;
						return (*this);
				}

				pointer				operator -> (void) const {
						return (&(operator * ()));
				}

				reference			operator [] (difference_type n) const {
						return (this->base()[-n - 1]);
				}

		}; // reverse_iterator class

		////////////////////////////////////////////////////////////////
		///						Non-Member Functions				////
		////////////////////////////////////////////////////////////////

/*		template <class Iterator> bool	operator == (const ft::reverse_iterator<Iterator>& lhs, const ft::reverse_iterator<Iterator>& rhs);
		template <class Iterator> bool	operator != (const ft::reverse_iterator<Iterator>& lhs, const ft::reverse_iterator<Iterator>& rhs);
		template <class Iterator> bool	operator < (const ft::reverse_iterator<Iterator>& lhs, const ft::reverse_iterator<Iterator>& rhs);
		template <class Iterator> bool	operator <= (const ft::reverse_iterator<Iterator>& lhs, const ft::reverse_iterator<Iterator>& rhs);
		template <class Iterator> bool	operator > (const ft::reverse_iterator<Iterator>& lhs, const ft::reverse_iterator<Iterator>& rhs);
		template <class Iterator> bool	operator >= (const ft::reverse_iterator<Iterator>& lhs, const ft::reverse_iterator<Iterator>& rhs);

		template <class Iterator>
		ft::reverse_iterator<Iterator>	operator + (typename ft::reverse_iterator<Iterator>::difference_type n, const ft::reverse_iterator<Iterator>& rev_it);

		template <class Iterator>
		typename ft::reverse_iterator<Iterator>::difference_type	operator - (const ft::reverse_iterator<Iterator>& lhs, const ft::reverse_iterator<Iterator>& rhs);
*/

		template <class Iterator>
		bool	operator == (const ft::reverse_iterator<Iterator>& lhs, const ft::reverse_iterator<Iterator>& rhs) {
				return (lhs.base() == rhs.base());
		}

		template <class It1, class It2>
		bool	operator == (const ft::reverse_iterator<It1>& lhs, const ft::reverse_iterator<It2>& rhs) {
				return (lhs.base() == rhs.base());
		}

		template <class Iterator>
		bool	operator != (const ft::reverse_iterator<Iterator>& lhs, const ft::reverse_iterator<Iterator>& rhs) {
				return (lhs.base() != rhs.base());
		}

		template <class It1, class It2>
		bool	operator != (const ft::reverse_iterator<It1>& lhs, const ft::reverse_iterator<It2>& rhs) {
				return (lhs.base() != rhs.base());
		}

		template <class Iterator>
		bool	operator < (const ft::reverse_iterator<Iterator>& lhs, const ft::reverse_iterator<Iterator>& rhs) {
				return (lhs.base() > rhs.base());
		}

		template <class It1, class It2>
		bool	operator < (const ft::reverse_iterator<It1>& lhs, const ft::reverse_iterator<It2>& rhs) {
				return (lhs.base() > rhs.base());
		}

		template <class Iterator>
		bool	operator <= (const ft::reverse_iterator<Iterator>& lhs, const ft::reverse_iterator<Iterator>& rhs) {
				return (lhs.base() >= rhs.base());
		}

		template <class It1, class It2>
		bool	operator <= (const ft::reverse_iterator<It1>& lhs, const ft::reverse_iterator<It2>& rhs) {
				return (lhs.base() >= rhs.base());
		}

		template <class Iterator>
		bool	operator > (const ft::reverse_iterator<Iterator>& lhs, const ft::reverse_iterator<Iterator>& rhs) {
				return (lhs.base() < rhs.base());
		}

		template <class It1, class It2>
		bool	operator > (const ft::reverse_iterator<It1>& lhs, const ft::reverse_iterator<It2>& rhs) {
				return (lhs.base() < rhs.base());
		}

		template <class Iterator>
		bool	operator >= (const ft::reverse_iterator<Iterator>& lhs, const ft::reverse_iterator<Iterator>& rhs) {
				return (lhs.base() <= rhs.base());
		}

		template <class It1, class It2>
		bool	operator >= (const ft::reverse_iterator<It1>& lhs, const ft::reverse_iterator<It2>& rhs) {
				return (lhs.base() <= rhs.base());
		}

		template <class Iterator>
		ft::reverse_iterator<Iterator>	operator + (typename ft::reverse_iterator<Iterator>::difference_type n, const ft::reverse_iterator<Iterator>& rev_it) {
				return (rev_it + n);
		}

		template <class Iterator>
		typename ft::reverse_iterator<Iterator>::difference_type	operator - (const ft::reverse_iterator<Iterator>& lhs, const ft::reverse_iterator<Iterator>& rhs) {
				return (rhs.base() - lhs.base());
		}

		template <class It1, class It2>
		typename ft::reverse_iterator<It1>::difference_type		operator - (const ft::reverse_iterator<It1>& lhs, const ft::reverse_iterator<It2>& rhs) {
				return (rhs.base() - lhs.base());
		}

} // namespace

#endif
