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
	std::string fileName;
	void readFile();
	bool checkSpelling(std::string word);
public:
	SpellChecker(std::string fileName);
	void Check(std::string word);
};

#endif /* SpellChecker_hpp */
