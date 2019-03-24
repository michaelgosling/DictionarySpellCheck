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
int BinaryTree::height(Node *N) {
	if (N == nullptr)
		return 0;
	return N->height;
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
Node* BinaryTree::rightRotate(Node *y) {
	Node *x = y->left;
	Node *T2 = x->right;

	// Perform rotation
	x->right = y;
	y->left = T2;

	// Update heights
	y->height = max(height(y->left), height(y->right)) + 1;
	x->height = max(height(x->left), height(x->right)) + 1;

	// Return new root
	return x;
}

/**
 * Rotate Left
 */
Node* BinaryTree::leftRotate(Node *x) {
	Node *y = x->right;
	Node *T2 = y->left;

	// Perform rotation
	y->left = x;
	x->right = T2;

	// Update heights
	x->height = max(height(x->left),
					height(x->right)) + 1;
	y->height = max(height(y->left),
					height(y->right)) + 1;

	// Return new root
	return y;
}

/**
 * Get balance of node
 */
int BinaryTree::getBalance(Node *N) {
	if (N == nullptr)
		return 0;
	return height(N->left) - height(N->right);
}

Node* BinaryTree::insert(Node* node, std::string key) {
	/* 1. Perform the normal BST insertion */
	if (node == nullptr)
		return(newNode(key));

	if (key.compare(node->key) < 0)
		node->left = insert(node->left, key);
	else if (key.compare(node->key) > 0)
		node->right = insert(node->right, key);
	else // Equal keys are not allowed in BST
		return node;

	/* 2. Update height of this ancestor node */
	node->height = 1 + max(height(node->left),
						   height(node->right));

	/* 3. Get the balance factor of this ancestor
	 node to check whether this node became
	 unbalanced */
	int balance = getBalance(node);

	// If this node becomes unbalanced, then
	// there are 4 cases

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

	/* return the (unchanged) node pointer */
	return node;
}

/**
 * Print tree
 */
void BinaryTree::print(Node* node, int indent) {
	if(node != nullptr) {
		if(node->right)	print(node->right, indent+4);
		if (indent) std::cout << std::setw(indent) << ' ';
		if (node->right) std::cout<<" /\n" << std::setw(indent) << ' ';
		std::cout<< node->key << "\n ";
		if(node->left) {
			std::cout << std::setw(indent) << ' ' <<" \\\n";
			print(node->left, indent+4);
		}
	}
}
