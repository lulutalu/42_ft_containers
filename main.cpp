/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:41:24 by lduboulo          #+#    #+#             */
/*   Updated: 2023/01/23 18:06:22 by lulutalu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if 0

# include <memory>
# include <iostream>
# include <vector>
# include <iterator>
# include <map>
# include <string>
# include <list>

namespace ft = std;

#else

# include <vector.hpp>
# include <map.hpp>
# include <binary_search_tree.hpp>
# include <vector>
# include <list>

#endif

int	main(void) {

    std::vector<int> v;
		ft::map<int, int>	mp;

    for (int i = 0, j = 0; i < 100 * 100000; ++i, ++j)
        mp.insert(ft::make_pair(i, j));
    v.push_back(mp.size());
    for (int i = 0; i < 43 * 100000; ++i)
        mp.erase(i);
    v.push_back(mp.size());

	for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++)
			std::cout << *it << std::endl;
}
