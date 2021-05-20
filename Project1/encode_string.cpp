#include <iostream>
#include <string>
#include "encode_string.h"

using namespace std;

void WordClass::operator += (string sentence) {
	_sentenceNumber++;
	_sentence = changeSizeElement(_sentence, _sentenceNumber);
	_sentence[_sentenceNumber - 1] = sentence;

	addWords();

	initializWordsByNumber();

	initializWordsAlphabetically();
}

void WordClass::addWords(void) {
	string safeWord = "";

	for (int characterNumber = 0; characterNumber < (static_cast<int>(_sentence[_sentenceNumber - 1].length()) + 1); characterNumber++) {

		if (((_sentence[_sentenceNumber - 1][characterNumber] == ' ') || 
			(characterNumber == static_cast<int>(_sentence[_sentenceNumber - 1].length()))) && (safeWord != "")) {

			if (isNewWord(safeWord) == true) {
				_wordNumber++;

				_wordStruct = changeSizeElement(_wordStruct, _wordNumber);
				_wordStruct[_wordNumber - 1].word = safeWord;
				_wordStruct[_wordNumber - 1].number++;
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
	for (int i = 0; i < _wordNumber; i++) {
		if (_wordStruct[i].word == word) {
			_wordStruct[i].number++;
			return false;
		}
	}

	return true;
}

void WordClass::initializWordsByNumber() {
	_wordsByNumber = new WordStruct[_wordNumber];

	for (int i = 0; i < _wordNumber; i++) {
		_wordsByNumber[i].word = _wordStruct[i].word;
		_wordsByNumber[i].number = _wordStruct[i].number;
	}

	sortWordsByNumber();
}

void WordClass::sortWordsByNumber() {
	for (int k = _wordNumber - 1; k > 0; k--) {
		int cycle_permutations = 0;

		for (int i = 0; i < k; i++) {

			if (_wordsByNumber[i].number > _wordsByNumber[i + 1].number) {
				swap(_wordsByNumber[i], _wordsByNumber[i + 1]);
				cycle_permutations++;
			}

		}

		if (cycle_permutations == 0) {
			break;
		}
	}
}

void WordClass::initializWordsAlphabetically(void) {
	_wordsAlphabetically = new WordStruct[_wordNumber];

	for (int i = 0; i < _wordNumber; i++) {
		_wordsAlphabetically[i].word = _wordStruct[i].word;
		_wordsAlphabetically[i].number = _wordStruct[i].number;
	}

	sortWordsAlphabetically();
}

void WordClass::sortWordsAlphabetically(void) {
	const int firstLetter = 0;

	for (int k = _wordNumber - 1; k > 0; k--) {
		int cycle_permutations = 0;

		for (int i = 0; i < k; i++) {

			if (_wordsAlphabetically[i].word[firstLetter] > _wordsAlphabetically[i + 1].word[firstLetter]) {
				swap(_wordsAlphabetically[i], _wordsAlphabetically[i + 1]);
				cycle_permutations++;
			}

		}

		if (cycle_permutations == 0) {
			break;
		}
	}
}

void WordClass::printWordStruct(void) {
	for (int i = 0; i < _wordNumber; i++) {
		cout << _wordStruct[i].word << " - " << _wordStruct[i].number << endl;
	}
}

void WordClass::printWordsByNumber(void) {
	for (int i = 0; i < _wordNumber; i++) {
		cout << _wordsByNumber[i].word << " - " << _wordsByNumber[i].number << endl;
	}
}

void WordClass::printWordsAlphabetically(void) {
	for (int i = 0; i < _wordNumber; i++) {
		cout << _wordsAlphabetically[i].word << " - " << _wordsAlphabetically[i].number << endl;
	}
}

void WordClass::safeWordStruct(ofstream &file, int number) {
	for (int i = 0; i < number; i++) {
		file << _wordStruct[i].word << " - " << _wordStruct[i].number << endl;
	}

	file << endl;
}

void WordClass::safeWordStruct(ofstream &file) {
	for (int i = 0; i < _wordNumber; i++) {
		file << _wordStruct[i].word << " - " << _wordStruct[i].number << endl;
	}

	file << endl;
}

void WordClass::safeWordsByNumberInFile(ofstream &file, int number) {
	for (int i = 0; i < number; i++) {
		file << _wordsByNumber[i].word << " - " << _wordsByNumber[i].number << endl;
	}

	file << endl;
	}

void WordClass::safeWordsAlphabeticallyInFile(ofstream &file, int number) {
	for (int i = 0; i < number; i++) {
		file << _wordsAlphabetically[i].word << " - " << _wordsAlphabetically[i].number << endl;
	}

	file << endl;
}

WordClass::~WordClass() {
	if (_sentence != nullptr) {
		delete[] _sentence;
		delete[] _wordStruct;
		delete[] _wordsAlphabetically;
		delete[] _wordsByNumber;
	}
}
