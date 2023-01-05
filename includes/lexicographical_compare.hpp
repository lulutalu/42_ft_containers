/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexicographical_compare.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulutalu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 15:28:45 by lulutalu          #+#    #+#             */
/*   Updated: 2023/01/05 15:51:21 by lulutalu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXICOGRAPHICAL_COMPARE
# define LEXICOGRAPHICAL_COMPARE

namespace ft {

		/*
		 * The function will return true if [first1, last1] range is
		 * lexicographically less than [first2, last2] range
		 * 
		 * Basically, if the value of *first2 is smaller than *first1 we return false
		 * because in that case [first2, last2] range is lexicographically less than [first1, last1] range. (1)
		 * And the opposite if *first1 is smaller than *first2 (2)
		 *
		 * At the end of the loop, if the condition (first2 != last2) equal at true, it means that
		 * the [first1, last1] range was smaller in size than the [first2, last2] range
		 * thus returning true.
		*/

		template <class InputIterator>
		bool	lexicographical_compare(InputIterator first1, InputIterator last1, InputIterator first2, InputIterator last2) {
				while (first1 != last1) {
						if (first2 == last2 || *first2 < *first1)	// (1)
								return (false);
						else if (*first1 < *first2)					// (2)
								return (true);
						first1++;
						first2++;
				}
				return (first2 != last2);
		}

		template <class InputIterator, class Compare>
		bool	lexicographical_compare(InputIterator first1, InputIterator last1, InputIterator first2, InputIterator last2, Compare comp) {
				while (first1 != last1) {
						if (first2 == last2 || comp(*first2, *first1))
								return (false);
						else if (comp(*first1, *first2))
								return (true);
						first1++;
						first2++;
				}
				return (first2 != last2);
		}

		template <class InputIterator1, class InputIterator2>
		bool	lexicographical_compare(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2) {
				while (first1 != last1) {
						if (first2 == last2 || *first2 < *first1)
								return (false);
						else if (*first1 < *first2)
								return (true);
						first1++;
						first2++;
				}
				return (first2 != last2);
		}

		template <class InputIterator1, class InputIterator2, class Compare>
		bool	lexicographical_compare(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2, Compare comp) {
				while (first1 != last1) {
						if (first2 == last2 || comp(*first2, *first1))
								return (false);
						else if (comp(*first1, *first2))
								return (true);
						first1++;
						first2++;
				}
				return (first2 != last2);
		}

} // namespace

#endif
