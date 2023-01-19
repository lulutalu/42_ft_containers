/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:41:24 by lduboulo          #+#    #+#             */
/*   Updated: 2023/01/19 18:40:30 by lulutalu         ###   ########.fr       */
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
		ft::BST<int, std::string>			test;
		ft::BST<int, std::string>			cpy;

		test.insertNode(ft::pair<int, std::string>(10, "Ten"));
		test.insertNode(ft::pair<int, std::string>(20, "Twenty"));
		test.insertNode(ft::pair<int, std::string>(5, "Five"));
		test.insertNode(ft::pair<int, std::string>(15, "Fifteen"));

		test.printTree(test.getRoot(), 0);

		std::cout << "#####################################" << std::endl << std::endl;

		cpy.insertNode(ft::pair<int, std::string>(5, "Five"));
		cpy.insertNode(ft::pair<int, std::string>(10, "Ten"));
		cpy.insertNode(ft::pair<int, std::string>(15, "Fifteen"));
		cpy.insertNode(ft::pair<int, std::string>(20, "Twenty"));
		cpy.insertNode(ft::pair<int, std::string>(30, "Thirty"));

		cpy.printTree(cpy.getRoot(), 0);
}
