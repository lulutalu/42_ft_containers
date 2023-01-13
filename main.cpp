/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:41:24 by lduboulo          #+#    #+#             */
/*   Updated: 2023/01/13 16:18:07 by lulutalu         ###   ########.fr       */
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

# include <vector.hpp>
# include <map.hpp>
# include <binary_search_tree.hpp>
# include <vector>

#endif


int	main(void) {
		ft::BST<int, std::string>		test;

		test.insertNode(ft::pair<int, std::string>(0, "Zero"));
		test.insertNode(ft::pair<int, std::string>(5, "Five"));
		test.insertNode(ft::pair<int, std::string>(-5, "- Five"));
		test.insertNode(ft::pair<int, std::string>(10, "Ten"));
		test.insertNode(ft::pair<int, std::string>(-1, "- One"));
		test.insertNode(ft::pair<int, std::string>(12, "Twelve"));
		test.insertNode(ft::pair<int, std::string>(15, "Fifteen"));
		test.insertNode(ft::pair<int, std::string>(14, "Fourteen"));
		test.insertNode(ft::pair<int, std::string>(4, "Four"));
		test.insertNode(ft::pair<int, std::string>(3, "Three"));
		test.insertNode(ft::pair<int, std::string>(-15, "- Fifteen"));
		test.insertNode(ft::pair<int, std::string>(-8, "- Eight"));
		test.insertNode(ft::pair<int, std::string>(-10, "- Ten"));

		test.printTree(test.getRoot(), 0);
}
