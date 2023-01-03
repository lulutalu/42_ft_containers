/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:41:24 by lduboulo          #+#    #+#             */
/*   Updated: 2023/01/03 14:21:51 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if 0

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
		ft::vector<int>	vec(5, 5);
//		ft::vector<int>	range (10, 1);
		ft::vector<int>::iterator	it;

		std::cout << "Capacity before op : " << vec.capacity() << std::endl;
		vec.push_back(1);
		vec.push_back(2);
		std::cout << "Capacity after op : " << vec.capacity() << std::endl;
		for (it = vec.begin(); it != vec.end(); it++)
			std::cout << *it << std::endl;
		std::cout << "======================================================" << std::endl;
		std::cout << *(vec.erase(vec.begin() + 2, vec.end() - 2)) << std::endl;
		std::cout << "======================================================" << std::endl;
		for (it = vec.begin(); it != vec.end(); it++)
				std::cout << *it << std::endl;
		std::cout << "Size : " << vec.size() << std::endl;
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
