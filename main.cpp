/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:41:24 by lduboulo          #+#    #+#             */
/*   Updated: 2023/01/20 21:24:19 by lulutalu         ###   ########.fr       */
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
	std::list<ft::pair<int, int> > lst;
	ft::map<int, int>::iterator		cc;
	unsigned int lst_size = 7;
	for (unsigned int i = 0; i < lst_size; ++i)
		lst.push_back(ft::make_pair(lst_size - i, i));

	ft::map<int, int> mp(lst.begin(), lst.end());
//	ft::map<int, int>::iterator it = mp.begin();
	ft::map<int, int>::iterator ite = mp.end();

		std::cout << ite->first << "\t" << ite->second << std::endl;

		--ite;
		std::cout << ite->first << "\t" << ite->second << std::endl;

/*	ft::map<int, int> mp_range(it, --(--ite));

	std::cout << ite->first << "\t" << ite->second << std::endl;

	for (int i = 0; it != ite; ++it)
		it->second = ++i * 5;

	it = mp.begin(); ite = --(--mp.end());
	ft::map<int, int> mp_copy(mp);
	for (int i = 0; it != ite; ++it)
		it->second = ++i * 7;

	std::cout << "\t-- PART ONE --" << std::endl;
	for (cc = mp.begin(); cc != mp.end(); cc++)
			std::cout << cc->first << "\t" << cc->second << std::endl;
	std::cout << "#################################" << std::endl << std::endl;
	for (cc = mp_range.begin(); cc != mp_range.end(); cc++)
			std::cout << cc->first << "\t" << cc->second << std::endl;
	std::cout << "#################################" << std::endl << std::endl;
	for (cc = mp_copy.begin(); cc != mp_copy.end(); cc++)
			std::cout << cc->first << "\t" << cc->second << std::endl;
//	printSize(mp);
//	printSize(mp_range);
//	printSize(mp_copy);

	mp = mp_copy;
	mp_copy = mp_range;
	mp_range.clear();

	std::cout << "\t-- PART TWO --" << std::endl;
//	printSize(mp);
//	printSize(mp_range);
//	printSize(mp_copy);*/
}
