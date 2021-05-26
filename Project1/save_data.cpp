#include <iostream>
#include <fstream>
#include <string>
#include "open_file.h"
#include "encode_string.h"

using namespace std;

void SaveInputString(WordClass* wordClass) {
	cout << endl << "Хотите сохранить введённый текст в файл?" << endl;

	string choice = "";
	
	do {
		cout << "1 - Да" << endl
			<< "2 - Нет" << endl
			<< "Выбор: ";

		cin >> choice;

		if (choice.compare("2") && choice.compare("1")) {
			cout << "Такого выбора нет." << endl
				<< "Хотите сохранить введённый текст в файл?" << endl;
		}

	} while (choice.compare("2") && choice.compare("1"));

	if (choice.compare("2")) {
		ofstream file;
		file = OpenFileOutput();

		wordClass->

		file.close();
	}

};

void SaveChangeString(WordClass* wordClass, int numberSafe) {
	/*cout << endl << "Хотите сохранить в файл преобразованную строку?" << endl;
	string choice = "";

	do {
		cout << "1 - Да" << endl
			<< "2 - Нет" << endl
			<< "Выбор: ";

		cin >> choice;

		if (choice.compare("2") && choice.compare("1")) {
			cout << "Такого выбора нет." << endl
				<< "Хотите сохранить в файл преобразованную строку?" << endl;
		}

	} while (choice.compare("2") && choice.compare("1"));

	if (choice.compare("2")) {*/
		ofstream file;
		file = OpenFileOutput();

		wordClass->safeWordsByNumberInFile(file, numberSafe);
		file << endl;
		wordClass->safeWordsAlphabeticallyInFile(file, numberSafe);

		file.close();
	//}

}