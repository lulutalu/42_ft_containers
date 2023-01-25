/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:50:13 by lduboulo          #+#    #+#             */
/*   Updated: 2023/01/25 16:01:45 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#if 0

		namespace ft = std;
		#include <vector>
		#include <map>
		#include <stack>

#else

		#include <vector>
		#include <vector.hpp>
		#include <map.hpp>
		#include <stack.hpp>

#endif

class B {
public:
    char *l;
    int i;
    B():l(nullptr), i(1) {};
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
public:
    A():B(){};
    A(const B* ex){
        this->l = new char(*(ex->l));
        this->i = ex->i;
        if (ex->i == -1) throw "n";
    }
    ~A() {
        delete this->l;
        this->l = nullptr;
    };
};

int	main(void) {

		std::vector<int> 	v;
		ft::vector<int>		vector;
		ft::vector<int> 	tmp;

		tmp.assign(2600, 1);
		vector.assign(4200, 1);
		vector.insert(vector.end() - 1000, tmp.begin(), tmp.end());
		v.push_back(vector[3]);
		v.push_back(vector.size());
		v.push_back(vector.capacity());

		std::unique_ptr<B> k2(new B(3));
		std::unique_ptr<B> k3(new B(4));
		std::unique_ptr<B> k4(new B(-1));
		std::vector<A> vv;
		std::vector<B*> v1;

		v1.push_back(&(*k2));
		v1.push_back(&(*k3));
		v1.push_back(&(*k4));
		try { vv.insert(vv.begin(), v1.begin(), v1.end()); }
		catch (...) {
			v.push_back(vv.size());
			v.push_back(vv.capacity());
		}

		for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++)
				std::cout << *it << std::endl;


		ft::map<int, std::string> mp;

	mp[42] = "lol";

	mp[50] = "mdr";
	mp[25] = "funny";

	mp[46] = "bunny";
	mp[21] = "fizz";
	mp[30] = "buzz";
	mp[55] = "fuzzy";

	mp[18] = "bee";
	mp[23] = "coconut";
	mp[28] = "diary";
	mp[35] = "fiesta";
	mp[44] = "hello";
	mp[48] = "world";
	mp[53] = "this is a test";
	mp[80] = "hey";

	mp[12] = "no";
	mp[20] = "idea";
	mp[22] = "123";
	mp[24] = "345";
	mp[27] = "27";
	mp[29] = "29";
	mp[33] = "33";
	mp[38] = "38";

	mp[43] = "1";
	mp[45] = "2";
	mp[47] = "3";
	mp[49] = "4";
	mp[51] = "5";
	mp[54] = "6";
	mp[60] = "7";
	mp[90] = "8";


	/* A classic btree should give this:
	 *                                      42
	 *                     /                                            \
	 *                    25                                            50
	 *           /                 \                         /                       \
	 *          21                 30                       46                       55
	 *      /       \           /      \                /       \             /           \
	 *     18       23        28        35            44         48         53             80
	 *   /   \    /    \    /    \     /   \        /   \       /   \     /    \         /     \
	 *  12   20  22    24  27    29  33    38     43    45    47    49   51    54       60      90
	 *
	 * */

	mp.erase(25); // right != NULL; left != NULL
	mp.erase(55); // right != NULL; left != NULL

	/* After deleting 25 and 55, I would get:
	 *                                      42
	 *                     /                                            \
	 *                    24                                            50
	 *           /                 \                         /                      \
	 *          21                 30                       46                      54
	 *      /       \           /      \                /       \             /           \
	 *     18       23        28        35            44         48         53             80
	 *   /   \    /         /    \     /   \        /   \       /   \     /              /     \
	 *  12   20  22        27    29  33    38     43    45    47    49   51             60      90
	 *
	 * */

	mp.erase(24); // right != NULL; left != NULL
	mp.erase(54); // right != NULL; left != NULL

	/* After deleting 24 and 54, I would get:
	 *                                      42
	 *                     /                                            \
	 *                    23                                            50
	 *           /                 \                         /                      \
	 *          21                 30                       46                      53
	 *      /       \           /      \                /       \             /           \
	 *     18       22        28        35            44         48         51             80
	 *   /   \              /    \     /   \        /   \       /   \                    /     \
	 *  12   20            27    29  33    38     43    45    47    49                  60      90
	 *
	 * */

	mp.erase(22); // right == NULL; left == NULL
	mp.erase(51); // right == NULL; left == NULL

	mp.erase(21); // right == NULL; left != NULL
	mp.erase(53); // right != NULL; left == NULL

	/* After deleting 22, 51 and then 21, 53, I would get:
	 *                                      42
	 *                     /                                            \
	 *                    23                                            50
	 *           /                 \                         /                      \
	 *          20                 30                       46                      80
	 *      /                   /      \                /       \                /        \
	 *     18                 28        35            44         48             60         90
	 *   /                  /    \     /   \        /   \       /   \
	 *  12                 27    29  33    38     43    45    47    49
	 *
	 * */

	mp.erase(20); // right == NULL; left != NULL

	/* After deleting 20, I would get:
	 *                                      42
	 *                     /                                            \
	 *                    23                                            50
	 *           /                 \                         /                      \
	 *          18                 30                       46                      80
	 *      /                   /      \                /       \                /        \
	 *     12                 28        35            44         48             60         90
	 *                      /    \     /   \        /   \       /   \
	 *                     27    29  33    38     43    45    47    49
	 *
	 * */

	mp.erase(23); // right != NULL; left != NULL

	/* After deleting 23, I would get:
	 *                                      42
	 *                     /                                            \
	 *                    18                                            50
	 *           /                 \                         /                      \
	 *          12                 30                       46                      80
	 *                          /      \                /       \                /        \
	 *                        28        35            44         48             60         90
	 *                      /    \     /   \        /   \       /   \
	 *                     27    29  33    38     43    45    47    49
	 *
	 * */

	mp.erase(42); // right != NULL; left != NULL; parent == NULL

	/* After deleting 42, I would get:
	 *                                      38
	 *                     /                                            \
	 *                    18                                            50
	 *           /                 \                         /                      \
	 *          12                 30                       46                      80
	 *                          /      \                /       \                /        \
	 *                        28        35            44         48             60         90
	 *                      /    \     /            /   \       /   \
	 *                     27    29  33           43    45    47    49
	 *
	 * */

	mp.erase(38); // right != NULL; left != NULL; parent == NULL

	/* After deleting 38, I would get:
	 *                                      35
	 *                     /                                            \
	 *                    18                                            50
	 *           /                 \                         /                      \
	 *          12                 30                       46                      80
	 *                          /      \                /       \                /        \
	 *                        28        33            44         48             60         90
	 *                      /    \                  /   \       /   \
	 *                     27    29               43    45    47    49
	 *
	 * */

	mp.erase(35); // right != NULL; left != NULL; parent == NULL

	/* After deleting 35, I would get:
	 *                                      33
	 *                     /                                            \
	 *                    18                                            50
	 *           /                 \                         /                      \
	 *          12                 30                       46                      80
	 *                          /                       /       \                /        \
	 *                        28                      44         48             60         90
	 *                      /    \                  /   \       /   \
	 *                     27    29               43    45    47    49
	 *
	 * */

	mp.erase(33); // right != NULL; left != NULL; parent == NULL

	/* After deleting 33, I would get:
	 *                                      30
	 *                     /                                            \
	 *                    18                                            50
	 *           /                 \                         /                      \
	 *          12                 28                       46                      80
	 *                          /      \                /       \                /        \
	 *                        27       29             44         48             60         90
	 *                                              /   \       /   \
	 *                                            43    45    47    49
	 *
	 * */

		for (ft::map<int, std::string>::iterator it = mp.begin(); it != mp.end(); it++)
				std::cout << it->first << "\t" << it->second << std::endl;

}
