/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equal.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulutalu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 15:06:17 by lulutalu          #+#    #+#             */
/*   Updated: 2023/01/05 15:21:53 by lulutalu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EQUAL_HPP
# define EQUAL_HPP

namespace ft {

		template <class InputIterator>
		bool	equal(InputIterator first1, InputIterator last1, InputIterator first2) {
				while (first1 != last1) {
						if (*first1 != *first2)
								return (false);
						first1++;
						first2++;
				}
				return (true);
		}

		template <class InputIterator, class BinaryPredicate>
		bool	equal(InputIterator first1, InputIterator last1, InputIterator first2, BinaryPredicate pred) {
				while (first1 != last1) {
						if (!pred(*first1, *first2))
								return (false);
						first1++;
						first2++;
				}
				return (true);
		}

		template <class InputIterator1, class InputIterator2>
		bool	equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2) {
				while (first1 != last1) {
						if (*first1 != *first2)
								return (false);
						first1++;
						first2++;
				}
				return (true);
		}

		template <class InputIterator1, class InputIterator2, class BinaryPredicate>
		bool	equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, BinaryPredicate pred) {
				while (first1 != last1) {
						if (!pred(*first1, *first2))
								return (false);
						first1++;
						first2++;
				}
				return (true);
		}

} // namespace

#endif
