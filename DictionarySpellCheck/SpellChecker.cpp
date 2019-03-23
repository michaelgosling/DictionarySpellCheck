//
//  SpellChecker.cpp
//  DictionarySpellCheck
//
//  Created by Michael Gosling on 2019-03-23.
//  Copyright © 2019 Michael Gosling. All rights reserved.
//

#include "SpellChecker.hpp"
#include <fstream>
#include <iostream>

/**
 * Read dictionary file
 */
void SpellChecker::readFile(){
	std::ifstream file;
	std::string line;
	try {
		file.open(fileName);
		if (file.is_open()){
			while (!file.eof()){
				dict.insert(line);
			}
			file.close();
		}
	} catch (std::exception e){
		std::cout << e.what() << std::endl;
	}
}

/**
 * Check spelling of given string and return true or false
 */
bool SpellChecker::checkSpelling(std::string word){
	return false;
}

/**
 * Initialize spell checker with given file name.
 */
SpellChecker::SpellChecker(std::string dictionaryFileName){
	this->fileName = dictionaryFileName;
	readFile();
}

/**
 * Check word for spelling and print if its wrong.
 */
void SpellChecker::Check(std::string word){
	if (!checkSpelling(word))
		std::cout << word << std::endl;
}
