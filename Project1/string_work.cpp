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

	cout << endl << "�����:" << endl;
	wordClass->printWordStruct();

	cout << endl << endl << "����� �� ���-��:" << endl;
	wordClass->printWordsByNumber();
	
	cout << endl << endl << "����� �� ��������:" << endl;
	wordClass->printWordsAlphabetically();

	int numberSafe = 0;

	do {
		cout << endl << "���������� ����������� ����: ";
		cin >> numberSafe;

		if (numberSafe <= 0) {
			cout << "�� ���� �������!" << endl;
		}

	} while (numberSafe <= 0);

	
	SaveInputString(wordClass);
	//��� �������� �����//
	cout << endl << "���������� ������ �� ���-��." << endl;
	SaveChangeString(wordClass, numberSafe);
}
