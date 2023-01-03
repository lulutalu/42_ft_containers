/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_if.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:09:50 by lduboulo          #+#    #+#             */
/*   Updated: 2023/01/03 16:14:12 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENABLE_IF_HPP
# define ENABLE_IF_HPP

namespace ft {

template <bool Cond, class T = void()> struct enable_if {};

template <class T> struct enable_if<true, T> { typedef T type; };

} // namespace

/*
 * Type T is define as member type of enable_if::type if the boolean Cond is true
*/

#endif
