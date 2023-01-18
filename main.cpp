/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:41:24 by lduboulo          #+#    #+#             */
/*   Updated: 2023/01/18 18:33:09 by lulutalu         ###   ########.fr       */
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
		test.insertNode(ft::pair<int, std::string>(100, "Hundred"));
		test.insertNode(ft::pair<int, std::string>(60, "Sixty"));
		test.insertNode(ft::pair<int, std::string>(80, "Eighty"));
		test.insertNode(ft::pair<int, std::string>(50, "Fifty"));
		test.insertNode(ft::pair<int, std::string>(59, "Fifty-Nine"));
		test.insertNode(ft::pair<int, std::string>(70, "Seventy"));

		test.printTree(test.getRoot(), 0);

		test.deleteNode(80);

		std::cout << "\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\" << std::endl;

		test.printTree(test.getRoot(), 0);

		test.deleteNode(70);

		std::cout << "\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\" << std::endl;

		test.printTree(test.getRoot(), 0);
		
		test.deleteNode(60);

		std::cout << "\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\" << std::endl;

		test.printTree(test.getRoot(), 0);

		test.deleteNode(10);

		std::cout << "\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\" << std::endl;

		test.printTree(test.getRoot(), 0);

}
