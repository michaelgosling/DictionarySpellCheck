//
//  SpellChecker.hpp
//  DictionarySpellCheck
//
//  Created by Michael Gosling on 2019-03-23.
//  Copyright © 2019 Michael Gosling. All rights reserved.
//

#ifndef SpellChecker_hpp
#define SpellChecker_hpp

#include <stdio.h>
#include <string>
#include <vector>
#include "BinaryTree.hpp"

class SpellChecker {
private:
	BinaryTree dict;
	Node* root;
	std::string dictFileName;
	void readDictionary();
	bool checkSpelling(std::string word);
public:
	SpellChecker(std::string dictionaryFileName);
	void Check(std::string fileName);
	void printTree();
};

#endif /* SpellChecker_hpp */
