/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_search_tree.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulutalu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:11:32 by lulutalu          #+#    #+#             */
/*   Updated: 2023/01/18 16:42:14 by lulutalu         ###   ########.fr       */
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
		ft::pair<Key, T>			pair;	// grant access to key and value
		Node*						lChild;	// pointer to left child of node
		Node*						rChild;	// pointer to right child of node
		Node*						parent;	// pointer to parend of node

		Node(ft::pair<Key, T> newPair) : 
				color(true), pair(newPair), lChild(NULL), rChild(NULL), parent(NULL) {}

		Node(void) : color(false), pair(), lChild(NULL), rChild(NULL), parent(NULL) {}
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
				NodePtr				_null;
				Compare				_comp;
				Alloc				_alloc;
				std::size_t			_size;

		public :

/*				BST(void);													// Constructor of empty BST

				~BST(void);													// Destructor /!\ Need to free all of the nodes /!\

				void	insertNode(ft::pair<const Key, T> newPair);			// Insert new Node with the parameter newPair<const Key, T>

				void	deleteNode(Key& key);								// Delete a Node with the parameter key

				void	insertFix(NodePtr x);								// After inserting new node check if the 5 rules of Red-Black-BST are respected

				void	deleteFix(void);									// After deleting a node check if the 5 rules of Red-Black-BST are respected

				void	recolor(NodePtr node);								// Change the color of the node in parameter

				void	leftRotate(NodePtr node);							// Make the operation lrotate to the node in parameter

				void	rightRotate(NodePtr node);							// Make the operation rrotate to the node in parameter
*/

				BST(const comp_operation& comp = comp_operation(), const allocator_type& alloc = allocator_type()) 
						: _root(NULL), _comp(comp), _alloc(alloc), _size(0) {
						_null = _alloc.allocate(1);
						_alloc.construct(_null, Node());
						_null->color = false;
						_null->lChild = NULL;
						_null->rChild = NULL;
						_null->parent = NULL;
						_root = _null;
						}

				std::size_t		getSize(void) const {
						return (this->_size);
				}

				NodePtr			getRoot(void) const {
						return (this->_root);
				}

				void	insertNode(ft::pair<Key, T> newPair) {
						if (this->_root == this->_null) {
								NodePtr		newNode = NULL;

								newNode = _alloc.allocate(1);
								_alloc.construct(newNode, Node(newPair));
								newNode->lChild = this->_null;
								newNode->rChild = this->_null;
								this->_root = newNode;
								recolor(this->_root);
								this->_size++;
								return ;
						}
						else {
								NodePtr		cur = this->_root;
								NodePtr		ptrParent = NULL;
								int			dir;

								while (cur != this->_null) {

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
								newNode->rChild = this->_null;
								newNode->lChild = this->_null;
								newNode->parent = ptrParent;
								if (dir == 0)
										ptrParent->lChild = newNode;
								else
										ptrParent->rChild = newNode;
								cur = newNode;
								this->_size++;
								insertFix(cur);
						}
				}

				void	insertFix(NodePtr x) {
						NodePtr		gp = NULL;
						bool		r;
						bool		uncle = true;

						if (x->parent->parent != NULL) {
								gp = x->parent->parent;
								if (gp->lChild == x->parent)
										r = false;
								else
										r = true;
								if ((r && gp->lChild == this->_null) || (!r && gp->rChild == this->_null))
										uncle = false;
						}

						if (x->parent->color) { // Parent is red
								if ((r && (gp->lChild != this->_null && gp->lChild->color)) || (!r && (gp->rChild != this->_null && gp->rChild->color))) { // Both Uncle and Parent are red
										if (gp != this->_root)
												recolor(gp);
										recolor(gp->lChild);
										recolor(gp->rChild);
								}
								else if (!uncle || ((r && !gp->lChild->color) || (!r && !gp->rChild->color))) { // Uncle is black
										if (r && x->parent->rChild == x) {							// Parent is rChild of GrandParent and x is rChild of Parent
												leftRotate(gp);
												recolor(gp);
												recolor(x->parent);
										}
										else if (r && x->parent->lChild == x) {						// Parent is rChild of GrandParent and x is lChild of Parent
												rightRotate(x->parent);
												leftRotate(gp);
												recolor(gp);
												recolor(x);
										}
										else if (!r && x->parent->lChild == x) {					// Parent is lChild of GrandParent and x is lChild of Parent
												rightRotate(gp);
												recolor(gp);
												recolor(x->parent);
										}
										else if (!r && x->parent->rChild == x) {					// Parent is lChild of GrandParent anx x is rChild of Parent
												leftRotate(x->parent);
												rightRotate(gp);
												recolor(gp);
												recolor(x);
										}
								}
						}
				}

				void	deleteNode(const Key& key) {
						NodePtr		cur;
						NodePtr		y;
						NodePtr		par = NULL;
						bool		oldColor = true;

						cur = this->_root;
						while (cur != NULL && cur->pair._first != key) {
								if (this->_comp(key, cur->pair._first))
										cur = cur->lChild;
								else
										cur = cur->rChild;
						}
						if (cur == NULL) {
								std::cout << "No occurence found" << std::endl;
								return ;
						}

						if (cur->lChild != NULL && cur->rChild != NULL) {							// If cur has two child
								y = minimum(cur->rChild);
								if (y->parent != cur) {
										y->parent->lChild = y->rChild;
										if (y->rChild != NULL)
												y->rChild->color = y->color;
								}
								oldColor = false;
								cur->pair = y->pair;
								_alloc.destroy(y);
								_alloc.deallocate(y, 1);
						}
						else if (cur->lChild == NULL && cur->rChild == NULL) {						// If cur has no Child
								oldColor = !cur->color;
								if (cur->parent->lChild == cur) {
										cur->parent->lChild = NULL;
										par = cur->parent;
								}
								else {
										cur->parent->rChild = NULL;
										par = cur->parent;
								}
								if (this->_root == cur)
										this->_root = NULL;
								_alloc.destroy(cur);
								_alloc.deallocate(cur, 1);
						}
						else if (cur->lChild != NULL) {												// If cur has a lChild
								y = cur->lChild;
								cur->pair = y->pair;
								cur->lChild = NULL;
								oldColor = !y->color;
								par = cur;
								_alloc.destroy(y);
								_alloc.deallocate(y, 1);
						}
						else {																		// If cur has a rChild
								y = cur->rChild;
								cur->pair = y->pair;
								cur->rChild = NULL;
								oldColor = !y->color;
								par = cur;
								_alloc.destroy(y);
								_alloc.deallocate(y, 1);
						}
						if (oldColor)
								std::cout << "Node was black" << std::endl;
						else
								std::cout << "Node was red" << std::endl;
						if (oldColor)
								deleteFix(par);
				}

				void	deleteFix(NodePtr x) {
						NodePtr		sibling = NULL;
						bool		dir;

						if (x->rChild == NULL) {
								sibling = x->lChild;
								dir = true;
						}
						else {
								sibling = x->rChild;
								dir = false;
						}

						if (!dir) {
								if (sibling->color) {												// If the sibling color is red
										recolor(sibling);
										x->color = true;
										leftRotate(x);
										x = sibling->lChild;
								}																	// If both the sibling's child color is black
								else if ((sibling->lChild == NULL || !sibling->lChild->color) && (sibling->rChild == NULL || !sibling->rChild->color)) {
										sibling->color = true;
										x = x->parent;
								}																	// If the rChild of sibling is black
								else if ((sibling->rChild == NULL || !sibling->rChild->color)) {
										if (sibling->lChild != NULL)
												sibling->lChild->color = false;
										sibling->color = true;
										rightRotate(sibling);
								}
								else {
										sibling->color = x->color;
										x->parent->color = false;
										if (sibling->rChild != NULL)
												sibling->rChild->color = false;
										leftRotate(x);
								}

								if (x != this->_root && !x->color)
										deleteFix(x);

						}
				}

				NodePtr	minimum(NodePtr x) {
						while (x->lChild != this->_null) {
								x = x->lChild;
						}
						return (x);
				}

				/* We need to bring modifications to 4 nodes.
				 * First 'node' : parent and rChild will change
				 * Then 'node->rChild' : parent and lChild will change.
				 * Also 'node->parent' : lChild or rChild will change depending of prev pos of 'node'
				 * Finally 'node->rChild->lChild : parent will change. */
				void	leftRotate(NodePtr x) {
						if (x->rChild == this->_null)
								return ;

						NodePtr		y = x->rChild;

						x->rChild = y->lChild;

						if (x->rChild != this->_null)
								x->rChild->parent = x;

						y->lChild = x;

						y->parent = x->parent;
						if (y->parent == this->_null)
								this->_root = y;
						else if (y->parent->lChild == x)
								y->parent->lChild = y;
						else
								y->parent->rChild = y;

						x->parent = y;
				}

				/*
				 * Same as leftRotate, 4 nodes need to be manipulated
				 * x : x->parent and x->lChild will change
				 * y : y->parent and y->rChild will change
				 * x->parent : either lChild or rChild need to be change
				 * y->rChild : parent will change
				*/
				void	rightRotate(NodePtr x) {
						if (x->lChild == this->_null)
								return ;

						NodePtr		y = x->lChild;

						x->lChild = y->rChild;

						if (x->lChild != this->_null)
								x->lChild->parent = x;

						y->rChild = x;

						y->parent = x->parent;
						if (y->parent == this->_null)
								this->_root = y;
						else if (y->parent->lChild == x)
								y->parent->lChild = y;
						else
								y->parent->rChild = y;

						x->parent = y;
				}

				void	recolor(NodePtr node) { node->color = !node->color; }

				void	printTree(NodePtr root, int space) const {
						if (root == this->_null)
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
