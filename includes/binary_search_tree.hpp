/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_search_tree.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulutalu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:11:32 by lulutalu          #+#    #+#             */
/*   Updated: 2023/01/13 14:14:16 by lulutalu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BINARY_SEARCH_TREE
# define BINARY_SEARCH_TREE

# include "pair.hpp"

# include <functional>
# include <iostream>

namespace ft {

template <class Key, class T>
struct Node {


		bool						color; 	// true -> red, false -> black
		ft::pair<const Key, T>		pair;	// grant access to key and value
		Node*						lChild;	// pointer to left child of node
		Node*						rChild;	// pointer to right child of node
		Node*						parent;	// pointer to parend of node

		Node(ft::pair<const Key, T> newPair) : 
				color(true), pair(newPair), lChild(NULL), rChild(NULL), parent(NULL) {}

};

/*
 * The five rules of Red-Black-BST are as follow :
 * 		1. Every Node are colored, either red or black
 * 		2. The root Node is always colored black
 * 		3. Every Leaf are colored black
 * 		4. If a red Node has children, then the two children nodes are always colored black
 * 		5. For all the path inside the BST, the number of black nodes encounter from root to leaves must be the same
*/

template <class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::Node<Key, T> > >
class BST
{
		public :

				typedef Node<Key, T>	Node;
				typedef Node*			NodePtr;
				typedef Alloc			allocator_type;
				typedef Compare			comp_operation;

		private :
				
				NodePtr				_root;
				Compare				_comp;
				Alloc				_alloc;
				std::size_t			_size;

		public :

/*				BST(void);													// Constructor of empty BST

				~BST(void);													// Destructor /!\ Need to free all of the nodes /!\

				void	insertNode(ft::pair<const Key, T> newPair);			// Insert new Node with the parameter newPair<const Key, T>

				void	deleteNode(Key& key);								// Delete a Node with the parameter key

				void	insertFix(void);									// After inserting new node check if the 5 rules of Red-Black-BST are respected

				void	deleteFix(void);									// After deleting a node check if the 5 rules of Red-Black-BST are respected

				void	recolor(NodePtr node);								// Change the color of the node in parameter

				void	leftRotate(NodePtr node);							// Make the operation lrotate to the node in parameter

				void	rightRotate(NodePtr node);							// Make the operation rrotate to the node in parameter
*/

				BST(const comp_operation& comp = comp_operation(), const allocator_type& alloc = allocator_type()) 
						: _root(NULL), _comp(comp), _alloc(alloc), _size(0) {}

				std::size_t		getSize(void) const {
						return (this->_size);
				}

				NodePtr			getRoot(void) const {
						return (this->_root);
				}

				void	insertNode(ft::pair<const Key, T> newPair) {
						if (this->_root == NULL) {
								NodePtr		newNode = NULL;

								newNode = _alloc.allocate(1);
								_alloc.construct(newNode, Node(newPair));
								this->_root = newNode;
								recolor(this->_root);
						}
						else {
								NodePtr		cur = this->_root;
								NodePtr		ptrParent = NULL;
								int			dir;

								while (cur != NULL) {

										if (cur->pair._first == newPair._first) // check if the key already exist inside the BST
												return ;

										else if (this->_comp(newPair._first, cur->pair._first)) {
												ptrParent = cur;
												cur = cur->lChild;
												dir = 0;
										}

										else {
												ptrParent = cur;
												cur = cur->rChild;
												dir = 1;
										}
								}

								NodePtr		newNode = NULL;

								newNode = _alloc.allocate(1);
								_alloc.construct(newNode, Node(newPair));
								newNode->parent = ptrParent;
								if (dir == 0)
										ptrParent->lChild = newNode;
								else
										ptrParent->rChild = newNode;
								cur = newNode;
						}
						this->_size++;
				}

				/* We need to bring modifications to 4 nodes.
				 * First 'node' : parent and rChild will change
				 * Then 'node->rChild' : parent and lChild will change.
				 * Also 'node->parent' : lChild or rChild will change depending of prev pos of 'node'
				 * Finally 'node->rChild->lChild : parent will change. */
				void	leftRotate(NodePtr x) {
						if (x->rChild == NULL)
								return ;

						NodePtr		y = x->rChild;

						x->rChild = y->lChild;

						if (x->rChild != NULL)
								x->rChild->parent = x;

						y->lChild = x;

						y->parent = x->parent;
						if (y->parent == NULL)
								this->_root = y;
						else if (y->parent->lChild == x)
								y->parent->lChild = y;
						else
								y->parent->rChild = y;

						x->parent = y;
				}

				void	recolor(NodePtr node) { node->color = !node->color; }

				void	printTree(NodePtr root, int space) const {
						if (root == NULL)
								return ;
						space += 5;
						printTree(root->rChild, space);
						std::cout << std::endl;
						for (int i = 5; i < space; i++)
								std::cout << " ";

						std::string		strCol;

						if (root->color)
								strCol = "\033[1;31m";
						else
								strCol = "\033[0m";
						std::cout << strCol << root->pair._second << "\033[0m" << std::endl;
						printTree(root->lChild, space);
				}

}; // BST class

} // namespace

#endif
