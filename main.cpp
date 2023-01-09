/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:41:24 by lduboulo          #+#    #+#             */
/*   Updated: 2023/01/09 13:13:24 by lulutalu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if 0

# include <memory>
# include <iostream>
# include <vector>
# include <iterator>

namespace ft = std;

#else

# include "includes/vector.hpp"
# include <vector>

#endif

int	main(void)
{
		std::vector<int>	v;
		ft::vector<int>		base;
		ft::vector<int>		tmp0(base);
		ft::vector<int>		tmp(1000, 4), tmp2(1000, 5);

		tmp = tmp2;

		std::cout << "########################################################" << std::endl;
		std::cout << "Printing tmp vector which should be equal to tmp2 vector" << std::endl;

		for (ft::vector<int>::iterator it = tmp.begin(); it != tmp.end(); it++)
				std::cout << *it++ << std::endl;

		ft::vector<int>		tmp3(tmp);
		ft::vector<int>		tmp4(tmp.begin(), tmp.end());
		v.push_back(tmp4.size());
		std::cout << "push_back : " << tmp4.size() << std::endl;
		v.push_back(tmp4.capacity());
		std::cout << "push_back : " << tmp4.capacity() << std::endl;
		v.push_back(tmp[2]);
		std::cout << "push_back : " << tmp[2] << std::endl;
		v.push_back(tmp3[2]);
		std::cout << "push_back : " << tmp3[2] << std::endl;
		v.push_back(tmp4[2]);
		std::cout << "push_back : " << tmp4[2] << std::endl;
		try { ft::vector<int>	tmp5(-1, -1); }
		catch (std::exception& e) { v.push_back(1); }

		std::cout << "##########################" << std::endl << "Vector v contains : " << std::endl;

		for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++)
				std::cout << *it++ << std::endl;
}
