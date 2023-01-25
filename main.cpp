/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:41:24 by lduboulo          #+#    #+#             */
/*   Updated: 2023/01/25 13:59:34 by lduboulo         ###   ########.fr       */
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
		ft::map<int, int>		mp;
		ft::map<int, int>		mp2;

		mp.insert(ft::make_pair(29, 54));
		mp.insert(ft::make_pair(97, 123));
		mp.insert(ft::make_pair(25, 87));
		mp.insert(ft::make_pair(896, 64));
		mp.insert(ft::make_pair(75, 93));
		mp.insert(ft::make_pair(57, 28));
		mp.insert(ft::make_pair(24, 76));

		mp2.insert(ft::make_pair(85, 10));
		mp2.insert(ft::make_pair(16, 92));
		mp2.insert(ft::make_pair(36, 600));
		mp2.insert(ft::make_pair(93, 61));
		mp2.insert(ft::make_pair(15, 98));

		for (ft::map<int, int>::iterator it = mp.begin(); it != mp.end(); it++)
				std::cout << it->first << "\t" << it->second << std::endl;

		std::cout << "########################################" << std::endl;

		for (ft::map<int, int>::iterator it = mp2.begin(); it != mp2.end(); it++)
				std::cout << it->first << "\t" << it->second << std::endl;

		mp.swap(mp2);

		std::cout << "+++++++++++++++++++++++++++++++++++++++++++++" << std::endl;

		for (ft::map<int, int>::iterator it = mp.begin(); it != mp.end(); it++)
				std::cout << it->first << "\t" << it->second << std::endl;

		std::cout << "########################################" << std::endl;

		for (ft::map<int, int>::iterator it = mp2.begin(); it != mp2.end(); it++)
				std::cout << it->first << "\t" << it->second << std::endl;

}
