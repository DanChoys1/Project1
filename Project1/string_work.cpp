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
	wordClass->printWord();

	cout << endl << endl << "����� ����������:" << endl;
	wordClass->printPalindromeWord();
	
	cout << endl << endl << "������������ �����:" << endl;
	wordClass->printReverseWord();
	
	//SaveInputString(wordClass);

	//SaveChangeString(wordClass);
}
