#include <iostream>
#include <fstream>
#include <string>
#include "open_file.h"
#include "encode_string.h"

using namespace std;

void SaveInputString(WordClass* wordClass, int numberSafe) {
	//cout << endl << "������ ��������� �������� ����� � ����?" << endl;

	//string choice = "";
	//
	//do {
	//	cout << "1 - ��" << endl
	//		<< "2 - ���" << endl
	//		<< "�����: ";

	//	cin >> choice;

	//	if (choice.compare("2") && choice.compare("1")) {
	//		cout << "������ ������ ���." << endl
	//			<< "������ ��������� �������� ����� � ����?" << endl;
	//	}

	//} while (choice.compare("2") && choice.compare("1"));

	//if (choice.compare("2")) {
	/*	ofstream file;
		file = OpenFileOutput();

		wordClass->safeWordStruct(file, numberSafe);

		file.close();*/
	//}

	ofstream file("Logo.txt", ios::app);

	wordClass->safeWordStruct(file);

	file.close(); 

};

void SaveChangeString(WordClass* wordClass, int numberSafe) {
	/*cout << endl << "������ ��������� � ���� ��������������� ������?" << endl;
	string choice = "";

	do {
		cout << "1 - ��" << endl
			<< "2 - ���" << endl
			<< "�����: ";

		cin >> choice;

		if (choice.compare("2") && choice.compare("1")) {
			cout << "������ ������ ���." << endl
				<< "������ ��������� � ���� ��������������� ������?" << endl;
		}

	} while (choice.compare("2") && choice.compare("1"));

	if (choice.compare("2")) {*/
		ofstream file;
		file = OpenFileOutput();

		wordClass->safeWordsByNumberInFile(file, numberSafe);
		wordClass->safeWordsAlphabeticallyInFile(file, numberSafe);

		file.close();
	//}

}