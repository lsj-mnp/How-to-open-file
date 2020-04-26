#pragma once
#include <string>

class TextFile
{
public:
	TextFile();
	~TextFile();

public:
	void openAndRead(const char* fileName);

	void display() const;

private:
	std::string _data{};
};
