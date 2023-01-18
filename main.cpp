/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:41:24 by lduboulo          #+#    #+#             */
/*   Updated: 2023/01/18 16:42:25 by lulutalu         ###   ########.fr       */
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

		test.insertNode(ft::pair<int, std::string>(55, "Fifty-Five"));
		test.insertNode(ft::pair<int, std::string>(65, "Sixty-Five"));
		test.insertNode(ft::pair<int, std::string>(45, "Forty-Five"));
		test.insertNode(ft::pair<int, std::string>(60, "Sixty"));
		test.insertNode(ft::pair<int, std::string>(75, "Seventy-Five"));
		test.insertNode(ft::pair<int, std::string>(57, "Fifty-Seven"));

		test.printTree(test.getRoot(), 0);
}
