/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:41:24 by lduboulo          #+#    #+#             */
/*   Updated: 2023/01/19 15:58:39 by lulutalu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if 1

# include <memory>
# include <iostream>
# include <vector>
# include <iterator>
# include <map>
# include <string>

namespace ft = std;

#else

# include <vector.hpp>
# include <map.hpp>
# include <binary_search_tree.hpp>
# include <vector>

#endif


int	main(void) {
		ft::map<int, std::string>			test;
		ft::map<int, std::string>::iterator	it;

		test.insert(ft::pair<int, std::string>(100, "Ten"));
		test.insert(ft::pair<int, std::string>(200, "Twenty"));
		test.insert(ft::pair<int, std::string>(150, "Five"));
		test.insert(ft::pair<int, std::string>(250, "Five"));

		for (it = test.begin(); it != test.end(); it++)
				std::cout << it->first << std::endl;
}
