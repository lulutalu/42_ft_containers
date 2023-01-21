/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:41:24 by lduboulo          #+#    #+#             */
/*   Updated: 2023/01/21 19:38:07 by lulutalu         ###   ########.fr       */
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

int		main(void)
{
	std::list<ft::pair<const int, std::string> > lst;
	unsigned int lst_size = 1;
	for (unsigned int i = 0; i < lst_size; ++i)
		lst.push_back(ft::make_pair(i, std::string((lst_size - i), i + 65)));
	ft::map<const int, std::string> mp(lst.begin(), lst.end());
//	printSize(mp);

//	mp.erase(++mp.begin());

//	mp.erase(mp.begin());
//	mp.erase(--mp.end());

//	mp.erase(mp.begin(), ++(++(++mp.begin())));
//	mp.erase(--(--(--mp.end())), --mp.end());

//	mp[10] = "Hello";
//	mp[11] = "Hi there";
//	printSize(mp);
//	mp.erase(--(--(--mp.end())), mp.end());

//	mp[12] = "ONE";
//	mp[13] = "TWO";
//	mp[14] = "THREE";
//	mp[15] = "FOUR";
//	printSize(mp);
//	mp.erase(mp.begin(), mp.end());

	return (0);
}
