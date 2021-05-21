#include <iostream>
#include <string>
#include "encode_string.h"

using namespace std;

void WordClass::operator += (string sentence) {
	_sentenceNumber++;
	_sentence = changeSizeElement(_sentence, _sentenceNumber);
	_sentence[_sentenceNumber - 1] = sentence;

	addWords();
}

template <class T>
T* WordClass::changeSizeElement(T *element, int &size) {
	T *newElement = new T[size];

	for (int i = 0; i < size - 1; i++) {
		newElement[i] = element[i];
	}

	if (element != nullptr) {
		delete[] element;
	}

	return newElement;
};

void WordClass::addWords(void) {
	string safeWord = "";

	for (int characterNumber = 0; characterNumber < (static_cast<int>(_sentence[_sentenceNumber - 1].length()) + 1); characterNumber++) {

		if (((_sentence[_sentenceNumber - 1][characterNumber] == ' ') || 
			(characterNumber == static_cast<int>(_sentence[_sentenceNumber - 1].length()))) && (safeWord != "")) {

			if (isNewWord(safeWord) == true) {
				_wordsNumber++;

				_word = changeSizeElement(_word, _wordsNumber);
				_word[_wordsNumber - 1] = safeWord;
				initializWords();
			}

			safeWord = "";
			continue;
		}

		if (_sentence[_sentenceNumber - 1][characterNumber] != ' ') {
			safeWord += _sentence[_sentenceNumber - 1][characterNumber];
		}
	}

}

bool WordClass::isNewWord(string word) {
	for (int i = 0; i < _wordsNumber; i++) {
		if (_word[i] == word) {
			return false;
		}
	}

	return true;
}

void WordClass::initializWords(void) {
	string reversWord = "";

	for (int j = static_cast<int>(_word[_wordsNumber - 1].length()) - 1; j >= 0; j--) {
		reversWord += _word[_wordsNumber - 1][j];
	}

	if (!reversWord.compare(_word[_wordsNumber - 1])) {
		initializPalindromeWord(_word[_wordsNumber - 1], reversWord);
		return;
	}

	for (int k = 0; k < _wordsNumber - 1; k++) {
		if (!reversWord.compare(_word[k])) {
			initializReverseWord(_word[_wordsNumber - 1], reversWord);
			break;
		}
	}	
}

void WordClass::initializPalindromeWord(string word, string reverseWord) {
	_palindromeWordsNumber++;
	_palindromeWord = changeSizeElement(_palindromeWord, _palindromeWordsNumber);

	_palindromeWord[_palindromeWordsNumber - 1].normal= word;
	_palindromeWord[_palindromeWordsNumber - 1].reverse = reverseWord;
}

void WordClass::initializReverseWord(string word, string reverseWord) {
	_reverseWordsNumber++;
	_reverseWord = changeSizeElement(_reverseWord, _reverseWordsNumber);

	_reverseWord[_reverseWordsNumber - 1].normal = word;
	_reverseWord[_reverseWordsNumber - 1].reverse = reverseWord;
}

void WordClass::printWord(void) {
	for (int i = 0; i < _wordsNumber; i++) {
		cout << i + 1 << ")" << _word[i] << endl;
	}
}

void WordClass::printPalindromeWord(void) {
	for (int i = 0; i < _palindromeWordsNumber; i++) {
		cout << i + 1 << ")" << _palindromeWord[i].normal << " - " << _palindromeWord[i].reverse << endl;
	}
}

void WordClass::printReverseWord(void) {
	for (int i = 0; i < _reverseWordsNumber; i++) {
		cout << i + 1 << ")" << _reverseWord[i].normal << " - " << _reverseWord[i].reverse << endl;
	}
}

WordClass::~WordClass() {
	if (_sentence != nullptr) {
		delete[] _sentence;
		delete[] _word;
		delete[] _palindromeWord;
		delete[] _reverseWord;
	}
}
