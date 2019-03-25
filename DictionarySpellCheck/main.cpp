//
//  main.cpp
//  DictionarySpellCheck
//
//  Created by Michael Gosling on 2019-03-23.
//  Copyright © 2019 Michael Gosling. All rights reserved.
//

#include <iostream>
#include "SpellChecker.hpp"

int main(int argc, const char * argv[]) {
	// create new spellchecker
	SpellChecker checker("dictionary.txt");

	// print out tree
	checker.printTree();

	// check mispelled file
	checker.Check("mispelled.txt");
	
	return 0;
}
