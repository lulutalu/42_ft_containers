/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulutalu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 17:36:20 by lulutalu          #+#    #+#             */
/*   Updated: 2023/01/25 15:45:22 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

# include "vector.hpp"

namespace ft {

template <class T, class Container = ft::vector<T> >
class stack
{

		public :

				////////////////////////////////////////////////////////////////
				///						Member Types						////
				////////////////////////////////////////////////////////////////

				typedef T				value_type;
				typedef Container		container_type;
				typedef std::size_t		size_type;

				////////////////////////////////////////////////////////////////
				///						Member Functions					////
				////////////////////////////////////////////////////////////////

/*				explicit stack(const container_type& cntr = container_type());  //Constructor

				bool				empty(void) const;							// Boolean function to check if the container is empty
				size_type			size(void) const;							// Return the size of the container
				value_type&			top(void);									// Return a reference to the top value of the stack
				const value_type&	top(void) const;
				void				push(const value_type& val);				// Insert new element at the top of the stack
				void				pop(void);									// Remove top element of the stack
				void				swap(stack& x);								// Swap two stack
*/

		protected :

				container_type		c;

		public :

				explicit stack(const container_type& cntr = container_type()) : c(cntr) {}

				bool				empty(void) const {
						return (this->c.empty());
				}

				size_type			size(void) const {
						return (this->c.size());
				}

				value_type&			top(void) {
						return (this->c.back());
				}

				const value_type&	top(void) const {
						return (this->c.back());
				}

				void				push(const value_type& val) {
						this->c.push_back(val);
				}

				void				pop(void) {
						this->c.pop_back();
				}

				void				swap(stack& x) {
						stack	tmp;

						tmp = *this;

						this = x;
						x = tmp;
				}

				friend bool	operator == (const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
						return (lhs.c == rhs.c);
				}

				friend bool	operator != (const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
						return (lhs.c != rhs.c);
				}

				friend bool	operator < (const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
						return (lhs.c < rhs.c);
				}

				friend bool	operator <= (const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
						return (lhs.c <= rhs.c);
				}

				friend bool	operator > (const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
						return (lhs.c > rhs.c);
				}

				friend bool	operator >= (const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
						return (lhs.c >= rhs.c);
				}

				friend void	swap(stack<T, Container>& x, stack<T, Container>& y) {
						x.swap(y);
				}


}; // class

		////////////////////////////////////////////////////////////////////////
		///						Relational Operators						////
		////////////////////////////////////////////////////////////////////////

/*		template <class T, class Container>
		bool	operator == (const stack<T, Container>& lhs, const stack<T, Container>& rhs);

		template <class T, class Container>
		bool	operator != (const stack<T, Container>& lhs, const stack<T, Container>& rhs);

		template <class T, class Container>
		bool	operator < (const stack<T, Container>& lhs, const stack<T, Container>& rhs);

		template <class T, class Container>
		bool	operator <= (const stack<T, Container>& lhs, const stack<T, Container>& rhs);

		template <class T, class Container>
		bool	operator > (const stack<T, Container>& lhs, const stack<T, Container>& rhs);

		template <class T, class Container>
		bool	operator >= (const stack<T, Container>& lhs, const stack<T, Container>& rhs);


		////////////////////////////////////////////////////////////////////////
		///							Functions Overload						////
		////////////////////////////////////////////////////////////////////////

		template <class T, class Container>
		void	swap(stack<T, Container>& x, stack<T, Container>& y);
*/
	
} // namespace

#endif
