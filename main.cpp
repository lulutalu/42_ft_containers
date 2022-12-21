/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:41:24 by lduboulo          #+#    #+#             */
/*   Updated: 2022/12/21 17:11:15 by lulutalu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if 1

# include <memory>
# include <iostream>
# include <vector>
# include <iterator>

namespace ft = std;

# else

# include "includes/vector.hpp"

#endif

int	main(void)
{
		ft::vector<int>	vec;
		ft::vector<int>::iterator	it;

		vec.push_back(1);
		vec.push_back(2);
		it = vec.begin();
		std::cout << vec.capacity() << std::endl;
		vec.assign(2, 10);
		std::cout << vec.capacity() << std::endl;
		std::cout << it[0] << std::endl;
		std::cout << it[1] << std::endl;
		std::cout << it[2] << std::endl;
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
