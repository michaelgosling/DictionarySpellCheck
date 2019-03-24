//
//  BinaryTree.hpp
//  DictionarySpellCheck
//
//  Created by Michael Gosling on 2019-03-23.
//  Copyright © 2019 Michael Gosling. All rights reserved.
//

#ifndef BinaryTree_hpp
#define BinaryTree_hpp

#include <iostream>
#include <stdio.h>
#include <string>

class Node {
public:
	std::string key;
	Node *left, *right;
	int height;
};

class BinaryTree {
private:
	int height(Node *N);
	int max(int a, int b);
	Node* newNode(std::string key);
	Node *rightRotate(Node *y);
	Node *leftRotate(Node *x);
	int getBalance(Node *N);
public:
	Node* insert(Node* node, std::string key);
	void print(Node* node, int indent=0);
};

#endif /* BinaryTree_hpp */
