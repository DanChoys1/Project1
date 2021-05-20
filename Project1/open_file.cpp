#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

using namespace std;

enum Opening {
	FAILED,
	COMPLITE
};

ofstream OpenFileOutput(void) {
	string path = "";
	bool file_open_complit = false;
	ofstream file;
	error_code ec;

	do {
		cout << "������� ���� � �����" << endl;
		cin.ignore();
		getline(cin, path);

		if (ifstream(path)) {

			if (!filesystem::is_regular_file(path, ec)) {
				cout << "���� ���� �� ����� ���� ������. ���������� ��� ���" << endl;
				continue;
			}

			cout << "���� ���� ����������. ������ ��� ������������?" << endl;
			string choice;

			do {
				cout << "1 - ��" << endl
					<< "2 - ���" << endl
					<< "�����: ";

				cin >> choice;

				if (choice.compare("2") && choice.compare("1")) {
					cout << "������ ������ ���." << endl
						<< "������ ������������ ����?" << endl;
				}

			} while (choice.compare("2") && choice.compare("1"));

			if (!choice.compare("2")) {
				continue;
			}

		}

		file.open(path);

		if (!filesystem::is_regular_file(path, ec)) {
			cout << "���� ���� �� ����� ���� ������." << endl;
			continue;
		}

		if (!file.is_open()) {
			cout << "���� ���� �� ����� ���� ������." << endl;
			continue;
		}

		file_open_complit = true;
	} while (!file_open_complit);

	return file;
}

ifstream OpenFileInput(void) {

	cout << "������� ���� � �����" << endl;
	string path;
	int opening_file = 0;
	error_code ec;
	ifstream file;

	do {

		do {
			getline(cin, path);

			if (!filesystem::is_regular_file(path, ec)) {
				cout << "���� ���� �� ����� ���� ������." << endl
					<< "������� ������ ���� ��� ��� �����: ";
			}

		} while (!filesystem::is_regular_file(path, ec));

		file.open(path);

		if (file.is_open()) {

			opening_file = COMPLITE;

		} else {

			cout << "���� ���� �� ����� ���� ������." << endl
				<< "������� ������ ���� ��� ��� �����: ";

			opening_file = FAILED;

		}

	} while (opening_file == FAILED);

	return file;
}
