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
void SpellChecker::readDictionary(){
	std::ifstream file;
	std::string line;
	root = nullptr;
	try {
		file.open(dictFileName);
		if (file.is_open()){
			while (getline(file, line))
				root = dict.insert(root, line);
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
	Node* searchResult = dict.search(root, word);
	if (searchResult != nullptr && searchResult->key == word) return true;
	else return false;
}

/**
 * Initialize spell checker with given file name.
 */
SpellChecker::SpellChecker(std::string dictionaryFileName){
	this->dictFileName = dictionaryFileName;
	readDictionary();
}

/**
 * Check word for spelling and print if its wrong.
 */
void SpellChecker::Check(std::string fileName){
	std::cout << std::endl << "Mispelled words: " << std::endl;
	std::ifstream file;
	std::string fileWord;
	try {
		file.open(fileName);
		if (file.is_open()){
			// we read each word and iterate through the characters to remove
			// characters which aren't letters and convert them to lowercase
			// if the words length is longer than 0 and is spelled wrong,
			// print to the console
			while (file >> fileWord){
				std::string word;
				for (auto i : fileWord)
					if (std::isalpha(i) && !isspace(i)) word += tolower(i);
				if (word.length() > 0 && !checkSpelling(word)) std::cout << word << std::endl;
			}
			file.close();
		}
	} catch (std::exception e) {
		std::cout << e.what() << std::endl;
	}
}

/**
 * Prints tree out to prove it's balanced
 */
void SpellChecker::printTree() {
	dict.print(root);
}
