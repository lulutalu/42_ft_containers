/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:41:24 by lduboulo          #+#    #+#             */
/*   Updated: 2023/01/19 18:50:38 by lulutalu         ###   ########.fr       */
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

		std::allocator<std::pair<const int, std::string> >		alloc;

		std::cout << alloc.max_size() << std::endl;

}
