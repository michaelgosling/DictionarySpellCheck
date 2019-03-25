//
//  BinaryTree.cpp
//  DictionarySpellCheck
//
//  Created by Michael Gosling on 2019-03-23.
//  Copyright © 2019 Michael Gosling. All rights reserved.
//

#include "BinaryTree.hpp"
#include <iomanip>

/**
 * Get height of node
 */
int BinaryTree::height(Node *node) {
	if (node == nullptr) return 0;
	return node->height;
}

/**
 * Get max of 2 integers
 */
int BinaryTree::max(int a, int b) {
	return (a > b)? a : b;
}

/**
 * Create new node with given key
 */
Node* BinaryTree::newNode(std::string key) {
	Node* node = new Node();
	node->key = key;
	node->left = nullptr;
	node->right = nullptr;
	node->height = 1;
	return(node);
}

/**
 * Rotate right
 */
Node* BinaryTree::rightRotate(Node *currentRoot) {
	Node *newRoot = currentRoot->left;
	Node *newLeft = newRoot->right;

	// Perform rotation
	newRoot->right = currentRoot;
	currentRoot->left = newLeft;

	// Update heights
	currentRoot->height = max(height(currentRoot->left),
							  height(currentRoot->right)) + 1;
	newRoot->height = max(height(newRoot->left),
						  height(newRoot->right)) + 1;

	// Return new root
	return newRoot;
}

/**
 * Rotate Left
 */
Node* BinaryTree::leftRotate(Node *currentRoot) {
	Node *newRoot = currentRoot->right;
	Node *newRight = newRoot->left;

	// Perform rotation
	newRoot->left = currentRoot;
	currentRoot->right = newRight;

	// Update heights
	currentRoot->height = max(height(currentRoot->left),
					height(currentRoot->right)) + 1;
	newRoot->height = max(height(newRoot->left),
					height(newRoot->right)) + 1;

	// Return new root
	return newRoot;
}

/**
 * Get balance of node
 */
int BinaryTree::getBalance(Node *node) {
	if (node == nullptr) return 0;
	return height(node->left) - height(node->right);
}

/**
 * Insert key/node into tree
 */
Node* BinaryTree::insert(Node* node, std::string key) {
	if (node == nullptr)
		return(newNode(key));

	// if the key's value is smaller than the node key's value, insert to left,
	// if the key's value is greater than the node key's value, insert right,
	// else return given node
	if (key.compare(node->key) < 0)
		node->left = insert(node->left, key);
	else if (key.compare(node->key) > 0)
		node->right = insert(node->right, key);
	else // Equal keys are not allowed in BST
		return node;

	// Update height of this node
	node->height = 1 + max(height(node->left),
						   height(node->right));

	// check balance
	int balance = getBalance(node);

	// If it's unbalanced, balance it:

	// Left Left Case
	if (balance > 1 && key.compare(node->left->key) < 0)
		return rightRotate(node);

	// Right Right Case
	if (balance < -1 && key.compare(node->right->key) > 0)
		return leftRotate(node);

	// Left Right Case
	if (balance > 1 && key.compare(node->left->key) > 0) {
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}

	// Right Left Case
	if (balance < -1 && key.compare(node->right->key) < 0) {
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}

	// return unchanged node pointer
	return node;
}

Node* BinaryTree::search(Node* node, std::string key){
	// if node's key matches, return it
	if (node == nullptr || node->key == key)
		return node;

	// if node's key is smaller than key, search right node
	if (key.compare(node->key) > 0)
		return search(node->right, key);

	// if node's key is bigger than key, search left node
	return search(node->left, key);
}

/**
 * Print tree
 */
void BinaryTree::print(Node* node, int indent) {
	if(node != nullptr) {
		if(node->right)	print(node->right, indent+5);
		if (indent) std::cout << std::setw(indent) << ' ';
		if (node->right) std::cout<<" /\n" << std::setw(indent) << ' ';
		std::cout<< node->key << "\n ";
		if(node->left) {
			std::cout << std::setw(indent) << ' ' <<" \\\n";
			print(node->left, indent+5);
		}
	}
//	if( node != nullptr )
//	{
//		print(node->right, indent + 5 );
//		std::cout << std::setw(indent) << node->key << std::endl;
//		print(node->left, indent + 5 );
//	}
}
