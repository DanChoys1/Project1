#pragma once

#include <string>

using namespace std;
#include "encode_string.h"

class Input {
public:

	virtual WordClass* Read() = 0;

	virtual bool IsFileInput(void) = 0;

	virtual ~Input() = default;

};

class KeyboardInput final : public Input {
public:

	WordClass* Read();
	
	bool IsFileInput(void);
};

class FileInput final : public Input {
public:

	WordClass* Read();

	bool IsFileInput(void);
};
