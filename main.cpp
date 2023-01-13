/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:41:24 by lduboulo          #+#    #+#             */
/*   Updated: 2023/01/13 15:04:28 by lulutalu         ###   ########.fr       */
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

		test.insertNode(ft::pair<int, std::string>(10, "Ten"));
		test.insertNode(ft::pair<int, std::string>(20, "Twenty"));
		test.insertNode(ft::pair<int, std::string>(15, "Fifteen"));
		test.insertNode(ft::pair<int, std::string>(30, "Thirty"));
		test.insertNode(ft::pair<int, std::string>(40, "Forty"));
		test.insertNode(ft::pair<int, std::string>(25, "Twenty-Five"));

		test.printTree(test.getRoot(), 0);

		test.leftRotate(test.getRoot());

		test.printTree(test.getRoot(), 0);

		test.leftRotate(test.getRoot());

		test.printTree(test.getRoot(), 0);

		test.rightRotate(test.getRoot());

		test.printTree(test.getRoot(), 0);
}
