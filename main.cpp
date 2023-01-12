/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:41:24 by lduboulo          #+#    #+#             */
/*   Updated: 2023/01/12 17:13:48 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if 0

# include <memory>
# include <iostream>
# include <vector>
# include <iterator>
# include <map>
# include <string>

namespace ft = std;

#else

# include "includes/vector.hpp"
# include "includes/map.hpp"
# include "includes/binary_search_tree.hpp"
# include <vector>

#endif


int	main(void) {
		ft::BST<int, std::string>		test;

		test.insertNode(ft::pair<int, std::string>(10, "Ten"));
		test.insertNode(ft::pair<int, std::string>(5, "Five"));
		test.insertNode(ft::pair<int, std::string>(20, "Twenty"));
		test.insertNode(ft::pair<int, std::string>(1, "One"));
		test.insertNode(ft::pair<int, std::string>(7, "Seven"));
		test.insertNode(ft::pair<int, std::string>(4, "Four"));
		test.insertNode(ft::pair<int, std::string>(55, "Fifty-Five"));
		test.insertNode(ft::pair<int, std::string>(15, "Fifteen"));

		test.printTree(test.getRoot(), 0);
}
