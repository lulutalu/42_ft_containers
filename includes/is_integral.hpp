/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:21:59 by lduboulo          #+#    #+#             */
/*   Updated: 2023/01/12 15:08:45 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS_INTEGRAL_HPP
# define IS_INTEGRAL_HPP

# include <string>

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
 *		- wchar_t
 *		- signed char
 *		- short int
 *		- int
 *		- long int
 *		- long long int (long long is a c++ extension)
 *		- unsigned char
 *		- unsigned short int
 *		- unsigned int
 *		- unsigned long int
 *		- unsigned long long int (long long is a c++11 extension)
 *
 *		Note : const types are also considered integral. Same for volatile types
*/

template<> struct is_integral<bool> : public integral_constant<true, bool> {};

template<> struct is_integral<char> : public integral_constant<true, char> {};

template<> struct is_integral<wchar_t> : public integral_constant<true, wchar_t> {};

template<> struct is_integral<signed char> : public integral_constant<true, signed char> {};

template<> struct is_integral<short int> : public integral_constant<true, short int> {};

template<> struct is_integral<int> : public integral_constant<true, int> {};

template<> struct is_integral<long int> : public integral_constant<true, long int> {};

template<> struct is_integral<unsigned char> : public integral_constant<true, unsigned char> {};

template<> struct is_integral<unsigned short int> : public integral_constant<true, unsigned short int> {};

template<> struct is_integral<unsigned int> : public integral_constant<true, unsigned int> {};

template<> struct is_integral<unsigned long int> : public integral_constant<true, unsigned long int> {};



template<> struct is_integral<const bool> : public integral_constant<true, const bool> {};

template<> struct is_integral<const char> : public integral_constant<true, const char> {};

template<> struct is_integral<const wchar_t> : public integral_constant<true, const wchar_t> {};

template<> struct is_integral<const signed char> : public integral_constant<true, const signed char> {};

template<> struct is_integral<const short int> : public integral_constant<true, const short int> {};

template<> struct is_integral<const int> : public integral_constant<true, const int> {};

template<> struct is_integral<const long int> : public integral_constant<true, const long int> {};

template<> struct is_integral<const unsigned char> : public integral_constant<true, const unsigned char> {};

template<> struct is_integral<const unsigned short int> : public integral_constant<true, const unsigned short int> {};

template<> struct is_integral<const unsigned int> : public integral_constant<true, const unsigned int> {};

template<> struct is_integral<const unsigned long int> : public integral_constant<true, const unsigned long int> {};


template<> struct is_integral<volatile bool> : public integral_constant<true, volatile bool> {};

template<> struct is_integral<volatile char> : public integral_constant<true, volatile char> {};

template<> struct is_integral<volatile wchar_t> : public integral_constant<true, volatile wchar_t> {};

template<> struct is_integral<volatile signed char> : public integral_constant<true, volatile signed char> {};

template<> struct is_integral<volatile short int> : public integral_constant<true, volatile short int> {};

template<> struct is_integral<volatile int> : public integral_constant<true, volatile int> {};

template<> struct is_integral<volatile long int> : public integral_constant<true, volatile long int> {};

template<> struct is_integral<volatile unsigned char> : public integral_constant<true, volatile unsigned char> {};

template<> struct is_integral<volatile unsigned short int> : public integral_constant<true, volatile unsigned short int> {};

template<> struct is_integral<volatile unsigned int> : public integral_constant<true, volatile unsigned int> {};

template<> struct is_integral<volatile unsigned long int> : public integral_constant<true, volatile unsigned long int> {};

} // namespace

#endif
