#pragma once

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct WordStruct {
	string word = "";
	int number = 0;
};

class WordClass final {
	string *_sentence = nullptr;
	int _sentenceNumber = 0;
	WordStruct *_wordStruct = nullptr;
	WordStruct *_wordsAlphabetically = nullptr;
	WordStruct *_wordsByNumber = nullptr;
	int _wordNumber = 0;

public:
	void operator += (string sentence);

	template<class T>
	T *changeSizeElement(T *element, int &size) {
		T *newElement = new T[size];

		for (int i = 0; i < size - 1; i++) {
			newElement[i] = element[i];
		}

		if (element != nullptr) {
			delete[] element;
		}

		return newElement;
	};

	void addWords(void);

	bool isNewWord(string word);

	void initializWordsByNumber();

	void sortWordsByNumber();

	void initializWordsAlphabetically(void);

	void sortWordsAlphabetically(void);

	void printWordStruct(void);

	void printWordsByNumber(void);

	void printWordsAlphabetically(void);

	void safeWordsAlphabeticallyInFile(ofstream &file, int number);

	void safeWordsByNumberInFile(ofstream &file, int number);

	void safeWordStruct(ofstream &file, int number);

	void safeWordStruct(ofstream &file);

	~WordClass();
};