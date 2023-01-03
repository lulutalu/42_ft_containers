/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:21:59 by lduboulo          #+#    #+#             */
/*   Updated: 2023/01/03 17:15:32 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS_INTEGRAL_HPP
# define IS_INTEGRAL_HPP

namespace ft {

template <bool is_integral, typename T>
struct integral_constant {
		static const bool value = is_integral;
		typedef T value_type;
};

template <typename T>
struct is_integral : public integral_constant<false, T> {};

/* Integral Types :
 *		- bool
 *		- char
 *		- char16_t
 *		- char32_t
 *		- wchar_t
 *		- signed char
 *		- short int
 *		- int
 *		- long int
 *		- long long int
 *		- unsigned char
 *		- unsigned short int
 *		- unsigned int
 *		- unsigned long int
 *		- unsigned long long int
*/

template<> struct is_integral<bool> : public integral_constant<true, bool> {};

template<> struct is_integral<char> : public integral_constant<true, char> {};

template<> struct is_integral<char16_t> : public integral_constant<true, char16_t> {};

template<> struct is_integral<char32_t> : public integral_constant<true, char32_t> {};

template<> struct is_integral<wchar_t> : public integral_constant<true, wchar_t> {};

template<> struct is_integral<signed char> : public integral_constant<true, signed char> {};

template<> struct is_integral<short int> : public integral_constant<true, short int> {};

template<> struct is_integral<int> : public integral_constant<true, int> {};

template<> struct is_integral<long int> : public integral_constant<true, long int> {};

template<> struct is_integral<long long int> : public integral_constant<true, long long int> {};

template<> struct is_integral<unsigned char> : public integral_constant<true, unsigned char> {};

template<> struct is_integral<unsigned short int> : public integral_constant<true, unsigned short int> {};

template<> struct is_integral<unsigned int> : public integral_constant<true, unsigned int> {};

template<> struct is_integral<unsigned long int> : public integral_constant<true, unsigned long int> {};

template<> struct is_integral<unsigned long long int> : public integral_constant<true, unsigned long long int> {};

} // namespace

#endif
