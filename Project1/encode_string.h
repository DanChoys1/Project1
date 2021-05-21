#pragma once

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct Word {
	string normal = "";
	string reverse = "";
};

class WordClass final {
	string *_sentence = nullptr;
	int _sentenceNumber = 0;
	string *_word = nullptr;
	int _wordsNumber = 0;
	Word *_palindromeWord = nullptr;
	int _palindromeWordsNumber = 0;
	Word *_reverseWord = nullptr;
	int _reverseWordsNumber = 0;
	
public:
	void operator += (string sentence);

	template <class T>
	T *changeSizeElement(T *element, int &size);

	void addWords(void);

	bool isNewWord(string word);

	void initializWords(void);

	void initializPalindromeWord(string word, string reverseWord);

	void initializReverseWord(string word, string reverseWord);

	void printWord(void);

	void printPalindromeWord(void);

	void printReverseWord(void);

	~WordClass();
};