//
//  BinaryTree.cpp
//  DictionarySpellCheck
//
//  Created by Michael Gosling on 2019-03-23.
//  Copyright © 2019 Michael Gosling. All rights reserved.
//

#include "BinaryTree.hpp"

/* Functions sourced/modified from https://www.geeksforgeeks.org/binary-search-tree-set-1-search-and-insertion/ */

/**
 * Creates a new Node
 */
struct node* BinaryTree::newNode(std::string item){
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->key = item;
	temp->left = temp->right = nullptr;
	return temp;
}

/**
 * Inserts a new node into the binary search tree
 */
struct node* BinaryTree::insert(struct node* node, std::string key){
	// If the tree is empty, return a new node with the given key
	if (node == NULL) return newNode(key);

	// Insert the key left or right of the node depending on it's compared value
	if (key.compare(node->key) < 0)
		node->left  = insert(node->left, key);
	else if (key.compare(node->key) > 0)
		node->right = insert(node->right, key);

	// Return the node itself if the key matches
	return node;
}

/**
 * Inserts a new node into the binary search tree
 */
struct node* BinaryTree::insert(std::string key) {
	return insert(root, key);
}

/**
 * Searches binary tree for given key
 */
struct node* BinaryTree::search(struct node* root, std::string key) {
	// if the root key matches or is null, return the root
	if (root == NULL || root->key == key)
		return root;

	// if the root key is alphabetically before the given key, search the roots right and return
	if (key.compare(root->key) > 0)
		return search(root->right, key);

	// if we got this far, search the roots left and return
	return search(root->left, key);
}

/**
 * Searches binary tree for a given key
 */
struct node* BinaryTree::search(std::string key) {
	return search(this->root, key);
}
