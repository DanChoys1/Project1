#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include "open_file.h"
#include "input.h"
#include "encode_string.h"

using namespace std;

enum ChoiceTypeInput {
	CHOICE_KEYBOARD = 1,
	CHOICE_FILE
};

enum Opening {
	FAILED,
	COMPLITE
};

int GetInt(void);
void StringInputMenu(void);

bool EnglishSymbols (string line) {

	for (int i = 0; i < line.length(); i++) {
		
		if ((static_cast<int>(line[i]) < 32) || (static_cast<int>(line[i]) > 127)) {
			return false;
		}

	}

	return true;
 }

WordClass* KeyboardInput::Read() {
	cout << "������� ����������� (����� ���������� ���� ������� 'Q')" << endl;
	string line = "";
	int i = 1;
	WordClass *wordClass = new WordClass();

	do {
		line = "";
		cout << i++ << ")";
		getline(cin, line);
		
		if (!EnglishSymbols(line)) {
			cout << endl << "�������, ������������ � ������, �� ��������������" << endl
				<< "������� ������ ������:" << endl;

			i--;
			continue;
		}

		if (line != "Q") {
			*wordClass += line;
		}

	} while (line != "Q");

	return wordClass;
}

bool KeyboardInput::IsFileInput(void) {
	return false;
}

WordClass* FileInput::Read() {
	ifstream file;
	string input_string = "";
	bool correctness_string = 0;
	WordClass *wordClass = new WordClass();

	do {
		cout << endl << "���� �����������." << endl;
		file = OpenFileInput();

		string line;

		while (!file.eof()) {
			getline(file, line);
			*wordClass += line ;
		}

		/*if (!line.length()) {
			cout << "���� ������ �� ��������. ���������� ��� ���." << endl;
			continue;
		}*/

		if (!EnglishSymbols(line)) {
			cout << endl << "�������, ������������ � �����, �� ��������������" << endl;

			continue;
		}

		correctness_string = COMPLITE;

		cout << endl << "�������� �����������:" << endl << input_string;

		file.close();
	} while (correctness_string == FAILED);

	return wordClass;
}

bool FileInput::IsFileInput(void) {
	return true;
}

unique_ptr<Input> ChoiceInputType(void) {
	int choice = 0;

	do {
		StringInputMenu();
		choice = GetInt();

		if (choice == CHOICE_KEYBOARD) {

			return unique_ptr<KeyboardInput>(new KeyboardInput);

		} else if (choice == CHOICE_FILE) {

			return unique_ptr<FileInput>(new FileInput);

		} else {

			cout << "������ ������ ���" << endl;

		}

	} while ((choice != CHOICE_KEYBOARD) && (choice != CHOICE_FILE));

	string inv_arg = "Went out of the loop";
	throw inv_arg;
}
