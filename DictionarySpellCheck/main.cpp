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
	SpellChecker checker("dictionary.txt");
	checker.printTree();
	return 0;
}
