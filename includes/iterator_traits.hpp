/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 16:23:29 by lduboulo          #+#    #+#             */
/*   Updated: 2022/12/15 18:00:22 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_TRAITS_HPP
# define ITERATOR_TRAITS_HPP

# include "iterator.hpp"

namespace ft {

template <class Iterator>
class iterator_traits
{
	public :

		typedef typename Iterator::difference_type		difference_type;
		typedef typename Iterator::value_type			value_type;
		typedef typename Iterator::pointer				pointer;
		typedef typename Iterator::reference			reference;
		typedef typename Iterator::iterator_category	iterator_category;

}; // generic definition

template <class T>
class iterator_traits<T*>
{
	public :

		typedef std::ptrdiff_t					difference_type;
		typedef T								value_type;
		typedef T*								pointer;
		typedef T&								reference;
		typedef random_access_iterator_tag		iterator_category;

}; // specialization with objects

template <class T>
class iterator_traits<const T*>
{
	public :

		typedef std::ptrdiff_t					difference_type;
		typedef T								value_type;
		typedef const T*						pointer;
		typedef const T&						reference;
		typedef random_access_iterator_tag		iterator_category;

}; // specialization with const objects

} // namespace

#endif
