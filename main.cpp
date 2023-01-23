/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:41:24 by lduboulo          #+#    #+#             */
/*   Updated: 2023/01/23 19:00:20 by lulutalu         ###   ########.fr       */
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
    std::vector<int> v;
	ft::map<int, int>	mp;
	ft::pair<ft::map<int, int>::iterator , bool> pair = mp.insert(ft::make_pair(7, 7));

	ft::map<int, int>::iterator it = mp.begin();
v.push_back(it->first);
v.push_back(it->second);
v.push_back(pair.first->first);
v.push_back(pair.first->second);
v.push_back(pair.second);
mp.insert(ft::make_pair(9, 9));
ft::pair<ft::map<int, int>::iterator , bool> pair2 = mp.insert(ft::make_pair(9, 9));
ft::map<int, int>::iterator it2 = pair.first;
v.push_back(it2->first);
v.push_back(it2->second);
v.push_back(pair2.first->first);
v.push_back(pair2.first->second);
v.push_back(pair2.second);
for (int i = 0, j = 0; i < 4; ++i, ++j) {
	mp.insert(ft::make_pair(i, j));
}
std::cout << mp.size() << std::endl;
ft::map<int, int>::iterator it3 = mp.begin();
for (; it3 != mp.end(); ++it3) {
	v.push_back(it3->first);
	v.push_back(it3->second);
}
v.push_back(mp.size());

for (std::vector<int>::iterator cc = v.begin(); cc != v.end(); cc++)
std::cout << *cc << std::endl;

}
