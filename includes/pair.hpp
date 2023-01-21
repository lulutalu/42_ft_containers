/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulutalu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:10:38 by lulutalu          #+#    #+#             */
/*   Updated: 2023/01/21 15:48:03 by lulutalu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
# define PAIR_HPP

namespace ft {

template <class T1, class T2>
struct pair {

		typedef T1			first_type;
		typedef T2			second_type;

		first_type		first;
		second_type		second;

		pair(void) : first(), second() {};											// Default constructor
		
		template <class U, class V>
		pair(const pair<U, V>& pr) : first(pr.first), second(pr.second) {};			// Copy / Move constructor

		pair(const first_type& a, const second_type& b) : first(a), second(b)	{}; 	// Assignation Constructor

		pair&		operator = (const pair& other) {
				if (&other == this)
						return (*this);
				this->first = other.first;
				this->second = other.second;
				return (*this);
		}

		first_type	getFirst(void) const {
				return (this->first);
		}

		second_type	getSecond(void) const {
				return (this->second);
		}

}; // struct

template <class T1, class T2>
bool	operator == (const ft::pair<T1, T2>& lhs, const ft::pair<T1, T2>& rhs) {
		return (lhs.first == rhs.first && lhs.second == rhs.second);
}

template <class T1, class T2>
bool	operator != (const ft::pair<T1, T2>& lhs, const ft::pair<T1, T2>& rhs) {
		return (!(lhs == rhs));
}

template <class T1, class T2>
bool	operator < (const ft::pair<T1, T2>& lhs, const ft::pair<T1, T2>& rhs) {
		return (lhs.first < rhs.first && lhs.second < rhs.second);
}

template <class T1, class T2>
bool	operator <= (const ft::pair<T1, T2>& lhs, const ft::pair<T1, T2>& rhs) {
		return (!(rhs < lhs));
}

template <class T1, class T2>
bool	operator > (const ft::pair<T1, T2>& lhs, const ft::pair<T1, T2>& rhs) {
		return (rhs < lhs);
}

template <class T1, class T2>
bool	operator >= (const ft::pair<T1, T2>& lhs, const ft::pair<T1, T2>& rhs) {
		return (!(lhs < rhs));
}

template <class T1, class T2>
ft::pair<T1, T2>	make_pair(T1 x, T2 y) {
		return (ft::pair<T1, T2>(x, y));
}

} // namespace

#endif
