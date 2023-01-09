/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:41:24 by lduboulo          #+#    #+#             */
/*   Updated: 2023/01/09 15:04:02 by lulutalu         ###   ########.fr       */
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

class B {
public :
		char *l;
		int i;
		B() : l(nullptr), i(1) {};
		B(const int &ex) {
				this->i = ex;
				this->l = new char('a');
		};
		virtual ~B() {
				delete this->l;
				this->l = nullptr;
		};
};

class A : public B {
public :
		A() : B() {};
		A(const B* ex) {
				this->l = new char(*(ex->l));
				this->i = ex->i;
				if (ex->i == -1) throw "n";
		}

		~A() {
				delete this->l;
				this->l = nullptr;
		};
};

int	main(void)
{
		std::vector<int>	v;
		ft::vector<int>		vector;
		ft::vector<int>		tmp;

		tmp.assign(2600, 1);
		vector.assign(4200, 1);
		vector.insert(vector.end() - 1000, tmp.begin(), tmp.end());
		v.push_back(vector[3]);
		std::cout << vector[3] << std::endl;
		v.push_back(vector.size());
		std::cout << vector.size() << std::endl;
		v.push_back(vector.capacity());
		std::cout << vector.capacity() << std::endl;

		std::unique_ptr<B> k2(new B(3));
		std::unique_ptr<B> k3(new B(4));
		std::unique_ptr<B> k4(new B(-1));

		ft::vector<A>	vv;
		ft::vector<B*>	v1;

		v1.push_back(&(*k2));
		v1.push_back(&(*k3));
		v1.push_back(&(*k4));
		try { vv.insert(vv.begin(), v1.begin(), v1.end()); }
		catch (...) {
				v.push_back(vv.size());
				v.push_back(vv.capacity());
		}

		std::cout << vv.capacity() << std::endl;

		std::cout << "###############" << std::endl;
		std::cout << "Final vector : " << std::endl;

		for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++)
				std::cout << *it << std::endl;
}
