/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:41:24 by lduboulo          #+#    #+#             */
/*   Updated: 2022/12/10 20:50:15 by lulutalu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if 1

# include <memory>
# include <iostream>
# include <vector>

namespace ft = std;

# else

# include "includes/vector.hpp"

#endif

int	main(void)
{
		ft::vector<int>	vec(130, 5);

		std::cout << vec.back() << std::endl;
		std::cout << vec[130] << std::endl;
		std::cout << vec.capacity() << std::endl;
		vec.reserve(200);
		std::cout << vec.capacity() << std::endl;
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
