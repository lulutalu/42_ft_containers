/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulutalu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 17:34:21 by lulutalu          #+#    #+#             */
/*   Updated: 2023/01/09 17:10:53 by lulutalu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include <functional>
# include "pair.hpp"
# include "reverse_iterator.hpp"

namespace ft {

template <class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<ft::pair<const Key, T> > >
class map {

		public :

				////////////////////////////////////////////////////////////////
				///						Member Types						////
				////////////////////////////////////////////////////////////////

				typedef Key												key_type;
				typedef T												mapped_type;
				typedef ft::pair<const Key, T>							value_type;
				typedef std::size_t										size_type;
				typedef std::ptrdiff_t									difference_type;
				typedef Compare											key_compare;
				typedef Allocator										allocator_type;

				typedef value_type&										reference;
				typedef const value_type&								const_reference;
				typedef typename Allocator::pointer						pointer;
				typedef typename Allocator::const_pointer				const_pointer;

				typedef ft::bidirectional_iterator<value_type>			iterator;
				typedef ft::bidirectional_iterator<const value_type>	const_iterator;
				typedef ft::reverse_iterator<iterator>					reverse_iterator;
				typedef ft::reverse_iterator<const_iterator>			const_reverse_iterator;

		private :

				allocator_type		_alloc;
				key_compare			_compare;
				size_type			_size;

}; // class

} // namespace

#endif
