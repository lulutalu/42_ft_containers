/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:41:24 by lduboulo          #+#    #+#             */
/*   Updated: 2023/01/06 20:16:11 by lulutalu         ###   ########.fr       */
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
		ft::vector<int>						vec;

		for (int i = 0; i < 10; i++)
				vec.push_back(i);

		ft::vector<int>::iterator			it = vec.begin();

		it++;

		ft::vector<int>::reverse_iterator	rev_it(it);

		std::cout << *it << std::endl;
		std::cout << *rev_it << std::endl;

		ft::vector<int>::iterator			it2 = rev_it.base();

		std::cout << *it2 << std::endl;

		rev_it = vec.rbegin();

		std::cout << *(rev_it + 3) << std::endl;
}
