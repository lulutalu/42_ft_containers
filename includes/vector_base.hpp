/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_base.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:51:05 by lduboulo          #+#    #+#             */
/*   Updated: 2022/12/06 17:32:45 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <memory>

explicit vector(const allocator_type& alloc = allocator_type()) : _alloc(alloc), _pointer(NULL) {}
