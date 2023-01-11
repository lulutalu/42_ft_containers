/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:41:24 by lduboulo          #+#    #+#             */
/*   Updated: 2023/01/11 17:17:51 by lulutalu         ###   ########.fr       */
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

# include "includes/vector.hpp"
# include "includes/map.hpp"
# include <vector>

#endif


int	main(void) {
		ft::map<std::string, char>	map;

		map["Pouet"] = 'N';
		map["Rat"] = 'R';
		map["Nul"] = 'P';

		map.insert(ft::pair<std::string, char>("Coucou", 'C'));

		ft::map<std::string, char>::iterator it = map.begin();

		std::cout << it->second << std::endl;
		it++;
		std::cout << it->second << std::endl;
		it++;
		std::cout << it->second << std::endl;
}
