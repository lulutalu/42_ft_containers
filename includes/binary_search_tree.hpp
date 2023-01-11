/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_search_tree.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulutalu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:11:32 by lulutalu          #+#    #+#             */
/*   Updated: 2023/01/11 17:42:47 by lulutalu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BINARY_SEARCH_TREE
# define BINARY_SEARCH_TREE

# include "pair.hpp"
# include <functional>

namespace ft {

template <class Key, class T>
struct Node {

		int							color; 	// 1 -> red, 0 -> black
		ft::pair<const Key, T>		pair;	// grant access to key and value
		Node*						lChild;	// pointer to left child of node
		Node*						rChild;	// pointer to right child of node
		Node*						parent;	// pointer to parend of node

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

				typedef Node<Key, T>*	NodePtr;

		private :
				
				NodePtr				_root;
				Compare				_comp;
				Alloc				_alloc;

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

}; // BST class

} // namespace

#endif
