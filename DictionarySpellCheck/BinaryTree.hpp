//
//  BinaryTree.hpp
//  DictionarySpellCheck
//
//  Created by Michael Gosling on 2019-03-23.
//  Copyright © 2019 Michael Gosling. All rights reserved.
//

#ifndef BinaryTree_hpp
#define BinaryTree_hpp

#include <stdio.h>
#include <string>

struct node {
	std::string key;
	struct node *left, *right;
};

class BinaryTree {
private:
	struct node* root;
	struct node* insert(struct node* node, std::string key);
	struct node* search(struct node* root, std::string key);
public:
	struct node* newNode(std::string item);
	struct node* insert(std::string key);
	struct node* search(std::string key);
};

#endif /* BinaryTree_hpp */
