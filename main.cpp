/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:41:24 by lduboulo          #+#    #+#             */
/*   Updated: 2022/12/26 21:43:51 by lulutalu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if 1

# include <memory>
# include <iostream>
# include <vector>
# include <iterator>

namespace ft = std;

#else

# include "includes/vector.hpp"

#endif

int	main(void)
{
		ft::vector<int>	vec;
		ft::vector<int>::iterator	it;

		std::cout << "Capacity : " << vec.capacity() << std::endl;
		vec.insert(vec.begin(), 10, 5);
		std::cout << "Capacity : " << vec.capacity() << std::endl;
		for (it = vec.begin(); it != vec.end(); it++)
				std::cout << *it << std::endl;
		std::cout << "======================================================" << std::endl;
		vec.insert(vec.end(), 12, 10);
		std::cout << "Capacity : " << vec.capacity() << std::endl;
		for (it = vec.begin(); it != vec.end(); it++)
				std::cout << *it << std::endl;
		return (0);

/*	int						*ptr;
	std::allocator<int>		alloc;
	int						i = -1;
	int						N = 10;

	try {
		ptr = alloc.allocate(N);
	}
	catch (std::bad_alloc &e) {
		std::cout << "bad allocation of memory : " << e.what() << std::endl;
	}
	while (++i < N)
		alloc.construct(ptr + i, i);
	i = -1;
	while (++i < N)
		alloc.destroy(ptr + i);
	alloc.deallocate(ptr, N);*/
}
