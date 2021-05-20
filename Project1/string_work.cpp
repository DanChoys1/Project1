#include <iostream>
#include <string>
#include "input.h"
#include "save_data.h"
#include "encode_string.h"

using namespace std;

unique_ptr<Input> ChoiceInputType(void);
int GetInt(void);

void StringInterface(void) {
	unique_ptr<Input> inp = ChoiceInputType();
	WordClass* wordClass = inp->Read();

	cout << endl << "Слова:" << endl;
	wordClass->printWordStruct();

	cout << endl << endl << "Слова по кол-ву:" << endl;
	wordClass->printWordsByNumber();
	
	cout << endl << endl << "Слова по алфавиту:" << endl;
	wordClass->printWordsAlphabetically();

	int numberSafe = 0;

	do {
		cout << endl << "Количество сохраняемых слов: ";
		cin >> numberSafe;

		if (numberSafe <= 0) {
			cout << "Не будь дураком!" << endl;
		}

	} while (numberSafe <= 0);

	
	SaveInputString(wordClass);
	//для создания ветви//
	cout << endl << "Сохранение данных по кол-ву." << endl;
	SaveChangeString(wordClass, numberSafe);
}
