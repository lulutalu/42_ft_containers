/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulutalu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 17:34:21 by lulutalu          #+#    #+#             */
/*   Updated: 2023/01/20 15:56:05 by lulutalu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include <functional>
# include "pair.hpp"
# include "reverse_iterator.hpp"
# include "bidirectional_iterator.hpp"
# include "binary_search_tree.hpp"
# include "enable_if.hpp"
# include "is_integral.hpp"

namespace ft {

template <class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key, T> > >
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
				typedef Alloc											allocator_type;

				typedef value_type&										reference;
				typedef const value_type&								const_reference;
				typedef typename Alloc::pointer							pointer;
				typedef typename Alloc::const_pointer					const_pointer;

				typedef typename ft::BST<Key, T, Compare>::iterator						iterator;
				typedef typename ft::BST<Key, T, Compare>::const_iterator				const_iterator;
				typedef typename ft::BST<Key, T, Compare>::reverse_iterator				reverse_iterator;
				typedef typename ft::BST<Key, T, Compare>::const_reverse_iterator		const_reverse_iterator;

				////////////////////////////////////////////////////////////////
				///							Friend Class					////
				////////////////////////////////////////////////////////////////

				class value_compare : public std::binary_function<value_type, value_type, bool>
				{
						public :
								
								//						Member Types
								typedef bool							result_type;
								typedef value_type						first_argument_type;
								typedef value_type						second_argument_type;

								//						Member Functions
								bool		operator () (const value_type&x, const value_type& y) const {
										return (this->_comp(x.first, y.first));
								}

						protected :

								//						Protected variable
								Compare		_comp;

								//						Protected Constructor
								value_compare(Compare c) : _comp(c) {};

				}; // value_compare class

		private :

				allocator_type				_alloc;
				key_compare					_compare;
				BST<Key, T, Compare>		_bst;

		public :

/*				////////////////////////////////////////////////////////////////
				///						Member Functions					////
				////////////////////////////////////////////////////////////////

				explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());									// Default constructor
				template <class InputIterator>
				map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());	// Range constructor
				map(const map& x);																														// Copy constructor

				~map(void);														// Destructor

				map&	operator = (const map& x);								// Overload of equal operator

				////////////////////////////////////////////////////////////////
				///						Iterators Functions					////
				////////////////////////////////////////////////////////////////

				iterator					begin(void);						// Returns an iterator referring to the first element in the container
				const_iterator				begin(void) const;					// Return a const iterator referring to the first element in the container
				iterator					end(void);							// Return an iterator referring to the past-the-end element in the container
				const_iterator				end(void) const;					// Return a const iterator referring to the past-the-end element in the container
				reverse_iterator			rbegin(void);						// Return a reverse iterator referring to the last element in the container
				const_reverse_iterator		rbegin(void) const;					// Return a const reverse iterator referring to the last element in the container
				reverse_iterator			rend(void);							// Return a reverse iterator referring to the first element in the container
				const_reverse_iterator		rend(void) const;					// Return a const reverse iterator referring to the first element in the container

				////////////////////////////////////////////////////////////////
				///						Capacity Functions					////
				////////////////////////////////////////////////////////////////

				bool		empty(void) const;									// Boolean evaluation of container size
				size_type	size(void) const;									// Return number of element inside the container
				size_type	max_size(void) const;								// Return the theorical maximum of container size

				////////////////////////////////////////////////////////////////
				///						Element Access						////
				////////////////////////////////////////////////////////////////

				mapped_type&		operator [] (const key_type& k);			// Return a reference to the mapped value of key 'k' if found inside the container
				mapped_type&		at(const key_type& k);						// Return a reference to the mapped value of key 'k' if found inside the container
				const mapped_type&	at(const key_type& k) const;				// Return a const reference to the mapped value of key 'k' if found inside the container

				////////////////////////////////////////////////////////////////
				///						Modifiers Functions					////
				////////////////////////////////////////////////////////////////

				pair<iterator, bool>	insert(const value_type& val);						// Insert single element and return a pair with an iterator pointing to his pos
				iterator				insert(iterator position, const value_type& val);	// Insert single element with an iterator for the position	
				template <class InputIterator>
				void					insert(InputIterator first, InputIterator last);	// Insert a range of new element

				void		erase(iterator position);										// Erase the element at the position of the iterator
				size_type	erase(const key_type& k);										// Erase the elements with the key 'k' returning how many element were erased
				void		erase(iterator first, iterator last);							// Erase the range of elements between first and last

				void		swap(map& x);													// Basically swap content of two maps with same types

				void		clear(void);													// Remove all elements from the container

				////////////////////////////////////////////////////////////////
				///						Observers Functions					////
				////////////////////////////////////////////////////////////////

				key_compare		key_comp(void) const;							// Return a copy of the comparison object used to compare the keys
				value_compare	value_comp(void) const;							// Return a comparison object used to compare two elements

				////////////////////////////////////////////////////////////////
				///							Operations						////
				////////////////////////////////////////////////////////////////

				iterator			find(const key_type& k);					// Search the container for an element with a key equivalent to k and return an iterator
				const_iterator		find(const key_type& k) const;				// Search the container for an element with a key equivalent to k and return a const iterator

				size_type			count(const key_type& k) const;				// Search the container for the elements with a key equivalent to k and return number of match

				iterator			lower_bound(const key_type& k);				// Return an iterator to the first element whose key is not considered to go before than k
				const_iterator		lower_bound(const key_type& k) const;		// Return a const iterator to the first element whose key is not considered to go before than k

				iterator			upper_bound(const key_type& k);				// Return an iterator to the first element whose key is considered to go after k
				const_iterator		upper_bound(const key_type& k) const;		// Return a const iterator to the first element whose key is considered to go after k

				pair<const_iterator, const_iterator>	equal_range(const key_type& k) const;
				pair<iterator, iterator>				equal_range(const key_type& k);
				// Return the bounds of a range that includes all the elements in the container which have a key equivalent to k

				////////////////////////////////////////////////////////////////
				///							Allocator						////
				////////////////////////////////////////////////////////////////

				allocator_type		get_allocator(void) const;					// Return a copy of the allocator used in the container
*/

		////////////////////////////////////////////////////////////////
		///						Member Functions					////
		////////////////////////////////////////////////////////////////

		explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) :
				_bst(comp, alloc), _alloc(alloc), _compare(comp) {}

		template <class InputIterator>
		map(typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last, 
						const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _bst(comp, alloc), _alloc(alloc), _compare(comp) {
				while (first != last) {
						this->_bst.insertNode(first->pair);
						first++;
				}
		}

		map(const map& x) : _bst(x._compare, x._alloc), _alloc(x._alloc), _compare(x._compare) {
				*this = x;
		}

		map&		operator = (const map& x) {
				if (this == &x)
						return (*this);

				for (iterator it = x.begin(); it != x.end(); it++)
						this->_bst.insertNode(*it);
				return (*this);
		}

		~map(void) {}

		////////////////////////////////////////////////////////////////
		///						Iterators Functions					////
		////////////////////////////////////////////////////////////////

		iterator				begin(void) {
				return (iterator(this->_bst.minimum(this->_bst.getRoot())));
		}

		const_iterator			begin(void) const {
				return (const_iterator(this->_bst.minimum(this->_bst.getRoot())));
		}

		iterator				end(void) {
				return (iterator(this->_bst.maximum(this->_bst.getRoot())));
		}

		const_iterator			end(void) const {
				return (const_iterator(this->_bst.maximum(this->_bst.getRoot())));
		}

		reverse_iterator		rbegin(void) {
				return (reverse_iterator(this->_bst.maximum(this->_bst.getRoot())));
		}

		const_reverse_iterator	rbegin(void) const {
				return (const_reverse_iterator(this->_bst.maximum(this->_bst.getRoot())));
		}

		reverse_iterator		rend(void) {
				return (reverse_iterator(this->_bst.minimum(this->_bst.getRoot())));
		}

		const_reverse_iterator	rend(void) const {
				return (const_reverse_iterator(this->_bst.minimum(this->_bst.getRoot())));
		}

		////////////////////////////////////////////////////////////////
		///						Capacity Functions					////
		////////////////////////////////////////////////////////////////

		bool		empty(void) const {
				if (this->_bst.getSize() == 0)
						return (true);
				return (false);
		}

		size_type	size(void) const {
				return (this->_bst.getSize());
		}

		size_type	max_size(void) const {
				return (this->_alloc.max_size());
		}

		////////////////////////////////////////////////////////////////
		///						Element Access						////
		////////////////////////////////////////////////////////////////

		mapped_type&		operator [] (const key_type& k) {
				iterator	it = this->_bst.find(k);

				return (it->pair._first);
		}

		mapped_type&		at(const key_type& k) {
				iterator	it = this->_bst.find(k);

				if (it->_ptr == this->_bst.getNull())
						throw std::out_of_range("Out of Range");
				return (it->pair._first);
		}

		const mapped_type&	at(const key_type& k) const {
				iterator	it = this->_bst.find(k);

				if (it->_ptr == this->_bst.getNull())
						throw std::out_of_range("Out of Range");
				return (it->pair._first);
		}

		////////////////////////////////////////////////////////////////
		///						Modifiers Functions					////
		////////////////////////////////////////////////////////////////

		ft::pair<iterator, bool>	insert(const value_type& val) {
				bool		isNew;
				iterator	it;

				isNew = this->_bst.insertNode(val);
				it = this->_bst.find(val->_first);
				return (ft::make_pair(it, isNew));
		}

		iterator					insert(iterator position, const value_type& val) {
				iterator	it;

				this->_bst.insertNode(val);
				it = this->_bst.find(val->_first);
				return (it);
		}

		template <class InputIterator>
		void	insert (typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last) {
				while (first != last) {
						this->_bst.insertNode(first->pair);
						first++;
				}
		}

		void		erase(iterator position) {
				this->_bst.deleteNode(position->pair._first);
		}

		size_type	erase(const key_type& k) {
				if (this->_bst.deleteNode(k))
						return (1);
				return (0);
		}

		void		erase(iterator first, iterator last) {
				while (first != last) {
						this->_bst.deleteNode(first->pair._first);
						first++;
				}
		}

		void		swap(map& x) {
				BST<Key, T, Compare>	tmp;

				tmp = this->_bst;
				this->_bst = x._bst;
				x._bst = tmp;
		}

		void		clear(void) {
				if (this->_bst.getRoot() != NULL)
						this->_bst.clearTree();
		}

		////////////////////////////////////////////////////////////////
		///						Observers Functions					////
		////////////////////////////////////////////////////////////////

		key_compare		key_comp(void) const {
				return (this->_compare);
		}

		value_compare	value_comp(void) const {
				return (value_compare());
		}

		////////////////////////////////////////////////////////////////
		///							Operations						////
		////////////////////////////////////////////////////////////////

		iterator		find(const key_type& k) {
				iterator	it = this->_bst.find(k);

				if (it->_ptr == this->_bst.getNull())
						return (this->end());
				return (it);
		}

		const_iterator	find(const key_type& k) const {
				const_iterator	it = this->_bst.find(k);

				if (it->_ptr == this->_bst.getNull())
						return (this->end());
				return (it);
		}

		size_type		count(const key_type& k) const {
				iterator	it = this->_bst.find(k);

				if (it->_ptr == this->_bst.getNull())
						return (0);
				return (1);
		}

		iterator		lower_bound(const key_type& k) {
				return (this->_bst.lower(k));
		}

		const_iterator	lower_bound(const key_type& k) const {
				return (this->_bst.lower(k));
		}

		iterator		upper_bound(const key_type& k) {
				return (this->_bst.upper(k));
		}

		const_iterator	upper_bound(const key_type& k) const {
				return (this->_bst.upper(k));
		}

		ft::pair<const_iterator, const_iterator>	equal_range(const key_type& k) const {
				return (ft::make_pair(this->lower_bound(k), this->upper_bound(k)));
		}

		ft::pair<iterator, iterator>				equal_range(const key_type& k) {
				return (ft::make_pair(this->lower_bound(k), this->upper_bound(k)));
		}

		////////////////////////////////////////////////////////////////
		///							Allocator						////
		////////////////////////////////////////////////////////////////

		allocator_type		get_allocator(void) const {
				return (this->_alloc);
		}

}; // class

/*		////////////////////////////////////////////////////////////////
		///					Non-Member Functions					////
		////////////////////////////////////////////////////////////////
		
		////////////////////////////////////////////////////////////////
		///					Relational Operators					////
		////////////////////////////////////////////////////////////////

		template <class Key, class T, class Compare, class Alloc>
		bool	operator == (const ft::map<Key, T, Compare, Alloc>& lhs, const ft::map<Key, T, Compare, Alloc>& rhs);

		template <class Key, class T, class Compare, class Alloc>
		bool	operator != (const ft::map<Key, T, Compare, Alloc>& lhs, const ft::map<Key, T, Compare, Alloc>& rhs);

		template <class Key, class T, class Compare, class Alloc>
		bool	operator < (const ft::map<Key, T, Compare, Alloc>& lhs, const ft::map<Key, T, Compare, Alloc>& rhs);

		template <class Key, class T, class Compare, class Alloc>
		bool	operator <= (const ft::map<Key, T, Compare, Alloc>& lhs, const ft::map<Key, T, Compare, Alloc>& rhs);

		template <class Key, class T, class Compare, class Alloc>
		bool	operator > (const ft::map<Key, T, Compare, Alloc>& lhs, const ft::map<Key, T, Compare, Alloc>& rhs);

		template <class Key, class T, class Compare, class Alloc>
		bool	operator >= (const ft::map<Key, T, Compare, Alloc>& lhs, const ft::map<Key, T, Compare, Alloc>& rhs);

		////////////////////////////////////////////////////////////////
		///							Overload						////
		////////////////////////////////////////////////////////////////

		template <class Key, class T, class Compare, class Alloc>
		void	swap(ft::map<Key, T, Compare, Alloc>& lhs, ft::map<Key, T, Compare, Alloc>& rhs);
*/

} // namespace

#endif
